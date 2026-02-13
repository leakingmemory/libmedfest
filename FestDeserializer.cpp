//
// Created by sigsegv on 1/13/23.
//

#ifdef WIN32
#define FEST_SERIALIZER_USE_STD_CXX_FILEIO
#endif

#include "FestDeserializer.h"
#include "FestSerializer.h"
#include "FestVectors.h"
#include "DbVersion.h"
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#ifdef FEST_SERIALIZER_USE_STD_CXX_FILEIO
#include <fstream>
#else
#include <unistd.h>
#include <sys/mman.h>
#endif
#include <iostream>
#include <type_traits>

FestDeserializer::FestDeserializer(const std::string &filename) : mapping(nullptr), mapsize(0) {
#ifdef FEST_SERIALIZER_USE_STD_CXX_FILEIO
    std::ifstream inputFile(filename, std::ios_base::binary);
    inputFile.seekg(0, std::ios_base::end);
    mapsize = inputFile.tellg();
    inputFile.seekg(0, std::ios_base::beg);
    mapping = malloc(mapsize);
    if (mapping == nullptr) {
        std::cerr << "Error: Unable to allocate memory for reading file\n";
        inputFile.close();
        throw PackException("Allocate memory");
    }
    inputFile.read(reinterpret_cast<char*>(mapping), mapsize);
    inputFile.close();
#else
    auto fd = open(filename.c_str(), O_RDONLY);
    if (fd < 0) {
        std::cerr << "Error: Open file: " << filename << ": " << strerror(errno) << "\n";
        throw PackException("Open file");
    }
    auto size = lseek(fd, 0, SEEK_END);
    if (lseek(fd, 0, SEEK_SET) != 0) {
        std::cerr << "Error: Seek start: " << strerror(errno) << "\n";
        if (close(fd) != 0) {
            std::cerr << "Error: Close file: " << strerror(errno) << "\n";
        }
        throw PackException("Seek file");
    }
    mapsize = size;
    mapping = mmap(nullptr, size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (mapping == MAP_FAILED) {
        std::cerr << "Error: Map failed: " << strerror(errno) << "\n";
        mapping = nullptr;
        throw PackException("Map failed");
    }
    if (close(fd) != 0) {
        std::cerr << "Error: Close file: " << strerror(errno) << "\n";
    }
#endif
    Init();
}

FestDeserializer::FestDeserializer(const void *data, size_t size) {
    mapsize = size;
#ifdef FEST_SERIALIZER_USE_STD_CXX_FILEIO
    mapping = malloc(mapsize);
    if (mapping == nullptr) {
        std::cerr << "Error: Unable to allocate memory for input data\n";
        throw PackException("Allocate memory");
    }
    memcpy(mapping, data, size);
#else
    mapping = mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (mapping == MAP_FAILED) {
        std::cerr << "Error: Map failed: " << strerror(errno) << "\n";
        mapping = nullptr;
        throw PackException("Map failed");
    }
    memcpy(mapping, data, size);
    mprotect(mapping, size, PROT_READ);
#endif
    Init();
}

void FestDeserializer::Init() {
    auto *header = (FestFirstHeader *) mapping;
    FestSecondHeader *secondHeader{nullptr};
    uint32_t secondDataOffset{0};
    size_t offset = sizeof(*header);
    size_t trailerOffset{0};
    bool fullySupportedVersion{true};
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    if (offset > mapsize) {
        std::cerr << "Error: Does not contain a header\n";
        throw PackException("File size");
    }
    {
        auto version = GetDbVersion(header->magic);
        if (!version.valid) {
            std::cerr << "Error: File is not a FEST db file\n";
            throw PackException("Not a FEST file");
        }
        versionMajor = version.major;
        versionMinor = version.minor;
        versionPatch = version.patch;
        if (version.major > 1) {
            std::cerr << "Error: Major version " << version.major << " can not be read\n";
            throw PackException("Major version of file");
        }
        if ((version.major == 0 && version.minor > 4) ||
            (version.major == 1 && version.minor > 5)) {
            std::cerr << "Warning: Version " << ((int) version.major) << "." << ((int) version.minor) << " contains unsupported data (ignored)\n";
            fullySupportedVersion = false;
        }
        if (version.major > 0 || version.minor >= 1) {
            if (mapsize < sizeof(FestTrailer)) {
                throw PackException("Insufficient size (trailer)");
            }
            trailerOffset = mapsize - sizeof(FestTrailer);
            auto *trailer = (FestTrailer *) (((uint8_t *) mapping) + trailerOffset);
            if (trailer->magic != header->magic) {
                throw PackException("Trailer magic incorrect");
            }
            if (mapsize <= 0) {
                throw PackException("Second header offset overflow");
            }
            if (version.major == 0) {
                if (version.minor == 1) {
                    if ((trailer->secondHeaderOffset + sizeof(FestSecondHeaderV0_1_0)) > (mapsize - 1)) {
                        throw PackException("Second header offset overflow (V0.1.0)");
                    }
                } else if (version.minor == 2) {
                    if ((trailer->secondHeaderOffset + sizeof(FestSecondHeader_0_2_0)) > (mapsize - 1)) {
                        throw PackException("Second header offset overflow (V0.2.0)");
                    }
                } else if ((trailer->secondHeaderOffset + sizeof(FestSecondHeader)) > (mapsize - 1)) {
                    throw PackException("Second header offset overflow (V0.3.0)");
                }
            } else {
                if ((trailer->secondHeaderOffset + sizeof(FestSecondHeader)) > (mapsize - 1)) {
                    throw PackException("Second header offset overflow (V1.0.0)");
                }
            }
            secondHeader = (FestSecondHeader *) (((uint8_t *) mapping) + trailer->secondHeaderOffset);
            if (trailer->magic != secondHeader->magic) {
                throw PackException("Second header magic incorrect");
            }
            if ((trailer->secondHeaderOffset + secondHeader->secondHeaderSize) > (mapsize - 1)) {
                throw PackException("Second header offset overflow");
            }
            secondDataOffset = trailer->secondHeaderOffset;
            secondDataOffset += secondHeader->secondHeaderSize;
            {
                auto off = secondDataOffset % alignment;
                if (off != 0) {
                    off = alignment - off;
                    secondDataOffset += off;
                }
            }
        }
    }
    if (versionMajor < 2) {
        merkevare_0_0_0 = (POppfLegemiddelMerkevare_0_0_0 *) (void *) (((uint8_t *) mapping) + offset);
        numMerkevare_0_0_0 = header->numLegemiddelMerkevare;
        offset += ((size_t) numMerkevare_0_0_0) * sizeof(*merkevare_0_0_0);
        if (versionMajor == 0) {
            {
                auto off = offset % alignment;
                if (off != 0) {
                    off = alignment - off;
                    offset += off;
                }
            }
            pakning_0_0_0 = (POppfLegemiddelpakning_0_0_0 *) (void *) (((uint8_t *) mapping) + offset);
            numPakning_0_0_0 = header->numPakning;
            offset += ((size_t) numPakning_0_0_0) * sizeof(*pakning_0_0_0);
        }
        {
            auto off = offset % alignment;
            if (off != 0) {
                off = alignment - off;
                offset += off;
            }
        }
        legemiddelVirkestoff_0_0_0 = (POppfLegemiddelVirkestoff_0_0_0 *) (void *) (((uint8_t *) mapping) + offset);
        numLegemiddelVirkestoff_0_0_0 = header->numLegemiddelVirkestoff;
        offset += ((size_t) numLegemiddelVirkestoff_0_0_0) * sizeof(*legemiddelVirkestoff_0_0_0);
        {
            auto off = offset % alignment;
            if (off != 0) {
                off = alignment - off;
                offset += off;
            }
        }
    }
    medForbrMatr = (POppfMedForbrMatr *) (void *) (((uint8_t *) mapping) + offset);
    numMedForbrMatr = header->numMedForbrMatr;
    offset += ((size_t) numMedForbrMatr) * sizeof(*medForbrMatr);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    naringsmiddel = (POppfNaringsmiddel *) (void *) (((uint8_t *) mapping) + offset);
    numNaringsmiddel = header->numNaringsmiddel;
    offset += ((size_t) numNaringsmiddel) * sizeof(*naringsmiddel);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    brystprotese = (POppfBrystprotese *) (void *) (((uint8_t *) mapping) + offset);
    numBrystprotese = header->numBrystprotese;
    offset += ((size_t) numBrystprotese) * sizeof(*brystprotese);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    if (versionMajor < 2) {
        legemiddeldose_0_0_0 = (POppfLegemiddeldose_0_0_0 *) (void *) (((uint8_t *) mapping) + offset);
        numLegemiddeldose_0_0_0 = header->numLegemiddeldose;
        offset += ((size_t) numLegemiddeldose_0_0_0) * sizeof(*legemiddeldose_0_0_0);
        {
            auto off = offset % alignment;
            if (off != 0) {
                off = alignment - off;
                offset += off;
            }
        }
    }
    virkestoffMedStyrke = (POppfVirkestoffMedStyrke *) (void *) (((uint8_t *) mapping) + offset);
    numVirkestoffMedStyrke = header->numVirkestoffMedStyrke;
    offset += ((size_t) numVirkestoffMedStyrke) * sizeof(*virkestoffMedStyrke);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    if (versionMajor < 2) {
        virkestoff_0_0_0 = (POppfVirkestoff_0_0_0 *) (void *) (((uint8_t *) mapping) + offset);
        numVirkestoff_0_0_0 = header->numVirkestoff;
        offset += ((size_t) numVirkestoff_0_0_0) * sizeof(*virkestoff_0_0_0);
        if (versionMajor == 0) {
            {
                auto off = offset % alignment;
                if (off != 0) {
                    off = alignment - off;
                    offset += off;
                }
            }
            kodeverk_0_0_0 = (POppfKodeverk_0_0_0 *) (void *) (((uint8_t *) mapping) + offset);
            numKodeverk_0_0_0 = header->numKodeverk;
            offset += ((size_t) numKodeverk_0_0_0) * sizeof(*kodeverk_0_0_0);
        } else {
            kodeverk_0_0_0 = nullptr;
            numKodeverk_0_0_0 = 0;
        }
        {
            auto off = offset % alignment;
            if (off != 0) {
                off = alignment - off;
                offset += off;
            }
        }
    }
    refusjon_0_0_0 = (POppfRefusjon_0_0_0 *) (void *) (((uint8_t *) mapping) + offset);
    numRefusjon_0_0_0 = header->numRefusjon;
    offset += ((size_t) numRefusjon_0_0_0) * sizeof(*refusjon_0_0_0);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    vilkar = (POppfVilkar *) (void *) (((uint8_t *) mapping) + offset);
    numVilkar = header->numVilkar;
    offset += ((size_t) numVilkar) * sizeof(*vilkar);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    if (versionMajor < 2) {
        varselSlv_0_0_0 = (POppfVarselSlv_0_0_0 *)(void *)(((uint8_t *) mapping) + offset);
        numVarselSlv_0_0_0 = header->numVarselSlv;
        offset += ((size_t) numVarselSlv_0_0_0) * sizeof(*varselSlv_0_0_0);
        {
            auto off = offset % alignment;
            if (off != 0) {
                off = alignment - off;
                offset += off;
            }
        }
    }
    byttegruppe_0_0_0 = (POppfByttegruppe_0_0_0 *) (void *) (((uint8_t *) mapping) + offset);
    numByttegruppe = header->numByttegruppe;
    offset += ((size_t) numByttegruppe) * sizeof(*byttegruppe_0_0_0);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    interaksjon = (POppfInteraksjon *) (void *) (((uint8_t *) mapping) + offset);
    numInteraksjon = header->numInteraksjon;
    offset += ((size_t) numInteraksjon) * sizeof(*interaksjon);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    interaksjonIkkeVurdert = (POppfInteraksjonIkkeVurdert *) (void *) (((uint8_t *) mapping) + offset);
    numInteraksjonIkkeVurdert = header->numInteraksjonIkkeVurdert;
    offset += ((size_t) numInteraksjonIkkeVurdert) * sizeof(*interaksjonIkkeVurdert);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    strDosering = (POppfStrDosering *) (void *) (((uint8_t *) mapping) + offset);
    numStrDosering = header->numStrDosering;
    offset += ((size_t) numStrDosering) * sizeof(*strDosering);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    festUuid = (const FestUuid *) (void *) (((uint8_t *) mapping) + offset);
    numFestUuid = header->numUuids;
    offset += ((size_t) numFestUuid) * sizeof(*festUuid);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    if (versionMajor < 2) {
        festUuidList_0_0_0 = (const PFestId *) (void *) (((uint8_t *) mapping) + offset);
        numFestUuidList_0_0_0 = header->numUuidLists;
        offset += ((size_t) numFestUuidList_0_0_0) * sizeof(*festUuidList_0_0_0);
        {
            auto off = offset % alignment;
            if (off != 0) {
                off = alignment - off;
                offset += off;
            }
        }
    }
    valueWithCodesetList = (const PValueWithCodeset *) (void *) (((uint8_t *) mapping) + offset);
    numValueWithCodesetList = header->numValueCodeset;
    offset += ((size_t) numValueWithCodesetList) * sizeof(*valueWithCodesetList);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    reseptgyldighetList = (const PReseptgyldighet *) (void *) (((uint8_t *) mapping) + offset);
    numReseptgyldighet = header->numReseptgyldighet;
    offset += ((size_t) numReseptgyldighet) * sizeof(*reseptgyldighetList);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    pakningskomponentList = (const PPakningskomponent *) (void *) (((uint8_t *) mapping) + offset);
    numPakningskomponent = header->numPakningskomponent;
    offset += ((size_t) numPakningskomponent) * sizeof(*pakningskomponentList);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    pakningskomponentInfoList = (const PPakningskomponentInfo *) (void *) (((uint8_t *) mapping) + offset);
    numPakningskomponentInfo = header->numPakningskomponentInfo;
    offset += ((size_t) numPakningskomponentInfo) * sizeof(*pakningskomponentInfoList);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    pakningsinfoList = (const PPakningsinfo *) (void *) (((uint8_t *) mapping) + offset);
    numPakningsinfo = header->numPakningsinfo;
    offset += ((size_t) numPakningsinfo) * sizeof(*pakningsinfoList);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    prisVareList = (const PPrisVare *) (void *) (((uint8_t *) mapping) + offset);
    numPrisVare = header->numPrisVare;
    offset += ((size_t) numPrisVare) * sizeof(*prisVareList);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    refusjonList = (const PRefusjon *) (void *) (((uint8_t *) mapping) + offset);
    numRefusjonList = header->numRefusjonList;
    offset += ((size_t) numRefusjonList) * sizeof(*refusjonList);
    if (versionMajor == 0) {
        {
            auto off = offset % alignment;
            if (off != 0) {
                off = alignment - off;
                offset += off;
            }
        }
        elementList_0_0_0 = (const PElement_0_0_0 *) (void *) (((uint8_t *) mapping) + offset);
        numElement_0_0_0 = header->numElement;
        offset += ((size_t) numElement_0_0_0) * sizeof(*elementList_0_0_0);
    } else {
        elementList_0_0_0 = nullptr;
        numElement_0_0_0 = 0;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    refRefusjonsvilkarList_0_0_0 = (const PRefRefusjonsvilkar_0_0_0 *) (void *) (((uint8_t *) mapping) + offset);
    numRefRefusjonsvilkar_0_0_0 = header->numRefRefusjonsvilkar_0_0_0;
    offset += ((size_t) numRefRefusjonsvilkar_0_0_0) * sizeof(*refRefusjonsvilkarList_0_0_0);
    if (versionMajor == 0) {
        {
            auto off = offset % alignment;
            if (off != 0) {
                off = alignment - off;
                offset += off;
            }
        }
        refusjonskodeList_0_0_0 = (const PRefusjonskode_0_0_0 *) (void *) (((uint8_t *) mapping) + offset);
        numRefusjonskode_0_0_0 = header->numRefusjonskode_0_0_0;
        offset += ((size_t) numRefusjonskode_0_0_0) * sizeof(*refusjonskodeList_0_0_0);
    } else {
        refusjonskodeList_0_0_0 = nullptr;
        numRefusjonskode_0_0_0 = 0;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    referanseList = (const PReferanse *) (void *) (((uint8_t *) mapping) + offset);
    numReferanseList = header->numReferanseList;
    offset += ((size_t) numReferanseList) * sizeof(*referanseList);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    substansgruppeList = (const PSubstansgruppe *) (void *) (((uint8_t *) mapping) + offset);
    numSubstansgruppeList = header->numSubstansgruppeList;
    offset += ((size_t) numSubstansgruppeList) * sizeof(*substansgruppeList);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    substansList = (const PSubstans *) (void *) (((uint8_t *) mapping) + offset);
    numSubstansList = header->numSubstansList;
    offset += ((size_t) numSubstansList) * sizeof(*substansList);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    doseFastTidspunktList = (const PDoseFastTidspunkt *) (void *) (((uint8_t *) mapping) + offset);
    numDoseFastTidspunktList = header->numDoseFastTidspunktList;
    offset += ((size_t) numDoseFastTidspunktList) * sizeof(*doseFastTidspunktList);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    doseringList = (const PDosering *) (void *) (((uint8_t *) mapping) + offset);
    numDoseringList = header->numDoseringList;
    offset += ((size_t) numDoseringList) * sizeof(*doseringList);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    legemiddelforbrukList = (const PLegemiddelforbruk *) (void *) (((uint8_t *) mapping) + offset);
    numLegemiddelforbrukList = header->numLegemiddelforbrukList;
    offset += ((size_t) numLegemiddelforbrukList) * sizeof(*legemiddelforbrukList);
    if (versionMajor == 0) {
        {
            auto off = offset % alignment;
            if (off != 0) {
                off = alignment - off;
                offset += off;
            }
        }
        uint16List_V_0_0_0 = (const uint16_t *) (void *) (((uint8_t *) mapping) + offset);
        numUint16List_V_0_0_0 = header->numUint16List;
        offset += ((size_t) numUint16List_V_0_0_0) * sizeof(*uint16List_V_0_0_0);
        {
            auto off = offset % alignment;
            if (off != 0) {
                off = alignment - off;
                offset += off;
            }
        }
        fests_V_0_0_0 = (const PFest_V_0_0_0 *) (void *) (((uint8_t *) mapping) + offset);
        numFests_V_0_0_0 = header->numFests;
        offset += ((size_t) numFests_V_0_0_0) * sizeof(*fests_V_0_0_0);
    } else {
        numUint16List_V_0_0_0 = 0;
        numFests_V_0_0_0 = 0;
        uint16List_V_0_0_0 = nullptr;
        fests_V_0_0_0 = nullptr;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    stringList = (const PString *) (void *) (((uint8_t *) mapping) + offset);
    numStringList = header->numStringList;
    offset += ((size_t) numStringList) * sizeof(*stringList);
    stringblock = (const char *) (void *) (((uint8_t *) mapping) + offset);
    if (offset < mapsize) {
        stringblocksize = mapsize - offset;
    } else {
        stringblocksize = 0;
        if (offset > mapsize) {
            std::cerr << "Error: File is truncated\n";
            throw PackException("Truncated file");
        }
    }
    if (secondHeader != nullptr) {
        if (stringblocksize < secondHeader->stringblockSize) {
            throw PackException("Stringblock overflow");
        }
        stringblocksize = secondHeader->stringblockSize;
        offset = secondDataOffset;
        refusjonskodeList_0_1_0 = (const PRefusjonskode_0_1_0 *) (void *) (((uint8_t *) mapping) + offset);
        numRefusjonskode_0_1_0 = secondHeader->numRefusjonskode_0_1_0;
        offset += ((size_t) numRefusjonskode_0_1_0) * sizeof(*refusjonskodeList_0_1_0);
        if (offset > mapsize) {
            throw PackException("Refusjonskode list overflow (v0.1.0)");
        }
        if (versionMajor > 0 || versionMinor > 1) {
            {
                auto off = offset % alignment;
                if (off != 0) {
                    off = alignment - off;
                    offset += off;
                }
            }
            uint16List = (const uint16_t *) (void *) (((uint8_t *) mapping) + offset);
            numUint16List = secondHeader->numUint16NewList;
            offset += ((size_t) numUint16List) * sizeof(*uint16List);
            if (versionMajor == 0) {
                {
                    auto off = offset % alignment;
                    if (off != 0) {
                        off = alignment - off;
                        offset += off;
                    }
                }
                fests_V_0_2_0 = (const PFest_V_0_2_0 *) (void *) (((uint8_t *) mapping) + offset);
                numFests_V_0_2_0 = secondHeader->numFests;
                offset += sizeof(*fests_V_0_2_0) * ((size_t) numFests_V_0_2_0);
                if (offset > mapsize) {
                    throw PackException("Fest list overflow (v0.2.0)");
                }
            } else {
                fests_V_0_2_0 = nullptr;
                numFests_V_0_2_0 = 0;
            }
        } else {
            uint16List = nullptr;
            numUint16List = 0;
            fests_V_0_2_0 = nullptr;
            numFests_V_0_2_0 = 0;
        }
        if (versionMajor > 0 || versionMinor > 2) {
            {
                auto off = offset % alignment;
                if (off != 0) {
                    off = alignment - off;
                    offset += off;
                }
            }
            elementList_0_3_0 = (const PElement_0_3_0 *) (void *) (((uint8_t *) mapping) + offset);
            numElement_0_3_0 = secondHeader->numElementList;
            offset += ((size_t) numElement_0_3_0) * sizeof(*elementList_0_3_0);
            {
                auto off = offset % alignment;
                if (off != 0) {
                    off = alignment - off;
                    offset += off;
                }
            }
            termList = (const PTerm *) (void *) (((uint8_t *) mapping) + offset);
            numTerm = secondHeader->numTermList;
            offset += ((size_t) numTerm) * sizeof(*termList);
            {
                auto off = offset % alignment;
                if (off != 0) {
                    off = alignment - off;
                    offset += off;
                }
            }
            kodeverk_0_3_0 = (const POppfKodeverk_0_3_0 *) (void *) (((uint8_t *) mapping) + offset);
            numKodeverk_0_3_0 = secondHeader->numKodeverk;
            offset += ((size_t) numKodeverk_0_3_0) * sizeof(*kodeverk_0_3_0);
            {
                auto off = offset % alignment;
                if (off != 0) {
                    off = alignment - off;
                    offset += off;
                }
            }
            pakning_0_0_0 = (const POppfLegemiddelpakning_0_0_0 *) (void *) (((uint8_t *) mapping) + offset);
            numPakning_0_0_0 = secondHeader->numPakning_0_3_0;
            offset += ((size_t) numPakning_0_0_0) * sizeof(*pakning_0_0_0);
            {
                auto off = offset % alignment;
                if (off != 0) {
                    off = alignment - off;
                    offset += off;
                }
            }
            fests_V_0_3_0 = (const PFest_V_0_3_0 *) (void *) (((uint8_t *) mapping) + offset);
            numFests_V_0_3_0 = secondHeader->numFests;
            offset += sizeof(*fests_V_0_3_0) * ((size_t)numFests_V_0_3_0);
            {
                auto off = offset % alignment;
                if (off != 0) {
                    off = alignment - off;
                    offset += off;
                }
            }
            uint32List = (const uint32_t *) (void *) (((uint8_t *) mapping) + offset);
            numUint32List = secondHeader->numUint32List;
            offset += ((size_t) numUint32List) * sizeof(*uint32List);
            if (offset > mapsize) {
                throw PackException("Uint32 list overflow (v0.3.0)");
            }
        } else {
            elementList_0_3_0 = nullptr;
            numElement_0_3_0 = 0;
            termList = nullptr;
            numTerm = 0;
            kodeverk_0_3_0 = nullptr;
            numKodeverk_0_3_0 = 0;
            fests_V_0_3_0 = nullptr;
            numFests_V_0_3_0 = 0;
            uint32List = nullptr;
            numUint32List = 0;
        }
        if (versionMajor > 1 || (versionMajor == 1 && versionMinor > 0) || (versionMajor == 0 && versionMinor > 3)) {
            {
                auto off = offset % alignment;
                if (off != 0) {
                    off = alignment - off;
                    offset += off;
                }
            }
            festUuidList_0_4_0 = (const PFestId *) (void *) (((uint8_t *) mapping) + offset);
            numFestUuidList_0_4_0 = secondHeader->numFestUuidList;
            offset += ((size_t) numFestUuidList_0_4_0) * sizeof(*festUuidList_0_4_0);
            {
                auto off = offset % alignment;
                if (off != 0) {
                    off = alignment - off;
                    offset += off;
                }
            }
            merkevare_0_4_0 = (const POppfLegemiddelMerkevare_0_4_0 *) (void *) (((uint8_t *) mapping) + offset);
            numMerkevare_0_4_0 = secondHeader->numMerkevare;
            offset += ((size_t) numMerkevare_0_4_0) * sizeof(*merkevare_0_4_0);
            {
                auto off = offset % alignment;
                if (off != 0) {
                    off = alignment - off;
                    offset += off;
                }
            }
            legemiddelVirkestoff_0_4_0 = (const POppfLegemiddelVirkestoff_0_4_0 *) (void *) (((uint8_t *) mapping) + offset);
            numLegemiddelVirkestoff_0_4_0 = secondHeader->numLegemiddelVirkestoff;
            offset += ((size_t) numLegemiddelVirkestoff_0_4_0) * sizeof(*legemiddelVirkestoff_0_4_0);
            {
                auto off = offset % alignment;
                if (off != 0) {
                    off = alignment - off;
                    offset += off;
                }
            }
            pakning_0_4_0 = (const POppfLegemiddelpakning_0_4_0 *) (void *) (((uint8_t *) mapping) + offset);
            numPakning_0_4_0 = secondHeader->numPakning_0_4_0;
            offset += ((size_t) numPakning_0_4_0) * sizeof(*pakning_0_4_0);
            {
                auto off = offset % alignment;
                if (off != 0) {
                    off = alignment - off;
                    offset += off;
                }
            }
            legemiddeldose_0_4_0 = (const POppfLegemiddeldose_0_4_0 *) (void *) (((uint8_t *) mapping) + offset);
            numLegemiddeldose_0_4_0 = secondHeader->numLegemiddeldose;
            offset += ((size_t) numLegemiddeldose_0_4_0) * sizeof(*legemiddeldose_0_4_0);
            {
                auto off = offset % alignment;
                if (off != 0) {
                    off = alignment - off;
                    offset += off;
                }
            }
            virkestoff_0_4_0 = (const POppfVirkestoff_0_4_0 *) (void *) (((uint8_t *) mapping) + offset);
            numVirkestoff_0_4_0 = secondHeader->numVirkestoff;
            offset += ((size_t) numVirkestoff_0_4_0) * sizeof(*virkestoff_0_4_0);
            {
                auto off = offset % alignment;
                if (off != 0) {
                    off = alignment - off;
                    offset += off;
                }
            }
            varselSlv_0_4_0 = (const POppfVarselSlv_0_4_0 *) (void *) (((uint8_t *) mapping) + offset);
            numVarselSlv_0_4_0 = secondHeader->numVarselSlv;
            offset += ((size_t) numVarselSlv_0_4_0) * sizeof(*varselSlv_0_4_0);
            {
                auto off = offset % alignment;
                if (off != 0) {
                    off = alignment - off;
                    offset += off;
                }
            }
            fests_V_0_4_0 = (const PFest_V_0_4_0 *) (void *) (((uint8_t *) mapping) + offset);
            numFests_V_0_4_0 = secondHeader->numFests;
            offset += sizeof(*fests_V_0_4_0) * ((size_t)numFests_V_0_4_0);
            {
                auto off = offset % alignment;
                if (off != 0) {
                    off = alignment - off;
                    offset += off;
                }
            }
            if (versionMajor > 1 || (versionMajor == 1 && versionMinor > 1)) {
                refRefusjonsvilkarList_1_2_0 = (const PRefRefusjonsvilkar_1_2_0 *) (void *) (((uint8_t *) mapping) + offset);
                numRefRefusjonsvilkar_1_2_0 = secondHeader->numRefRefusjonsvilkar_1_2_0;
                offset += ((size_t) numRefRefusjonsvilkar_1_2_0) * sizeof(*refRefusjonsvilkarList_1_2_0);
                if (offset > mapsize) {
                    throw PackException("RefRefusjonsvilkar list overflow (v1.2.0)");
                }
                {
                    auto off = offset % alignment;
                    if (off != 0) {
                        off = alignment - off;
                        offset += off;
                    }
                }
                refusjonskodeList_1_2_0 = (const PRefusjonskode_1_2_0 *) (void *) (((uint8_t *) mapping) + offset);
                numRefusjonskode_1_2_0 = secondHeader->numRefusjonskode_1_2_0;
                offset += ((size_t) numRefusjonskode_1_2_0) * sizeof(*refusjonskodeList_1_2_0);
                if (offset > mapsize) {
                    throw PackException("Refusjonskode list overflow (v1.2.0)");
                }
                {
                    auto off = offset % alignment;
                    if (off != 0) {
                        off = alignment - off;
                        offset += off;
                    }
                }
                if (versionMajor > 1 || (versionMajor == 1 && versionMinor > 2)) {
                    fests_V_1_3_0 = (const PFest_V_1_3_0 *) (void *) (((uint8_t *) mapping) + offset);
                    numFests_V_1_3_0 = secondHeader->numFests;
                    offset += sizeof(*fests_V_1_3_0) * ((size_t)numFests_V_1_3_0);
                    {
                        auto off = offset % alignment;
                        if (off != 0) {
                            off = alignment - off;
                            offset += off;
                        }
                    }
                    pakning_1_3_0 = (const POppfLegemiddelpakning_1_3_0 *) (void *) (((uint8_t *) mapping) + offset);
                    numPakning_1_3_0 = secondHeader->numPakning_1_3_0;
                    offset += ((size_t) numPakning_1_3_0) * sizeof(*pakning_1_3_0);
                    {
                        auto off = offset % alignment;
                        if (off != 0) {
                            off = alignment - off;
                            offset += off;
                        }
                    }
                }
                if (versionMajor > 1 || (versionMajor == 1 && versionMinor > 3)) {
                    refusjon_1_4_0 = (const POppfRefusjon_1_4_0 *) (void *) (((uint8_t *) mapping) + offset);
                    numRefusjon_1_4_0 = secondHeader->numRefusjon_1_4_0;
                    offset += ((size_t) numRefusjon_1_4_0) * sizeof(*refusjon_1_4_0);
                    {
                        auto off = offset % alignment;
                        if (off != 0) {
                            off = alignment - off;
                            offset += off;
                        }
                    }
                    refusjonsgruppeList = (const PRefusjonsgruppe *) (void *) (((uint8_t *) mapping) + offset);
                    numRefusjonsgruppeList = secondHeader->numRefusjonsgruppeList;
                    offset += ((size_t) numRefusjonsgruppeList) * sizeof(*refusjonsgruppeList);
                    {
                        auto off = offset % alignment;
                        if (off != 0) {
                            off = alignment - off;
                            offset += off;
                        }
                    }
                    if (versionMajor > 1 || (versionMajor == 1 && versionMinor > 4)) {
                        byttegruppe_1_5_0 = (const POppfByttegruppe_1_5_0 *) (void *) (((uint8_t *) mapping) + offset);
                        offset += ((size_t) numByttegruppe) * sizeof(*byttegruppe_1_5_0);
                        {
                            auto off = offset % alignment;
                            if (off != 0) {
                                off = alignment - off;
                                offset += off;
                            }
                        }
                    } else {
                        byttegruppe_1_5_0 = nullptr;
                    }
                } else {
                    byttegruppe_1_5_0 = nullptr;
                    refusjon_1_4_0 = nullptr;
                    numRefusjon_1_4_0 = 0;
                    refusjonsgruppeList = nullptr;
                    numRefusjonsgruppeList = 0;
                }
            } else {
                byttegruppe_1_5_0 = nullptr;
                refusjon_1_4_0 = nullptr;
                numRefusjon_1_4_0 = 0;
                refusjonsgruppeList = nullptr;
                numRefusjonsgruppeList = 0;
                refusjonskodeList_1_2_0 = nullptr;
                numRefusjonskode_1_2_0 = 0;
            }
            if (fullySupportedVersion && offset != trailerOffset) {
                std::cerr << "Final offset of " << offset << " does not match trailer offset of " << trailerOffset << "\n";
                throw PackException("Size of data was not what was expected for this version");
            }
        } else {
            byttegruppe_1_5_0 = nullptr;
            refusjon_1_4_0 = nullptr;
            numRefusjon_1_4_0 = 0;
            refusjonsgruppeList = nullptr;
            numRefusjonsgruppeList = 0;
            merkevare_0_4_0 = nullptr;
            numMerkevare_0_4_0 = 0;
            legemiddelVirkestoff_0_4_0 = nullptr;
            numLegemiddelVirkestoff_0_4_0 = 0;
            pakning_0_4_0 = nullptr;
            numPakning_0_4_0 = 0;
            legemiddeldose_0_4_0 = nullptr;
            numLegemiddeldose_0_4_0 = 0;
            varselSlv_0_4_0 = nullptr;
            numVarselSlv_0_4_0 = 0;
            numFests_V_0_4_0 = 0;
        }
    } else {
        byttegruppe_1_5_0 = nullptr;
        refusjon_1_4_0 = nullptr;
        numRefusjon_1_4_0 = 0;
        refusjonsgruppeList = nullptr;
        numRefusjonsgruppeList = 0;
        refusjonskodeList_0_1_0 = nullptr;
        numRefusjonskode_0_1_0 = 0;
        uint16List = nullptr;
        numUint16List = 0;
        fests_V_0_2_0 = nullptr;
        numFests_V_0_2_0 = 0;
        elementList_0_3_0 = nullptr;
        numElement_0_3_0 = 0;
        termList = nullptr;
        numTerm = 0;
        kodeverk_0_3_0 = nullptr;
        numKodeverk_0_3_0 = 0;
        fests_V_0_3_0 = nullptr;
        numFests_V_0_3_0 = 0;
        uint32List = nullptr;
        numUint32List = 0;
    }
}

FestDeserializer::~FestDeserializer() {
    if (mapping != nullptr) {
#ifdef FEST_SERIALIZER_USE_STD_CXX_FILEIO
        free(mapping);
#else
        munmap(mapping, mapsize);
#endif
    }
}

int FestDeserializer::GetVersionMajor() const {
    return versionMajor;
}

int FestDeserializer::GetVersionMinor() const {
    return versionMinor;
}

int FestDeserializer::GetVersionPatch() const {
    return versionPatch;
}

std::vector<POppfLegemiddelMerkevare_0_0_0> FestDeserializer::GetLegemiddelMerkevare_0_0_0() const {
    std::vector<POppfLegemiddelMerkevare_0_0_0> result{};
    ForEachMerkevare_0_0_0([&result] (const auto &oppf) {
        result.emplace_back(oppf);
    });
    return result;
}

std::vector<POppfLegemiddelMerkevare_0_4_0> FestDeserializer::GetLegemiddelMerkevare_0_4_0() const {
    std::vector<POppfLegemiddelMerkevare_0_4_0> result{};
    ForEachMerkevare_0_4_0([&result] (const auto &oppf) {
        result.emplace_back(oppf);
    });
    return result;
}

std::vector<POppfLegemiddelMerkevare> FestDeserializer::GetLegemiddelMerkevare() const {
    std::vector<POppfLegemiddelMerkevare> dst{};
    if (versionMajor > 1 || (versionMajor == 1 && versionMinor > 0) || (versionMajor == 0 && versionMinor > 3)) {
        auto src = GetLegemiddelMerkevare_0_4_0();
        for (const auto &s : src) {
            dst.emplace_back(s);
        }
    } else {
        auto src = GetLegemiddelMerkevare_0_0_0();
        for (const auto &s : src) {
            dst.emplace_back(s);
        }
    }
    return dst;
}

std::vector<POppfLegemiddelpakning_0_0_0> FestDeserializer::GetLegemiddelPakning_0_0_0() const {
    std::vector<POppfLegemiddelpakning_0_0_0> result{};
    ForEachPakning_0_0_0([&result] (const auto &oppf) {
        result.emplace_back(oppf);
    });
    return result;
}

std::vector<POppfLegemiddelpakning_0_4_0> FestDeserializer::GetLegemiddelPakning_0_4_0() const {
    std::vector<POppfLegemiddelpakning_0_4_0> result{};
    ForEachPakning_0_4_0([&result] (const auto &oppf) {
        result.emplace_back(oppf);
    });
    return result;
}

std::vector<POppfLegemiddelpakning_1_3_0> FestDeserializer::GetLegemiddelPakning_1_3_0() const {
    std::vector<POppfLegemiddelpakning_1_3_0> result{};
    ForEachPakning_1_3_0([&result] (const auto &oppf) {
        result.emplace_back(oppf);
    });
    return result;
}

std::vector<POppfLegemiddelpakning> FestDeserializer::GetLegemiddelPakning() const {
    std::vector<POppfLegemiddelpakning> dst{};
    if (versionMajor > 1 || (versionMajor == 1 && versionMinor > 2)) {
        auto src = GetLegemiddelPakning_1_3_0();
        for (const auto &s : src) {
            dst.emplace_back(s);
        }
    } else if (versionMajor > 1 || (versionMajor == 1 && versionMinor > 0) || (versionMajor == 0 && versionMinor > 3)) {
        auto src = GetLegemiddelPakning_0_4_0();
        for (const auto &s : src) {
            dst.emplace_back(s);
        }
    } else {
        auto src = GetLegemiddelPakning_0_0_0();
        for (const auto &s : src) {
            dst.emplace_back(s);
        }
    }
    return dst;
}

std::vector<POppfLegemiddelVirkestoff_0_0_0> FestDeserializer::GetLegemiddelVirkestoff_0_0_0() const {
    std::vector<POppfLegemiddelVirkestoff_0_0_0> result{};
    ForEachLegemiddelVirkestoff_0_0_0([&result] (const auto &oppf) {
        result.emplace_back(oppf);
    });
    return result;
}

std::vector<POppfLegemiddelVirkestoff_0_4_0> FestDeserializer::GetLegemiddelVirkestoff_0_4_0() const {
    std::vector<POppfLegemiddelVirkestoff_0_4_0> result{};
    ForEachLegemiddelVirkestoff_0_4_0([&result] (const auto &oppf) {
        result.emplace_back(oppf);
    });
    return result;
}

std::vector<POppfLegemiddelVirkestoff> FestDeserializer::GetLegemiddelVirkestoff() const {
    std::vector<POppfLegemiddelVirkestoff> dst{};
    if (versionMajor > 1 || (versionMajor == 1 && versionMinor > 0) || (versionMajor == 0 && versionMinor > 3)) {
        auto src = GetLegemiddelVirkestoff_0_4_0();
        for (const auto &s : src) {
            dst.emplace_back(s);
        }
    } else {
        auto src = GetLegemiddelVirkestoff_0_0_0();
        for (const auto &s : src) {
            dst.emplace_back(s);
        }
    }
    return dst;
}

std::vector<POppfMedForbrMatr> FestDeserializer::GetMedForbrMatr() const {
    std::vector<POppfMedForbrMatr> result{};
    ForEachMedForbrMatr([&result] (const auto &oppf) {
        result.emplace_back(oppf);
    });
    return result;
}

std::vector<POppfNaringsmiddel> FestDeserializer::GetNaringsmiddel() const {
    std::vector<POppfNaringsmiddel> result{};
    ForEachNaringsmiddel([&result] (const auto &oppf) {
        result.emplace_back(oppf);
    });
    return result;
}

std::vector<POppfBrystprotese> FestDeserializer::GetBrystprotese() const {
    std::vector<POppfBrystprotese> result{};
    ForEachBrystprotese([&result] (const auto &oppf) {
        result.emplace_back(oppf);
    });
    return result;
}

std::vector<POppfLegemiddeldose_0_0_0> FestDeserializer::GetLegemiddeldose_0_0_0() const {
    std::vector<POppfLegemiddeldose_0_0_0> result{};
    ForEachLegemiddeldose_0_0_0([&result] (const auto &oppf) {
        result.emplace_back(oppf);
    });
    return result;
}

std::vector<POppfLegemiddeldose_0_4_0> FestDeserializer::GetLegemiddeldose_0_4_0() const {
    std::vector<POppfLegemiddeldose_0_4_0> result{};
    ForEachLegemiddeldose_0_4_0([&result] (const auto &oppf) {
        result.emplace_back(oppf);
    });
    return result;
}

std::vector<POppfLegemiddeldose> FestDeserializer::GetLegemiddeldose() const {
    std::vector<POppfLegemiddeldose> dst{};
    if (versionMajor > 1 || (versionMajor == 1 && versionMinor > 0) || (versionMajor == 0 && versionMinor > 3)) {
        auto src = GetLegemiddeldose_0_4_0();
        for (const auto &s : src) {
            dst.emplace_back(s);
        }
    } else {
        auto src = GetLegemiddeldose_0_0_0();
        for (const auto &s : src) {
            dst.emplace_back(s);
        }
    }
    return dst;
}

std::vector<POppfVirkestoffMedStyrke> FestDeserializer::GetVirkestoffMedStyrke() const {
    std::vector<POppfVirkestoffMedStyrke> result{};
    for (std::remove_const<decltype(numVirkestoffMedStyrke)>::type i = 0; i < numVirkestoffMedStyrke; i++) {
        result.emplace_back(this->virkestoffMedStyrke[i]);
    }
    return result;
}

std::vector<POppfVirkestoff_0_0_0> FestDeserializer::GetVirkestoff_0_0_0() const {
    std::vector<POppfVirkestoff_0_0_0> result{};
    for (std::remove_const<decltype(numVirkestoff_0_0_0)>::type i = 0; i < numVirkestoff_0_0_0; i++) {
        result.emplace_back(this->virkestoff_0_0_0[i]);
    }
    return result;
}

std::vector<POppfVirkestoff_0_4_0> FestDeserializer::GetVirkestoff_0_4_0() const {
    std::vector<POppfVirkestoff_0_4_0> result{};
    for (std::remove_const<decltype(numVirkestoff_0_4_0)>::type i = 0; i < numVirkestoff_0_4_0; i++) {
        result.emplace_back(this->virkestoff_0_4_0[i]);
    }
    return result;
}

std::vector<POppfVirkestoff> FestDeserializer::GetVirkestoff() const {
    std::vector<POppfVirkestoff> dst{};
    if (versionMajor > 1 || (versionMajor == 1 && versionMinor > 0) || (versionMajor == 0 && versionMinor > 3)) {
        auto src = GetVirkestoff_0_4_0();
        for (const auto &s : src) {
            dst.emplace_back(s);
        }
    } else {
        auto src = GetVirkestoff_0_0_0();
        for (const auto &s : src) {
            dst.emplace_back(s);
        }
    }
    return dst;
}

std::vector<POppfRefusjon_0_0_0> FestDeserializer::GetOppfRefusjon_0_0_0() const {
    std::vector<POppfRefusjon_0_0_0> result{};
    for (std::remove_const<decltype(numRefusjon_0_0_0)>::type i = 0; i < numRefusjon_0_0_0; i++) {
        result.emplace_back(this->refusjon_0_0_0[i]);
    }
    return result;
}

std::vector<POppfRefusjon_1_4_0> FestDeserializer::GetOppfRefusjon_1_4_0() const {
    std::vector<POppfRefusjon_1_4_0> result{};
    for (std::remove_const<decltype(numRefusjon_1_4_0)>::type i = 0; i < numRefusjon_1_4_0; i++) {
        result.emplace_back(this->refusjon_1_4_0[i]);
    }
    return result;
}

std::vector<POppfRefusjon> FestDeserializer::GetOppfRefusjon() const {
    std::vector<POppfRefusjon> dst{};
    if (versionMajor > 1 || (versionMajor == 1 && versionMinor > 3)) {
        auto src = GetOppfRefusjon_1_4_0();
        for (const auto &s : src) {
            dst.emplace_back(s);
        }
    } else {
        auto src = GetOppfRefusjon_0_0_0();
        for (const auto &s : src) {
            dst.emplace_back(s);
        }
    }
    return dst;
}

std::vector<POppfVilkar> FestDeserializer::GetOppfVilkar() const {
    std::vector<POppfVilkar> result{};
    result.reserve(numVilkar);
    for (std::remove_const<decltype(numVilkar)>::type i = 0; i < numVilkar; i++) {
        result.emplace_back(this->vilkar[i]);
    }
    return result;
}

std::vector<POppfVarselSlv_0_4_0> FestDeserializer::GetVarselSlv_0_4_0() const {
    std::vector<POppfVarselSlv_0_4_0> result{};
    result.reserve(numVarselSlv_0_4_0);
    for (std::remove_const<decltype(numVarselSlv_0_4_0)>::type i = 0; i < numVarselSlv_0_4_0; i++) {
        result.emplace_back(this->varselSlv_0_4_0[i]);
    }
    return result;
}

std::vector<POppfVarselSlv_0_0_0> FestDeserializer::GetVarselSlv_0_0_0() const {
    std::vector<POppfVarselSlv_0_0_0> result{};
    result.reserve(numVarselSlv_0_0_0);
    for (std::remove_const<decltype(numVarselSlv_0_0_0)>::type i = 0; i < numVarselSlv_0_0_0; i++) {
        result.emplace_back(this->varselSlv_0_0_0[i]);
    }
    return result;
}

std::vector<POppfVarselSlv> FestDeserializer::GetVarselSlv() const {
    std::vector<POppfVarselSlv> dst{};
    if (versionMajor > 1 || (versionMajor == 1 && versionMinor > 0) || (versionMajor == 0 && versionMinor > 3)) {
        for (const auto &src : GetVarselSlv_0_4_0()) {
            dst.emplace_back(src);
        }
    } else {
        for (const auto &src : GetVarselSlv_0_0_0()) {
            dst.emplace_back(src);
        }
    }
    return dst;
}

std::vector<POppfKodeverk_0_0_0> FestDeserializer::GetOppfKodeverk_0_0_0() const {
    std::vector<POppfKodeverk_0_0_0> result{};
    for (std::remove_const<decltype(numKodeverk_0_0_0)>::type i = 0; i < numKodeverk_0_0_0; i++) {
        result.emplace_back(this->kodeverk_0_0_0[i]);
    }
    return result;
}

std::vector<POppfKodeverk_0_3_0> FestDeserializer::GetOppfKodeverk_0_3_0() const {
    std::vector<POppfKodeverk_0_3_0> result{};
    for (std::remove_const<decltype(numKodeverk_0_3_0)>::type i = 0; i < numKodeverk_0_3_0; i++) {
        result.emplace_back(this->kodeverk_0_3_0[i]);
    }
    return result;
}

std::vector<POppfByttegruppe_0_0_0> FestDeserializer::GetByttegruppe_0_0_0() const {
    std::vector<POppfByttegruppe_0_0_0> result{};
    result.reserve(numByttegruppe);
    for (std::remove_const<decltype(numByttegruppe)>::type i = 0; i < numByttegruppe; i++) {
        result.emplace_back(this->byttegruppe_0_0_0[i]);
    }
    return result;
}

std::vector<POppfByttegruppe_1_5_0> FestDeserializer::GetByttegruppe_1_5_0() const {
    std::vector<POppfByttegruppe_1_5_0> result{};
    result.reserve(numByttegruppe);
    for (std::remove_const<decltype(numByttegruppe)>::type i = 0; i < numByttegruppe; i++) {
        result.emplace_back(this->byttegruppe_1_5_0[i]);
    }
    return result;
}

std::vector<POppfInteraksjon> FestDeserializer::GetInteraksjon() const {
    std::vector<POppfInteraksjon> result{};
    result.reserve(numInteraksjon);
    for (std::remove_const<decltype(numInteraksjon)>::type i = 0; i < numInteraksjon; i++) {
        result.emplace_back(this->interaksjon[i]);
    }
    return result;
}

std::vector<POppfInteraksjonIkkeVurdert> FestDeserializer::GetInteraksjonIkkeVurdert() const {
    std::vector<POppfInteraksjonIkkeVurdert> result{};
    result.reserve(numInteraksjonIkkeVurdert);
    for (std::remove_const<decltype(numInteraksjonIkkeVurdert)>::type i = 0; i < numInteraksjonIkkeVurdert; i++) {
        result.emplace_back(this->interaksjonIkkeVurdert[i]);
    }
    return result;
}

std::vector<POppfStrDosering> FestDeserializer::GetStrDosering() const {
    std::vector<POppfStrDosering> result{};
    result.reserve(numStrDosering);
    for (std::remove_const<decltype(numStrDosering)>::type i = 0; i < numStrDosering; i++) {
        result.emplace_back(this->strDosering[i]);
    }
    return result;
}

std::vector<PString> FestDeserializer::GetStrings() const {
    std::vector<PString> strings{};
    size_t idx{0};
    size_t base{0};
    while (idx < stringblocksize) {
        if (stringblock[idx] == '\0') {
            strings.emplace_back(base);
            base = idx + 1;
        }
        ++idx;
    }
    if (base < stringblocksize) {
        strings.emplace_back(base);
    }
    return strings;
}

std::vector<PPrisVare> FestDeserializer::GetPrisVare() const {
    std::vector<PPrisVare> prisVare{};
    prisVare.reserve(numPrisVare);
    for (std::remove_const<decltype(numPrisVare)>::type i = 0; i < numPrisVare; i++) {
        prisVare.emplace_back(this->prisVareList[i]);
    }
    return prisVare;
}

std::vector<PPakningsinfo> FestDeserializer::GetPakningsinfo() const {
    std::vector<PPakningsinfo> pakningsinfo{};
    pakningsinfo.reserve(numPakningsinfo);
    for (std::remove_const<decltype(numPakningsinfo)>::type i = 0; i < numPakningsinfo; i++) {
        pakningsinfo.emplace_back(this->pakningsinfoList[i]);
    }
    return pakningsinfo;
}

std::vector<PPakningskomponent> FestDeserializer::GetPakningskomponent() const {
    std::vector<PPakningskomponent> pakningskomponent{};
    pakningskomponent.reserve(numPakningskomponent);
    for (std::remove_const<decltype(numPakningskomponent)>::type i = 0; i < numPakningskomponent; i++) {
        pakningskomponent.emplace_back(this->pakningskomponentList[i]);
    }
    return pakningskomponent;
}

std::vector<PPakningskomponentInfo> FestDeserializer::GetPakningskomponentInfo() const {
    std::vector<PPakningskomponentInfo> pakningskomponentInfo{};
    pakningskomponentInfo.reserve(numPakningskomponentInfo);
    for (std::remove_const<decltype(numPakningskomponentInfo)>::type i = 0; i < numPakningskomponentInfo; i++) {
        pakningskomponentInfo.emplace_back(this->pakningskomponentInfoList[i]);
    }
    return pakningskomponentInfo;
}

std::vector<PReseptgyldighet> FestDeserializer::GetReseptgyldighet() const {
    std::vector<PReseptgyldighet> reseptgyldighet{};
    reseptgyldighet.reserve(numReseptgyldighet);
    for (std::remove_const<decltype(numReseptgyldighet)>::type i = 0; i < numReseptgyldighet; i++) {
        reseptgyldighet.emplace_back(this->reseptgyldighetList[i]);
    }
    return reseptgyldighet;
}

std::vector<PValueWithCodeset> FestDeserializer::GetValueWithCodeset() const {
    std::vector<PValueWithCodeset> valueWithCodeset{};
    valueWithCodeset.reserve(numValueWithCodesetList);
    for (std::remove_const<decltype(numValueWithCodesetList)>::type i = 0; i < numValueWithCodesetList; i++) {
        valueWithCodeset.emplace_back(this->valueWithCodesetList[i]);
    }
    return valueWithCodeset;
}

std::vector<FestUuid> FestDeserializer::GetFestIds() const {
    std::vector<FestUuid> uuids{};
    uuids.reserve(numFestUuid);
    for (std::remove_const<decltype(numFestUuid)>::type i = 0; i < numFestUuid; i++) {
        uuids.emplace_back(festUuid[i]);
    }
    return uuids;
}

std::vector<PFestId> FestDeserializer::GetFestIdLists_0_0_0() const {
    std::vector<PFestId> festIds{};
    festIds.reserve(numFestUuidList_0_0_0);
    for (std::remove_const<decltype(numFestUuidList_0_0_0)>::type i = 0; i < numFestUuidList_0_0_0; i++) {
        festIds.emplace_back(this->festUuidList_0_0_0[i]);
    }
    return festIds;
}

std::vector<PFestId> FestDeserializer::GetFestIdLists_0_4_0() const {
    std::vector<PFestId> festIds{};
    festIds.reserve(numFestUuidList_0_4_0);
    for (std::remove_const<decltype(numFestUuidList_0_4_0)>::type i = 0; i < numFestUuidList_0_4_0; i++) {
        festIds.emplace_back(this->festUuidList_0_4_0[i]);
    }
    return festIds;
}

std::vector<PFestId> FestDeserializer::GetFestIdLists() const {
    if (versionMajor > 1 || (versionMajor == 1 && versionMinor > 0) || (versionMajor == 0 && versionMinor > 3)) {
        return GetFestIdLists_0_4_0();
    } else {
        return GetFestIdLists_0_0_0();
    }
}

std::vector<PRefusjon> FestDeserializer::GetRefusjon() const {
    std::vector<PRefusjon> refusjon{};
    refusjon.reserve(numRefusjonList);
    for (std::remove_const<decltype(numRefusjonList)>::type i = 0; i < numRefusjonList; i++) {
        refusjon.emplace_back(this->refusjonList[i]);
    }
    return refusjon;
}

std::vector<PElement_0_0_0> FestDeserializer::GetElement_0_0_0() const {
    std::vector<PElement_0_0_0> element{};
    element.reserve(numElement_0_0_0);
    for (std::remove_const<decltype(numElement_0_0_0)>::type i = 0; i < numElement_0_0_0; i++) {
        element.emplace_back(this->elementList_0_0_0[i]);
    }
    return element;
}

std::vector<PElement_0_3_0> FestDeserializer::GetElement_0_3_0() const {
    std::vector<PElement_0_3_0> element{};
    element.reserve(numElement_0_3_0);
    for (std::remove_const<decltype(numElement_0_3_0)>::type i = 0; i < numElement_0_3_0; i++) {
        element.emplace_back(this->elementList_0_3_0[i]);
    }
    return element;
}

std::vector<PElement> FestDeserializer::GetElement() const {
    std::vector<PElement> element{};
    if (GetVersionMajor() > 0 || GetVersionMinor() > 2) {
        auto element_0_3_0 = GetElement_0_3_0();
        element.reserve(element_0_3_0.size());
        for (const auto &e : element_0_3_0) {
            element.emplace_back(e);
        }
    } else {
        auto element_0_0_0 = GetElement_0_0_0();
        element.reserve(element_0_0_0.size());
        for (const auto &e : element_0_0_0) {
            element.emplace_back(e);
        }
    }
    return element;
}

std::vector<PRefRefusjonsvilkar_0_0_0> FestDeserializer::GetRefRefusjonsvilkar_0_0_0() const {
    std::vector<PRefRefusjonsvilkar_0_0_0> refRefusjonsvilkar{};
    refRefusjonsvilkar.reserve(numRefRefusjonsvilkar_0_0_0);
    for (std::remove_const<decltype(numRefRefusjonsvilkar_0_0_0)>::type i = 0; i < numRefRefusjonsvilkar_0_0_0; i++) {
        refRefusjonsvilkar.emplace_back(this->refRefusjonsvilkarList_0_0_0[i]);
    }
    return refRefusjonsvilkar;
}

std::vector<PRefRefusjonsvilkar_1_2_0> FestDeserializer::GetRefRefusjonsvilkar_1_2_0() const {
    std::vector<PRefRefusjonsvilkar_1_2_0> refRefusjonsvilkar{};
    refRefusjonsvilkar.reserve(numRefRefusjonsvilkar_1_2_0);
    for (std::remove_const<decltype(numRefRefusjonsvilkar_1_2_0)>::type i = 0; i < numRefRefusjonsvilkar_1_2_0; i++) {
        refRefusjonsvilkar.emplace_back(this->refRefusjonsvilkarList_1_2_0[i]);
    }
    return refRefusjonsvilkar;
}

std::vector<PRefRefusjonsvilkar> FestDeserializer::GetRefRefusjonsvilkar() const {
    std::vector<PRefRefusjonsvilkar> varList{};
    if (versionMajor > 1 || (versionMajor == 1 && versionMinor > 1)) {
        auto v1_2_0List = GetRefRefusjonsvilkar_1_2_0();
        varList.reserve(v1_2_0List.size());
        for (const auto &v : v1_2_0List) {
            varList.emplace_back(v);
        }
    } else {
        auto v0_0_0List = GetRefRefusjonsvilkar_0_0_0();
        varList.reserve(v0_0_0List.size());
        for (const auto &v : v0_0_0List) {
            varList.emplace_back(v);
        }
    }
    return varList;
}

std::vector<PRefusjonskode_0_0_0> FestDeserializer::GetRefusjonskode_0_0_0() const {
    std::vector<PRefusjonskode_0_0_0> refusjonskode{};
    refusjonskode.reserve(numRefusjonskode_0_0_0);
    for (std::remove_const<decltype(numRefusjonskode_0_0_0)>::type i = 0; i < numRefusjonskode_0_0_0; i++) {
        refusjonskode.emplace_back(this->refusjonskodeList_0_0_0[i]);
    }
    return refusjonskode;
}

std::vector<PRefusjonskode_0_1_0> FestDeserializer::GetRefusjonskode_0_1_0() const {
    std::vector<PRefusjonskode_0_1_0> refusjonskode{};
    refusjonskode.reserve(numRefusjonskode_0_1_0);
    for (std::remove_const<decltype(numRefusjonskode_0_1_0)>::type i = 0; i < numRefusjonskode_0_1_0; i++) {
        refusjonskode.emplace_back(this->refusjonskodeList_0_1_0[i]);
    }
    return refusjonskode;
}

std::vector<PRefusjonskode_1_2_0> FestDeserializer::GetRefusjonskode_1_2_0() const {
    std::vector<PRefusjonskode_1_2_0> refusjonskode{};
    refusjonskode.reserve(numRefusjonskode_1_2_0);
    for (std::remove_const<decltype(numRefusjonskode_1_2_0)>::type i = 0; i < numRefusjonskode_1_2_0; i++) {
        refusjonskode.emplace_back(this->refusjonskodeList_1_2_0[i]);
    }
    return refusjonskode;
}

std::vector<PRefusjonskode> FestDeserializer::GetRefusjonskode() const {
    std::vector<PRefusjonskode> varList{};
    if (versionMajor > 1 || (versionMajor == 1 && versionMinor > 1)) {
        auto v1_2_0List = GetRefusjonskode_1_2_0();
        varList.reserve(v1_2_0List.size());
        for (const auto &v : v1_2_0List) {
            varList.emplace_back(v);
        }
    } else if (versionMajor > 0 || versionMinor > 0) {
        auto v0_1_0List = GetRefusjonskode_0_1_0();
        varList.reserve(v0_1_0List.size());
        for (const auto &v : v0_1_0List) {
            varList.emplace_back(v);
        }
    } else {
        auto v0_0_0List = GetRefusjonskode_0_0_0();
        varList.reserve(v0_0_0List.size());
        for (const auto &v : v0_0_0List) {
            varList.emplace_back(v);
        }
    }
    return varList;
}

std::vector<PReferanse> FestDeserializer::GetReferanse() const {
    std::vector<PReferanse> referanse{};
    referanse.reserve(numReferanseList);
    for (std::remove_const<decltype(numReferanseList)>::type i = 0; i < numReferanseList; i++) {
        referanse.emplace_back(this->referanseList[i]);
    }
    return referanse;
}

std::vector<PSubstansgruppe> FestDeserializer::GetSubstansgruppe() const {
    std::vector<PSubstansgruppe> substansgruppe{};
    substansgruppe.reserve(numSubstansgruppeList);
    for (std::remove_const<decltype(numSubstansgruppeList)>::type i = 0; i < numSubstansgruppeList; i++) {
        substansgruppe.emplace_back(this->substansgruppeList[i]);
    }
    return substansgruppe;
}

std::vector<PSubstans> FestDeserializer::GetSubstans() const {
    std::vector<PSubstans> substans{};
    substans.reserve(numSubstansList);
    for (std::remove_const<decltype(numSubstansList)>::type i = 0; i < numSubstansList; i++) {
        substans.emplace_back(this->substansList[i]);
    }
    return substans;
}

std::vector<PDoseFastTidspunkt> FestDeserializer::GetDoseFastTidspunkt() const {
    std::vector<PDoseFastTidspunkt> doseFastTidspunkt{};
    doseFastTidspunkt.reserve(numDoseFastTidspunktList);
    for (std::remove_const<decltype(numDoseFastTidspunktList)>::type i = 0; i < numDoseFastTidspunktList; i++) {
        doseFastTidspunkt.emplace_back(this->doseFastTidspunktList[i]);
    }
    return doseFastTidspunkt;
}

std::vector<PDosering> FestDeserializer::GetDosering() const {
    std::vector<PDosering> dosering{};
    dosering.reserve(numDoseringList);
    for (std::remove_const<decltype(numDoseringList)>::type i = 0; i < numDoseringList; i++) {
        dosering.emplace_back(this->doseringList[0]);
    }
    return dosering;
}

std::vector<PLegemiddelforbruk> FestDeserializer::GetLegemiddelforbruk() const {
    std::vector<PLegemiddelforbruk> legemiddelforbruk{};
    legemiddelforbruk.reserve(numLegemiddelforbrukList);
    for (std::remove_const<decltype(numLegemiddelforbrukList)>::type i = 0; i < numLegemiddelforbrukList; i++) {
        legemiddelforbruk.emplace_back(this->legemiddelforbrukList[i]);
    }
    return legemiddelforbruk;
}

std::vector<PString> FestDeserializer::GetStringList() const {
    std::vector<PString> strings{};
    strings.reserve(numStringList);
    for (std::remove_const<decltype(numStringList)>::type i = 0; i < numStringList; i++) {
        strings.emplace_back(this->stringList[i]);
    }
    return strings;
}

void FestDeserializer::ForEachMerkevare_0_0_0(const std::function<void(const POppfLegemiddelMerkevare_0_0_0 &)> &func) const {
    for (std::remove_const<decltype(numMerkevare_0_0_0)>::type i = 0; i < numMerkevare_0_0_0; i++) {
        func(this->merkevare_0_0_0[i]);
    }
}

void FestDeserializer::ForEachMerkevare_0_4_0(const std::function<void(const POppfLegemiddelMerkevare_0_4_0 &)> &func) const {
    for (std::remove_const<decltype(numMerkevare_0_4_0)>::type i = 0; i < numMerkevare_0_4_0; i++) {
        func(this->merkevare_0_4_0[i]);
    }
}

void FestDeserializer::ForEachMerkevare(const std::function<void(const POppfLegemiddelMerkevare &)> &func) const {
    if (versionMajor > 1 || (versionMajor == 1 && versionMinor > 0) || (versionMajor == 0 && versionMinor > 3)) {
        ForEachMerkevare_0_4_0([&func] (const POppfLegemiddelMerkevare_0_4_0 &src) {
            POppfLegemiddelMerkevare dst{src};
            func(dst);
        });
    } else {
        ForEachMerkevare_0_0_0([&func] (const POppfLegemiddelMerkevare_0_0_0 &src) {
            POppfLegemiddelMerkevare dst{src};
            func(dst);
        });
    }
}

void FestDeserializer::ForEachPakning_0_0_0(const std::function<void(const POppfLegemiddelpakning_0_0_0 &)> &func) const {
    for (std::remove_const<decltype(numPakning_0_0_0)>::type i = 0; i < numPakning_0_0_0; i++) {
        func(this->pakning_0_0_0[i]);
    }
}

void FestDeserializer::ForEachPakning_0_4_0(const std::function<void(const POppfLegemiddelpakning_0_4_0 &)> &func) const {
    for (std::remove_const<decltype(numPakning_0_4_0)>::type i = 0; i < numPakning_0_4_0; i++) {
        func(this->pakning_0_4_0[i]);
    }
}

void FestDeserializer::ForEachPakning_1_3_0(const std::function<void(const POppfLegemiddelpakning_1_3_0 &)> &func) const {
    for (std::remove_const<decltype(numPakning_1_3_0)>::type i = 0; i < numPakning_1_3_0; i++) {
        func(this->pakning_1_3_0[i]);
    }
}

void FestDeserializer::ForEachPakning(const std::function<void(const POppfLegemiddelpakning &)> &func) const {
    if (versionMajor > 1 || (versionMajor == 1 && versionMinor > 2)) {
        ForEachPakning_1_3_0([&func] (const POppfLegemiddelpakning_1_3_0 &src) {
            POppfLegemiddelpakning dst{src};
            func(dst);
        });
    } else if (versionMajor > 1 || (versionMajor == 1 && versionMinor > 0) || (versionMajor == 0 && versionMinor > 3)) {
        ForEachPakning_0_4_0([&func] (const POppfLegemiddelpakning_0_4_0 &src) {
            POppfLegemiddelpakning dst{src};
            func(dst);
        });
    } else {
        ForEachPakning_0_0_0([&func] (const POppfLegemiddelpakning_0_0_0 &src) {
            POppfLegemiddelpakning dst{src};
            func(dst);
        });
    }
}

void FestDeserializer::ForEachLegemiddelVirkestoff_0_0_0(const std::function<void(const POppfLegemiddelVirkestoff_0_0_0 &)> &func) const {
    for (std::remove_const<decltype(numLegemiddelVirkestoff_0_0_0)>::type i = 0; i < numLegemiddelVirkestoff_0_0_0; i++) {
        func(this->legemiddelVirkestoff_0_0_0[i]);
    }
}

void FestDeserializer::ForEachLegemiddelVirkestoff_0_4_0(const std::function<void(const POppfLegemiddelVirkestoff_0_4_0 &)> &func) const {
    for (std::remove_const<decltype(numLegemiddelVirkestoff_0_4_0)>::type i = 0; i < numLegemiddelVirkestoff_0_4_0; i++) {
        func(this->legemiddelVirkestoff_0_4_0[i]);
    }
}

void FestDeserializer::ForEachLegemiddelVirkestoff(const std::function<void(const POppfLegemiddelVirkestoff &)> &func) const {
    if (versionMajor > 1 || (versionMajor == 1 && versionMinor > 0) || (versionMajor == 0 && versionMinor > 3)) {
        ForEachLegemiddelVirkestoff_0_4_0([&func] (const POppfLegemiddelVirkestoff_0_4_0 &src) {
            POppfLegemiddelVirkestoff dst{src};
            func(dst);
        });
    } else {
        ForEachLegemiddelVirkestoff_0_0_0([&func] (const POppfLegemiddelVirkestoff_0_0_0 &src) {
            POppfLegemiddelVirkestoff dst{src};
            func(dst);
        });
    }
}

void FestDeserializer::ForEachMedForbrMatr(const std::function<void(const POppfMedForbrMatr &)> &func) const {
    for (std::remove_const<decltype(numMedForbrMatr)>::type i = 0; i < numMedForbrMatr; i++) {
        func(this->medForbrMatr[i]);
    }
}

void FestDeserializer::ForEachNaringsmiddel(const std::function<void(const POppfNaringsmiddel &)> &func) const {
    for (std::remove_const<decltype(numNaringsmiddel)>::type i = 0; i < numNaringsmiddel; i++) {
        func(this->naringsmiddel[i]);
    }
}

void FestDeserializer::ForEachBrystprotese(const std::function<void(const POppfBrystprotese &)> &func) const {
    for (std::remove_const<decltype(numBrystprotese)>::type i = 0; i < numBrystprotese; i++) {
        func(this->brystprotese[i]);
    }
}

void FestDeserializer::ForEachLegemiddeldose_0_0_0(const std::function<void(const POppfLegemiddeldose_0_0_0 &)> &func) const {
    for (std::remove_const<decltype(numLegemiddeldose_0_0_0)>::type i = 0; i < numLegemiddeldose_0_0_0; i++) {
        func(this->legemiddeldose_0_0_0[i]);
    }
}

void FestDeserializer::ForEachLegemiddeldose_0_4_0(const std::function<void(const POppfLegemiddeldose_0_4_0 &)> &func) const {
    for (std::remove_const<decltype(numLegemiddeldose_0_4_0)>::type i = 0; i < numLegemiddeldose_0_4_0; i++) {
        func(this->legemiddeldose_0_4_0[i]);
    }
}

void FestDeserializer::ForEachLegemiddeldose(const std::function<void(const POppfLegemiddeldose &)> &func) const {
    if (versionMajor > 1 || (versionMajor == 1 && versionMinor > 0) || (versionMajor == 0 && versionMinor > 3)) {
        ForEachLegemiddeldose_0_4_0([&func] (const POppfLegemiddeldose_0_4_0 &src) {
            POppfLegemiddeldose dst{src};
            func(dst);
        });
    } else {
        ForEachLegemiddeldose_0_0_0([&func] (const POppfLegemiddeldose_0_0_0 &src) {
            POppfLegemiddeldose dst{src};
            func(dst);
        });
    }
}

void FestDeserializer::ForEachVirkestoffMedStyrke(const std::function<void(const POppfVirkestoffMedStyrke &)> &func) const {
    for (std::remove_const<decltype(numVirkestoffMedStyrke)>::type i = 0; i < numVirkestoffMedStyrke; i++) {
        func(this->virkestoffMedStyrke[i]);
    }
}

void FestDeserializer::ForEachVirkestoff_0_0_0(const std::function<void(const POppfVirkestoff_0_0_0 &)> &func) const {
    for (std::remove_const<decltype(numVirkestoff_0_0_0)>::type i = 0; i < numVirkestoff_0_0_0; i++) {
        func(this->virkestoff_0_0_0[i]);
    }
}

void FestDeserializer::ForEachVirkestoff_0_4_0(const std::function<void(const POppfVirkestoff_0_4_0 &)> &func) const {
    for (std::remove_const<decltype(numVirkestoff_0_4_0)>::type i = 0; i < numVirkestoff_0_4_0; i++) {
        func(this->virkestoff_0_4_0[i]);
    }
}

void FestDeserializer::ForEachVirkestoff(const std::function<void(const POppfVirkestoff &)> &func) const {
    if (versionMajor > 1 || (versionMajor == 1 && versionMinor > 0) || (versionMajor == 0 && versionMinor > 3)) {
        ForEachVirkestoff_0_4_0([&func] (const POppfVirkestoff_0_4_0 &src) {
            POppfVirkestoff dst{src};
            func(dst);
        });
    } else {
        ForEachVirkestoff_0_0_0([&func] (const POppfVirkestoff_0_0_0 &src) {
            POppfVirkestoff dst{src};
            func(dst);
        });
    }
}

void FestDeserializer::ForEachKodeverk_0_0_0(const std::function<void(const POppfKodeverk_0_0_0 &)> &func) const {
    for (std::remove_const<decltype(numKodeverk_0_0_0)>::type i = 0; i < numKodeverk_0_0_0; i++) {
        func(this->kodeverk_0_0_0[i]);
    }
}

void FestDeserializer::ForEachKodeverk_0_3_0(const std::function<void(const POppfKodeverk_0_3_0 &)> &func) const {
    for (std::remove_const<decltype(numKodeverk_0_3_0)>::type i = 0; i < numKodeverk_0_3_0; i++) {
        func(this->kodeverk_0_3_0[i]);
    }
}

void FestDeserializer::ForEachKodeverk(const std::function<void(const POppfKodeverk &)> &func) const {
    if (GetVersionMajor() > 0 || GetVersionMinor() > 2) {
        ForEachKodeverk_0_3_0([&func] (const auto &k) {
            POppfKodeverk kodeverk{k};
            func(kodeverk);
        });
    } else {
        ForEachKodeverk_0_0_0([&func] (const auto &k) {
            POppfKodeverk kodeverk{k};
            func(kodeverk);
        });
    }
}

void FestDeserializer::ForEachRefusjon_0_0_0(const std::function<void(const POppfRefusjon_0_0_0 &)> &func) const {
    for (std::remove_const<decltype(numRefusjon_0_0_0)>::type i = 0; i < numRefusjon_0_0_0; i++) {
        func(this->refusjon_0_0_0[i]);
    }
}

void FestDeserializer::ForEachRefusjon_1_4_0(const std::function<void(const POppfRefusjon_1_4_0 &)> &func) const {
    for (std::remove_const<decltype(numRefusjon_1_4_0)>::type i = 0; i < numRefusjon_1_4_0; i++) {
        func(this->refusjon_1_4_0[i]);
    }
}

void FestDeserializer::ForEachRefusjon(const std::function<void(const POppfRefusjon &)> &func) const {
    if (versionMajor > 1 || (versionMajor == 1 && versionMinor > 3)) {
        ForEachRefusjon_1_4_0([&func] (const POppfRefusjon_1_4_0 &src) {
            POppfRefusjon dst{src};
            func(dst);
        });
    } else {
        ForEachRefusjon_0_0_0([&func] (const POppfRefusjon_0_0_0 &src) {
            POppfRefusjon dst{src};
            func(dst);
        });
    }
}

void FestDeserializer::ForEachVilkar(const std::function<void(const POppfVilkar &)> &func) const {
    for (std::remove_const<decltype(numVilkar)>::type i = 0; i < numVilkar; i++) {
        func(this->vilkar[i]);
    }
}

void FestDeserializer::ForEachVarselSlv_0_0_0(const std::function<void(const POppfVarselSlv_0_0_0 &)> &func) const {
    for (std::remove_const<decltype(numVarselSlv_0_0_0)>::type i = 0; i < numVarselSlv_0_0_0; i++) {
        func(this->varselSlv_0_0_0[i]);
    }
}

void FestDeserializer::ForEachVarselSlv_0_4_0(const std::function<void(const POppfVarselSlv_0_4_0 &)> &func) const {
    for (std::remove_const<decltype(numVarselSlv_0_4_0)>::type i = 0; i < numVarselSlv_0_4_0; i++) {
        func(this->varselSlv_0_4_0[i]);
    }
}

void FestDeserializer::ForEachVarselSlv(const std::function<void(const POppfVarselSlv &)> &func) const {
    if (versionMajor > 1 || (versionMajor == 1 && versionMinor > 0) || (versionMajor == 0 && versionMinor > 3)) {
        ForEachVarselSlv_0_4_0([&func] (const auto &src) {
            POppfVarselSlv dst{src};
            func(dst);
        });
    } else {
        ForEachVarselSlv_0_0_0([&func] (const auto &src) {
            POppfVarselSlv dst{src};
            func(dst);
        });
    }
}

void FestDeserializer::ForEachByttegruppe_0_0_0(const std::function<void(const POppfByttegruppe_0_0_0 &)> &func) const {
    for (std::remove_const<decltype(numByttegruppe)>::type i = 0; i < numByttegruppe; i++) {
        func(this->byttegruppe_0_0_0[i]);
    }
}

void FestDeserializer::ForEachByttegruppe_1_5_0(const std::function<void(const POppfByttegruppe_1_5_0 &)> &func) const {
    for (std::remove_const<decltype(numByttegruppe)>::type i = 0; i < numByttegruppe; i++) {
        func(this->byttegruppe_1_5_0[i]);
    }
}

void FestDeserializer::ForEachByttegruppe(const std::function<void(const POppfByttegruppe &)> &func) const {
    if (GetVersionMajor() > 1 || (GetVersionMajor() == 1 && GetVersionMinor() > 4)) {
        ForEachByttegruppe_1_5_0([&func] (const POppfByttegruppe_1_5_0 &poppf) {
            POppfByttegruppe variant{poppf};
            func(variant);
        });
    } else {
        ForEachByttegruppe_0_0_0([&func] (const POppfByttegruppe_0_0_0 &poppf) {
            POppfByttegruppe variant{poppf};
            func(variant);
        });
    }
}

void FestDeserializer::ForEachInteraksjon(const std::function<void(const POppfInteraksjon &)> &func) const {
    for (std::remove_const<decltype(numInteraksjon)>::type i = 0; i < numInteraksjon; i++) {
        func(this->interaksjon[i]);
    }
}

void FestDeserializer::ForEachInteraksjonIkkeVurdert(const std::function<void(const POppfInteraksjonIkkeVurdert &)> &func) const {
    for (std::remove_const<decltype(numInteraksjonIkkeVurdert)>::type i = 0; i < numInteraksjonIkkeVurdert; i++) {
        func(this->interaksjonIkkeVurdert[i]);
    }
}

void FestDeserializer::ForEachStrDosering(const std::function<void(const POppfStrDosering &)> &func) const {
    for (std::remove_const<decltype(numStrDosering)>::type i = 0; i < numStrDosering; i++) {
        func(this->strDosering[i]);
    }
}

void FestDeserializer::ForEachFests_V_0_0_0(const std::function<void(const PFest_V_0_0_0 &)> &func) const {
    for (std::remove_const<decltype(numFests_V_0_0_0)>::type i = 0; i < numFests_V_0_0_0; i++) {
        func(this->fests_V_0_0_0[i]);
    }
}

void FestDeserializer::ForEachFests_V_0_2_0(const std::function<void(const PFest_V_0_2_0 &)> &func) const {
    for (std::remove_const<decltype(numFests_V_0_2_0)>::type i = 0; i < numFests_V_0_2_0; i++) {
        func(this->fests_V_0_2_0[i]);
    }
}

void FestDeserializer::ForEachFests_V_0_3_0(const std::function<void(const PFest_V_0_3_0 &)> &func) const {
    for (std::remove_const<decltype(numFests_V_0_3_0)>::type i = 0; i < numFests_V_0_3_0; i++) {
        func(this->fests_V_0_3_0[i]);
    }
}

void FestDeserializer::ForEachFests_V_0_4_0(const std::function<void(const PFest_V_0_4_0 &)> &func) const {
    for (std::remove_const<decltype(numFests_V_0_4_0)>::type i = 0; i < numFests_V_0_4_0; i++) {
        func(this->fests_V_0_4_0[i]);
    }
}

void FestDeserializer::ForEachFests_V_1_3_0(const std::function<void(const PFest_V_1_3_0 &)> &func) const {
    for (std::remove_const<decltype(numFests_V_1_3_0)>::type i = 0; i < numFests_V_1_3_0; i++) {
        func(this->fests_V_1_3_0[i]);
    }
}

void FestDeserializer::ForEachFests(const std::function<void(const PFest &)> &func) const {
    if (GetVersionMajor() > 1 || (GetVersionMajor() == 1 && GetVersionMinor() > 2)) {
        ForEachFests_V_1_3_0([func] (const PFest_V_1_3_0 &festV) {
            PFest fest{festV};
            func(fest);
        });
    } else if ((GetVersionMajor() > 0 && GetVersionMinor() > 0) || (GetVersionMajor() == 0 && GetVersionMinor() > 3)) {
        ForEachFests_V_0_4_0([func] (const PFest_V_0_4_0 &festV) {
            PFest fest{festV};
            func(fest);
        });
    } else if (GetVersionMajor() > 0 || GetVersionMinor() > 2) {
        ForEachFests_V_0_3_0([func] (const PFest_V_0_3_0 &festV) {
            PFest fest{festV};
            func(fest);
        });
    } else if (GetVersionMinor() > 1) {
        ForEachFests_V_0_2_0([func] (const PFest_V_0_2_0 &festV) {
            PFest fest{festV};
            func(fest);
        });
    } else {
        ForEachFests_V_0_0_0([func] (const PFest_V_0_0_0 &festV) {
            PFest fest{festV};
            func(fest);
        });
    }
}

FestVectors FestDeserializer::Unpack(const PFest_V_0_0_0 &pFest) const {
    return {pFest, Unpack(pFest.dato), uint16List_V_0_0_0, numUint16List_V_0_0_0};
}

FestVectors FestDeserializer::Unpack(const PFest_V_0_2_0 &pFest) const {
    return {pFest, Unpack(pFest.dato), uint16List, numUint16List};
}

FestVectors FestDeserializer::Unpack(const PFest_V_0_3_0 &pFest) const {
    return {pFest, Unpack(pFest.dato), uint16List, numUint16List, uint32List, numUint32List};
}

FestVectors FestDeserializer::Unpack(const PFest_V_0_4_0 &pFest) const {
    return {pFest, Unpack(pFest.dato), uint16List, numUint16List, uint32List, numUint32List};
}

FestVectors FestDeserializer::Unpack(const PFest_V_1_3_0 &pFest) const {
    return {pFest, Unpack(pFest.dato), uint16List, numUint16List, uint32List, numUint32List};
}

FestVectors FestDeserializer::Unpack(const PFest &fest) const {
    if (std::holds_alternative<PFest_V_1_3_0>(fest)) {
        return Unpack(std::get<PFest_V_1_3_0>(fest));
    } else if (std::holds_alternative<PFest_V_0_4_0>(fest)) {
        return Unpack(std::get<PFest_V_0_4_0>(fest));
    } else if (std::holds_alternative<PFest_V_0_3_0>(fest)) {
        return Unpack(std::get<PFest_V_0_3_0>(fest));
    } else if (std::holds_alternative<PFest_V_0_2_0>(fest)) {
        return Unpack(std::get<PFest_V_0_2_0>(fest));
    } else {
        return Unpack(std::get<PFest_V_0_0_0>(fest));
    };
}

std::string FestDeserializer::Unpack(const PString &str) const {
    return str.ToString(stringblock, stringblocksize);
}

Reseptgyldighet FestDeserializer::Unpack(const PReseptgyldighet &reseptgyldighet) const {
    Reseptgyldighet r{Unpack(reseptgyldighet.varighet), Unpack(reseptgyldighet.kjonn)};
    return r;
}

ValueWithDistinguishedName FestDeserializer::Unpack(
        const PValueWithDistinguishedName &valueWithDistinguishedName) const {
    ValueWithDistinguishedName v{
        Unpack(valueWithDistinguishedName.value), Unpack(valueWithDistinguishedName.distinguishedName)};
    return v;
}

ValueWithCodeSet FestDeserializer::Unpack(const PValueWithCodeset &valueWithCodeset) const {
    ValueWithCodeSet v{
        {Unpack(valueWithCodeset.value), Unpack(valueWithCodeset.distinguishedName)},
        Unpack(valueWithCodeset.codeSet)};
    return v;
}

ValueUnit FestDeserializer::Unpack(const PValueUnit &valueUnit) const {
    ValueUnit v{valueUnit.value, Unpack(valueUnit.unit)};
    return v;
}

FestUuid FestDeserializer::Unpack(PFestId festId) const {
    if (festId.id > 0 && festId.id <= numFestUuid) {
        return this->festUuid[festId.id - 1];
    } else {
        return {};
    }
}

OppfLegemiddelMerkevare FestDeserializer::Unpack(const POppfLegemiddelMerkevare_0_0_0 &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<PLegemiddelMerkevare_0_0_0>(poppf))};
}

OppfLegemiddelMerkevare FestDeserializer::Unpack(const POppfLegemiddelMerkevare_0_4_0 &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<PLegemiddelMerkevare_0_4_0>(poppf))};
}

OppfLegemiddelMerkevare FestDeserializer::Unpack(const POppfLegemiddelMerkevare &poppf) const {
    return {Unpack(static_cast<const POppf &>(poppf)), Unpack(static_cast<const PLegemiddelMerkevare &>(poppf))};
}

OppfLegemiddelpakning FestDeserializer::Unpack(const POppfLegemiddelpakning_0_0_0 &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<PLegemiddelpakning_0_0_0>(poppf))};
}

OppfLegemiddelpakning FestDeserializer::Unpack(const POppfLegemiddelpakning_0_4_0 &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<PLegemiddelpakning_0_4_0>(poppf))};
}

OppfLegemiddelpakning FestDeserializer::Unpack(const POppfLegemiddelpakning_1_3_0 &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<PLegemiddelpakning_1_3_0>(poppf))};
}

OppfLegemiddelpakning FestDeserializer::Unpack(const POppfLegemiddelpakning &poppf) const {
    return {Unpack(static_cast<const POppf &>(poppf)), Unpack(static_cast<const PLegemiddelpakning &>(poppf))};
}

OppfLegemiddelVirkestoff FestDeserializer::Unpack(const POppfLegemiddelVirkestoff_0_0_0 &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<const PLegemiddelVirkestoff_0_0_0>(poppf))};
}

OppfLegemiddelVirkestoff FestDeserializer::Unpack(const POppfLegemiddelVirkestoff_0_4_0 &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<const PLegemiddelVirkestoff_0_4_0>(poppf))};
}

OppfLegemiddelVirkestoff FestDeserializer::Unpack(const POppfLegemiddelVirkestoff &poppf) const {
    return {Unpack(static_cast<const POppf &>(poppf)), Unpack(static_cast<const PLegemiddelVirkestoff &>(poppf))};
}

OppfMedForbrMatr FestDeserializer::Unpack(const POppfMedForbrMatr &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<const PMedForbrMatr>(poppf))};
}

OppfNaringsmiddel FestDeserializer::Unpack(const POppfNaringsmiddel &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<const PNaringsmiddel>(poppf))};
}

OppfBrystprotese FestDeserializer::Unpack(const POppfBrystprotese &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<const PBrystprotese>(poppf))};
}

OppfLegemiddeldose FestDeserializer::Unpack(const POppfLegemiddeldose_0_0_0 &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<const PLegemiddeldose_0_0_0>(poppf))};
}

OppfLegemiddeldose FestDeserializer::Unpack(const POppfLegemiddeldose_0_4_0 &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<const PLegemiddeldose_0_4_0>(poppf))};
}

OppfLegemiddeldose FestDeserializer::Unpack(const POppfLegemiddeldose &poppf) const {
    return {Unpack(static_cast<const POppf &>(poppf)), Unpack(static_cast<const PLegemiddeldose &>(poppf))};
}

OppfVirkestoffMedStyrke FestDeserializer::Unpack(const POppfVirkestoffMedStyrke &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<const PVirkestoffMedStyrke>(poppf))};
}

OppfVirkestoff FestDeserializer::Unpack(const POppfVirkestoff_0_0_0 &poppf) const {
    return {Unpack(static_cast<const POppf &>(poppf)), Unpack(static_cast<const PVirkestoff_0_0_0 &>(poppf))};
}

OppfVirkestoff FestDeserializer::Unpack(const POppfVirkestoff_0_4_0 &poppf) const {
    return {Unpack(static_cast<const POppf &>(poppf)), Unpack(static_cast<const PVirkestoff_0_4_0 &>(poppf))};
}

OppfVirkestoff FestDeserializer::Unpack(const POppfVirkestoff &poppf) const {
    return {Unpack(static_cast<const POppf &>(poppf)), Unpack(static_cast<const PVirkestoff &>(poppf))};
}

OppfKodeverk FestDeserializer::Unpack(const POppfKodeverk_0_0_0 &poppf) const {
    std::vector<Element> element{};
    {
        auto list = GetElementList(poppf);
        for (const auto &item : list) {
            element.emplace_back(Unpack(item));
        }
    }
    return {Unpack(static_cast<POppf>(poppf)), Unpack(static_cast<PInfo>(poppf)), element};
}

OppfKodeverk FestDeserializer::Unpack(const POppfKodeverk_0_3_0 &poppf) const {
    std::vector<Element> element{};
    {
        auto list = GetElementList(poppf);
        for (const auto &item : list) {
            element.emplace_back(Unpack(item));
        }
    }
    return {Unpack(static_cast<POppf>(poppf)), Unpack(static_cast<PInfo>(poppf)), element};
}

OppfKodeverk FestDeserializer::Unpack(const POppfKodeverk &poppf) const {
    if (std::holds_alternative<POppfKodeverk_0_3_0>(poppf)) {
        return Unpack(std::get<POppfKodeverk_0_3_0>(poppf));
    } else {
        return Unpack(std::get<POppfKodeverk_0_0_0>(poppf));
    }
}

OppfRefusjon FestDeserializer::Unpack(const POppfRefusjon_0_0_0 &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<const PRefusjonshjemmel_0_0_0>(poppf))};
}

OppfRefusjon FestDeserializer::Unpack(const POppfRefusjon_1_4_0 &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<const PRefusjonshjemmel_1_4_0>(poppf))};
}

OppfRefusjon FestDeserializer::Unpack(const POppfRefusjon &poppf) const {
    const std::variant<POppfRefusjon_0_0_0,POppfRefusjon_1_4_0> &v = poppf;
    if (std::holds_alternative<POppfRefusjon_1_4_0>(v)) {
        return Unpack(std::get<POppfRefusjon_1_4_0>(v));
    } else {
        return Unpack(std::get<POppfRefusjon_0_0_0>(v));
    }
}

OppfVilkar FestDeserializer::Unpack(const POppfVilkar &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<const PVilkar>(poppf))};
}

OppfVarselSlv FestDeserializer::Unpack(const POppfVarselSlv_0_0_0 &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<const PVarselSlv_0_0_0>(poppf))};
}

OppfVarselSlv FestDeserializer::Unpack(const POppfVarselSlv_0_4_0 &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<const PVarselSlv_0_4_0>(poppf))};
}

OppfVarselSlv FestDeserializer::Unpack(const POppfVarselSlv &poppf) const {
    if (std::holds_alternative<PVarselSlv_0_4_0>(poppf)) {
        return {Unpack(static_cast<const POppf &>(poppf)), Unpack(std::get<PVarselSlv_0_4_0>(poppf))};
    } else {
        return {Unpack(static_cast<const POppf &>(poppf)), Unpack(std::get<PVarselSlv_0_0_0>(poppf))};
    }
}

OppfByttegruppe FestDeserializer::Unpack(const POppfByttegruppe_0_0_0 &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<const PByttegruppe_0_0_0>(poppf))};
}

OppfByttegruppe FestDeserializer::Unpack(const POppfByttegruppe_1_5_0 &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<const PByttegruppe_1_5_0>(poppf))};
}

OppfByttegruppe FestDeserializer::Unpack(const POppfByttegruppe &poppf) const {
    struct {
        const FestDeserializer *festDeserializer;

        Byttegruppe operator() (const PByttegruppe_0_0_0 &src) const {
            return festDeserializer->Unpack(src);
        }
        Byttegruppe operator() (const PByttegruppe_1_5_0 &src) const {
            return festDeserializer->Unpack(src);
        }
    } visitor{.festDeserializer = this};
    return {Unpack(static_cast<const POppf &>(poppf)), std::visit(visitor, poppf)};
}

OppfInteraksjon FestDeserializer::Unpack(const POppfInteraksjon &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<const PInteraksjon>(poppf))};
}

OppfInteraksjonIkkeVurdert FestDeserializer::Unpack(const POppfInteraksjonIkkeVurdert &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<const PInteraksjonIkkeVurdert>(poppf))};
}

OppfStrDosering FestDeserializer::Unpack(const POppfStrDosering &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<PKortdose>(poppf))};
}

Oppf FestDeserializer::Unpack(const POppf &poppf) const {
    Status status{Unpack(poppf.status)};
    return {Unpack(poppf.id).ToString(), Unpack(poppf.tidspunkt), status};
}

LegemiddelMerkevare FestDeserializer::Unpack(const PLegemiddelMerkevare_0_0_0 &pmerkevare) const {
    std::vector<Reseptgyldighet> reseptgyldighet{};
    {
        auto rg = Unpack(reseptgyldighetList, numReseptgyldighet, pmerkevare.reseptgyldighet);
        for (const auto &r : rg) {
            reseptgyldighet.push_back(Unpack(r));
        }
    }
    std::vector<std::string> sortertVirkestoffUtenStyrke{};
    {
        auto sv = Unpack(festUuidList_0_0_0, numFestUuidList_0_0_0, pmerkevare.sortertVirkestoffUtenStyrke);
        for (const auto &v : sv) {
            sortertVirkestoffUtenStyrke.push_back(Unpack(v).ToString());
        }
    }
    return {
        Unpack(static_cast<PLegemiddel_0_0_0>(pmerkevare)),
        {Unpack(pmerkevare.preparattype)},
        Unpack(pmerkevare.id).ToString(),
        Unpack(pmerkevare.varenavn),
        Unpack(pmerkevare.legemiddelformLang),
        Unpack(pmerkevare.produsent),
        reseptgyldighet,
        FromRaw(pmerkevare.varseltrekant),
        Unpack(pmerkevare.referanseprodukt),
        Unpack(pmerkevare.preparatomtaleavsnitt),
        {Unpack(pmerkevare.smak)},
        sortertVirkestoffUtenStyrke,
        {Unpack(pmerkevare.vaksinestandard)}
    };
}

LegemiddelMerkevare FestDeserializer::Unpack(const PLegemiddelMerkevare_0_4_0 &pmerkevare) const {
    std::vector<Reseptgyldighet> reseptgyldighet{};
    {
        auto rg = Unpack(reseptgyldighetList, numReseptgyldighet, pmerkevare.reseptgyldighet);
        for (const auto &r : rg) {
            reseptgyldighet.push_back(Unpack(r));
        }
    }
    std::vector<std::string> sortertVirkestoffUtenStyrke{};
    {
        auto sv = Unpack(festUuidList_0_4_0, numFestUuidList_0_4_0, pmerkevare.sortertVirkestoffUtenStyrke);
        for (const auto &v : sv) {
            sortertVirkestoffUtenStyrke.push_back(Unpack(v).ToString());
        }
    }
    return {
            Unpack(static_cast<PLegemiddel_0_4_0>(pmerkevare)),
            {Unpack(pmerkevare.preparattype)},
            Unpack(pmerkevare.id).ToString(),
            Unpack(pmerkevare.varenavn),
            Unpack(pmerkevare.legemiddelformLang),
            Unpack(pmerkevare.produsent),
            reseptgyldighet,
            FromRaw(pmerkevare.varseltrekant),
            Unpack(pmerkevare.referanseprodukt),
            Unpack(pmerkevare.preparatomtaleavsnitt),
            {Unpack(pmerkevare.smak)},
            sortertVirkestoffUtenStyrke,
            {Unpack(pmerkevare.vaksinestandard)}
    };
}

LegemiddelMerkevare FestDeserializer::Unpack(const PLegemiddelMerkevare &pmerkevare) const {
    const std::variant<PLegemiddelMerkevare_0_4_0,PLegemiddelMerkevare_0_0_0> &p = pmerkevare;
    if (std::holds_alternative<PLegemiddelMerkevare_0_4_0>(p)) {
        return Unpack(std::get<PLegemiddelMerkevare_0_4_0>(p));
    } else {
        return Unpack(std::get<PLegemiddelMerkevare_0_0_0>(p));
    };
}

Legemiddelpakning FestDeserializer::Unpack(const PLegemiddelpakning_0_0_0 &ppakning) const {
    std::vector<Pakningsinfo> pakningsinfo{};
    {
        auto list = Unpack(pakningsinfoList, numPakningsinfo, ppakning.pakningsinfo);
        for (const auto &ppi : list) {
            auto pi = Unpack(ppi);
            pakningsinfo.push_back(pi);
        }
    }
    std::vector<PrisVare> prisVare{};
    {
        auto list = Unpack(prisVareList, numPrisVare, ppakning.prisVare);
        for (const auto &ppv : list) {
            auto pv = Unpack(ppv);
            prisVare.push_back(pv);
        }
    }
    return {
            Unpack(static_cast<PLegemiddelCore_0_0_0>(ppakning)),
            {Unpack(ppakning.preparattype)},
            Unpack(ppakning.id).ToString(),
            Unpack(ppakning.varenr),
            {Unpack(ppakning.oppbevaring)},
            pakningsinfo,
            Unpack(ppakning.markedsforingsinfo),
            Unpack(ppakning.ean),
            prisVare,
            { Unpack(ppakning.refusjon) },
            Unpack(ppakning.pakningByttegruppe),
            Unpack(ppakning.preparatomtaleavsnitt),
            ppakning.ikkeKonservering
    };
}

Legemiddelpakning FestDeserializer::Unpack(const PLegemiddelpakning_0_4_0 &ppakning) const {
    std::vector<Pakningsinfo> pakningsinfo{};
    {
        auto list = Unpack(pakningsinfoList, numPakningsinfo, ppakning.pakningsinfo);
        for (const auto &ppi : list) {
            auto pi = Unpack(ppi);
            pakningsinfo.push_back(pi);
        }
    }
    std::vector<PrisVare> prisVare{};
    {
        auto list = Unpack(prisVareList, numPrisVare, ppakning.prisVare);
        for (const auto &ppv : list) {
            auto pv = Unpack(ppv);
            prisVare.push_back(pv);
        }
    }
    return {
            Unpack(static_cast<PLegemiddelCore_0_4_0>(ppakning)),
            {Unpack(ppakning.preparattype)},
            Unpack(ppakning.id).ToString(),
            Unpack(ppakning.varenr),
            {Unpack(ppakning.oppbevaring)},
            pakningsinfo,
            Unpack(ppakning.markedsforingsinfo),
            Unpack(ppakning.ean),
            prisVare,
            { Unpack(ppakning.refusjon) },
            Unpack(ppakning.pakningByttegruppe),
            Unpack(ppakning.preparatomtaleavsnitt),
            ppakning.ikkeKonservering
    };
}

Legemiddelpakning FestDeserializer::Unpack(const PLegemiddelpakning_1_3_0 &ppakning) const {
    std::vector<Pakningsinfo> pakningsinfo{};
    {
        auto list = Unpack(pakningsinfoList, numPakningsinfo, ppakning.pakningsinfo);
        for (const auto &ppi : list) {
            auto pi = Unpack(ppi);
            pakningsinfo.push_back(pi);
        }
    }
    std::vector<PrisVare> prisVare{};
    {
        auto list = Unpack(prisVareList, numPrisVare, ppakning.prisVare);
        for (const auto &ppv : list) {
            auto pv = Unpack(ppv);
            prisVare.push_back(pv);
        }
    }
    std::vector<Refusjon> refusjon{};
    {
        auto list = Unpack(refusjonList, numRefusjonList, ppakning.refusjon);
        for (const auto &r : list) {
            refusjon.push_back(Unpack(r));
        }
    }
    return {
            Unpack(static_cast<PLegemiddelCore_0_4_0>(ppakning)),
            {Unpack(ppakning.preparattype)},
            Unpack(ppakning.id).ToString(),
            Unpack(ppakning.varenr),
            {Unpack(ppakning.oppbevaring)},
            pakningsinfo,
            Unpack(ppakning.markedsforingsinfo),
            Unpack(ppakning.ean),
            prisVare,
            refusjon,
            Unpack(ppakning.pakningByttegruppe),
            Unpack(ppakning.preparatomtaleavsnitt),
            ppakning.ikkeKonservering
    };
}

Legemiddelpakning FestDeserializer::Unpack(const PLegemiddelpakning &pl) const {
    const std::variant<PLegemiddelpakning_0_0_0,PLegemiddelpakning_0_4_0,PLegemiddelpakning_1_3_0> &p = pl;
    if (std::holds_alternative<PLegemiddelpakning_1_3_0>(p)) {
        return Unpack(std::get<PLegemiddelpakning_1_3_0>(p));
    } else if (std::holds_alternative<PLegemiddelpakning_0_4_0>(p)) {
        return Unpack(std::get<PLegemiddelpakning_0_4_0>(p));
    } else {
        return Unpack(std::get<PLegemiddelpakning_0_0_0>(p));
    }
}

LegemiddelVirkestoff FestDeserializer::Unpack(const PLegemiddelVirkestoff_0_0_0 &pvirkestoff) const {
    std::vector<Refusjon> refusjon{};
    {
        auto list = Unpack(this->refusjonList, numRefusjonList, pvirkestoff.refusjon);
        for (const auto &item : list) {
            refusjon.emplace_back(Unpack(item));
        }
    }
    std::vector<std::string> refLegemiddelMerkevare{};
    {
        auto list = Unpack(festUuidList_0_0_0, numFestUuidList_0_0_0, pvirkestoff.refLegemiddelMerkevare);
        for (const auto &id : list) {
            refLegemiddelMerkevare.emplace_back(Unpack(id).ToString());
        }
    }
    std::vector<std::string> refPakning{};
    {
        auto list = Unpack(festUuidList_0_0_0, numFestUuidList_0_0_0, pvirkestoff.refPakning);
        for (const auto &id : list) {
            refPakning.emplace_back(Unpack(id).ToString());
        }
    }
    return {
        Unpack(static_cast<PLegemiddel_0_0_0>(pvirkestoff)),
        Unpack(pvirkestoff.id).ToString(),
        refusjon,
        refLegemiddelMerkevare,
        refPakning,
        {Unpack(pvirkestoff.forskrivningsenhetResept)}
    };
}

LegemiddelVirkestoff FestDeserializer::Unpack(const PLegemiddelVirkestoff_0_4_0 &pvirkestoff) const {
    std::vector<Refusjon> refusjon{};
    {
        auto list = Unpack(this->refusjonList, numRefusjonList, pvirkestoff.refusjon);
        for (const auto &item : list) {
            refusjon.emplace_back(Unpack(item));
        }
    }
    std::vector<std::string> refLegemiddelMerkevare{};
    {
        auto list = Unpack(festUuidList_0_4_0, numFestUuidList_0_4_0, pvirkestoff.refLegemiddelMerkevare);
        for (const auto &id : list) {
            refLegemiddelMerkevare.emplace_back(Unpack(id).ToString());
        }
    }
    std::vector<std::string> refPakning{};
    {
        auto list = Unpack(festUuidList_0_4_0, numFestUuidList_0_4_0, pvirkestoff.refPakning);
        for (const auto &id : list) {
            refPakning.emplace_back(Unpack(id).ToString());
        }
    }
    return {
            Unpack(static_cast<PLegemiddel_0_4_0>(pvirkestoff)),
            Unpack(pvirkestoff.id).ToString(),
            refusjon,
            refLegemiddelMerkevare,
            refPakning,
            {Unpack(pvirkestoff.forskrivningsenhetResept)}
    };
}

LegemiddelVirkestoff FestDeserializer::Unpack(const PLegemiddelVirkestoff &pvirkestoff) const {
    const std::variant<PLegemiddelVirkestoff_0_4_0,PLegemiddelVirkestoff_0_0_0> &p = pvirkestoff;
    if (std::holds_alternative<PLegemiddelVirkestoff_0_4_0>(p)) {
        return Unpack(std::get<PLegemiddelVirkestoff_0_4_0>(p));
    } else {
        return Unpack(std::get<PLegemiddelVirkestoff_0_0_0>(p));
    }
}

Handelsvare FestDeserializer::Unpack(const PHandelsvare &pHandelsvare) const {
    std::vector<PrisVare> prisVare{};
    {
        auto list = Unpack(prisVareList, numPrisVare, pHandelsvare.prisVare);
        for (const auto &item : list) {
            prisVare.emplace_back(Unpack(item));
        }
    }
    return {
        Unpack(pHandelsvare.nr),
        Unpack(pHandelsvare.navn),
        Unpack(pHandelsvare.produktInfoVare),
        Unpack(pHandelsvare.leverandor),
        prisVare,
        Unpack(pHandelsvare.refusjon)
    };
}

Legemiddeldose FestDeserializer::Unpack(const PLegemiddeldose_0_0_0 &pLegemiddeldose) const {
    std::vector<std::string> refLegemiddelMerkevare{};
    {
        auto list = Unpack(festUuidList_0_0_0, numFestUuidList_0_0_0, pLegemiddeldose.refLegemiddelMerkevare);
        for (const auto &pid : list) {
            refLegemiddelMerkevare.emplace_back(Unpack(pid).ToString());
        }
    }
    std::vector<std::string> refPakning{};
    {
        auto list = Unpack(festUuidList_0_0_0, numFestUuidList_0_0_0, pLegemiddeldose.refPakning);
        for (const auto &pid : list) {
            refPakning.emplace_back(Unpack(pid).ToString());
        }
    }
    std::vector<PakningskomponentInfo> pakningskomponent{};
    {
        auto list = Unpack(pakningskomponentInfoList, numPakningskomponentInfo, pLegemiddeldose.pakningskomponent);
        for (const auto &item : list) {
            pakningskomponent.emplace_back(Unpack(item));
        }
    }
    return {
        Unpack(static_cast<PLegemiddelCore_0_0_0>(pLegemiddeldose)),
        {Unpack(pLegemiddeldose.preparattype)},
        Unpack(pLegemiddeldose.id).ToString(),
        Unpack(pLegemiddeldose.lmrLopenr),
        Unpack(pLegemiddeldose.mengde),
        refLegemiddelMerkevare,
        refPakning,
        pakningskomponent,
        Unpack(pLegemiddeldose.pakningstype)
    };
}

Legemiddeldose FestDeserializer::Unpack(const PLegemiddeldose_0_4_0 &pLegemiddeldose) const {
    std::vector<std::string> refLegemiddelMerkevare{};
    {
        auto list = Unpack(festUuidList_0_4_0, numFestUuidList_0_4_0, pLegemiddeldose.refLegemiddelMerkevare);
        for (const auto &pid : list) {
            refLegemiddelMerkevare.emplace_back(Unpack(pid).ToString());
        }
    }
    std::vector<std::string> refPakning{};
    {
        auto list = Unpack(festUuidList_0_4_0, numFestUuidList_0_4_0, pLegemiddeldose.refPakning);
        for (const auto &pid : list) {
            refPakning.emplace_back(Unpack(pid).ToString());
        }
    }
    std::vector<PakningskomponentInfo> pakningskomponent{};
    {
        auto list = Unpack(pakningskomponentInfoList, numPakningskomponentInfo, pLegemiddeldose.pakningskomponent);
        for (const auto &item : list) {
            pakningskomponent.emplace_back(Unpack(item));
        }
    }
    return {
            Unpack(static_cast<PLegemiddelCore_0_4_0>(pLegemiddeldose)),
            {Unpack(pLegemiddeldose.preparattype)},
            Unpack(pLegemiddeldose.id).ToString(),
            Unpack(pLegemiddeldose.lmrLopenr),
            Unpack(pLegemiddeldose.mengde),
            refLegemiddelMerkevare,
            refPakning,
            pakningskomponent,
            Unpack(pLegemiddeldose.pakningstype)
    };
}

Legemiddeldose FestDeserializer::Unpack(const PLegemiddeldose &pLegemiddeldose) const {
    const std::variant<PLegemiddeldose_0_0_0,PLegemiddeldose_0_4_0> &p = pLegemiddeldose;
    if (std::holds_alternative<PLegemiddeldose_0_4_0>(p)) {
        return Unpack(std::get<PLegemiddeldose_0_4_0>(p));
    } else {
        return Unpack(std::get<PLegemiddeldose_0_0_0>(p));
    }
}

VirkestoffMedStyrke FestDeserializer::Unpack(const PVirkestoffMedStyrke &pVirkestoffMedStyrke) const {
    return {
        Unpack(pVirkestoffMedStyrke.id).ToString(),
        Unpack(pVirkestoffMedStyrke.refVirkestoff).ToString(),
        {Unpack(pVirkestoffMedStyrke.styrke)},
        {Unpack(pVirkestoffMedStyrke.styrkenevner)},
        {Unpack(pVirkestoffMedStyrke.styrkeoperator)},
        {Unpack(pVirkestoffMedStyrke.alternativStyrke)},
        {Unpack(pVirkestoffMedStyrke.alternativStyrkenevner)},
        {Unpack(pVirkestoffMedStyrke.atcKombipreparat)},
        pVirkestoffMedStyrke.styrkeOvreVerdi
    };
}

Virkestoff FestDeserializer::Unpack(const PVirkestoff_0_0_0 &pVirkestoff) const {
    std::vector<std::string> refVirkestoff{};
    {
        auto list = Unpack(festUuidList_0_0_0, numFestUuidList_0_0_0, pVirkestoff.refVirkestoff);
        for (const auto &id : list) {
            refVirkestoff.emplace_back(Unpack(id).ToString());
        }
    }
    return {
        Unpack(pVirkestoff.id).ToString(),
        Unpack(pVirkestoff.navn),
        Unpack(pVirkestoff.navnEngelsk),
        refVirkestoff
    };
}

Virkestoff FestDeserializer::Unpack(const PVirkestoff_0_4_0 &pVirkestoff) const {
    std::vector<std::string> refVirkestoff{};
    {
        auto list = Unpack(festUuidList_0_4_0, numFestUuidList_0_4_0, pVirkestoff.refVirkestoff);
        for (const auto &id : list) {
            refVirkestoff.emplace_back(Unpack(id).ToString());
        }
    }
    return {
            Unpack(pVirkestoff.id).ToString(),
            Unpack(pVirkestoff.navn),
            Unpack(pVirkestoff.navnEngelsk),
            refVirkestoff
    };
}

Virkestoff FestDeserializer::Unpack(const PVirkestoff &pVirkestoff) const {
    if (std::holds_alternative<PVirkestoff_0_4_0>(pVirkestoff)) {
        return Unpack(std::get<PVirkestoff_0_4_0>(pVirkestoff));
    } else {
        return Unpack(std::get<PVirkestoff_0_0_0>(pVirkestoff));
    }
}

Info FestDeserializer::Unpack(const PInfo &pInfo) const {
    return {
        Unpack(pInfo.id),
        Unpack(pInfo.betegnelse),
        Unpack(pInfo.kortnavn),
        Unpack(pInfo.ansvarligUtgiver)
    };
}

Refusjonshjemmel FestDeserializer::Unpack(const PRefusjonshjemmel_0_0_0 &pRefusjonshjemmel) const {
    return {
        Unpack(pRefusjonshjemmel.refusjonshjemmel),
        pRefusjonshjemmel.kreverVarekobling,
        pRefusjonshjemmel.kreverVedtak,
        { Unpack(static_cast<const PRefusjonsgruppe &>(pRefusjonshjemmel)) }
    };
}

Refusjonshjemmel FestDeserializer::Unpack(const PRefusjonshjemmel_1_4_0 &pRefusjonshjemmel) const {
    std::vector<Refusjonsgruppe> refusjonsgruppe{};
    {
        auto list = Unpack(refusjonsgruppeList, numRefusjonsgruppeList, pRefusjonshjemmel.refusjonsgruppe);
        for (const auto &item : list) {
            refusjonsgruppe.emplace_back(Unpack(item));
        }
    }
    return {
            Unpack(pRefusjonshjemmel.refusjonshjemmel),
            pRefusjonshjemmel.kreverVarekobling,
            pRefusjonshjemmel.kreverVedtak,
            refusjonsgruppe
    };
}

Refusjonshjemmel FestDeserializer::Unpack(const PRefusjonshjemmel &pRefusjonshjemmel) const {
    const std::variant<PRefusjonshjemmel_0_0_0,PRefusjonshjemmel_1_4_0> &p = pRefusjonshjemmel;
    if (std::holds_alternative<PRefusjonshjemmel_1_4_0>(p)) {
        return Unpack(std::get<PRefusjonshjemmel_1_4_0>(p));
    } else {
        return Unpack(std::get<PRefusjonshjemmel_0_0_0>(p));
    }
}

Vilkar FestDeserializer::Unpack(const PVilkar &pVilkar) const {
    return {
        Unpack(pVilkar.id),
        Unpack(pVilkar.vilkarNr),
        Unpack(pVilkar.gruppe),
        Unpack(pVilkar.gjelderFor),
        Unpack(pVilkar.tekst),
        Unpack(pVilkar.gyldigFraDato),
        Unpack(static_cast<PStrukturertVilkar>(pVilkar))
    };
}

VarselSlv FestDeserializer::Unpack(const PVarselSlv_0_0_0 &pVarselSlv) const {
    std::vector<Visningsregel> visningsregel{};
    {
        auto list = Unpack(valueWithCodesetList, numValueWithCodesetList, pVarselSlv.visningsregel);
        for (const auto &item : list) {
            visningsregel.emplace_back(Unpack(item));
        }
    }
    return {
        Unpack(pVarselSlv.type),
        Unpack(pVarselSlv.overskrift),
        Unpack(pVarselSlv.varseltekst),
        visningsregel,
        Unpack(pVarselSlv.fraDato),
        Unpack(pVarselSlv.lenke),
        Unpack(pVarselSlv.referanseelement)
    };
}

VarselSlv FestDeserializer::Unpack(const PVarselSlv_0_4_0 &pVarselSlv) const {
    std::vector<Visningsregel> visningsregel{};
    {
        auto list = Unpack(valueWithCodesetList, numValueWithCodesetList, pVarselSlv.visningsregel);
        for (const auto &item : list) {
            visningsregel.emplace_back(Unpack(item));
        }
    }
    return {
            Unpack(pVarselSlv.type),
            Unpack(pVarselSlv.overskrift),
            Unpack(pVarselSlv.varseltekst),
            visningsregel,
            Unpack(pVarselSlv.fraDato),
            Unpack(pVarselSlv.lenke),
            Unpack(pVarselSlv.referanseelement)
    };
}

VarselSlv FestDeserializer::Unpack(const PVarselSlv &pVarselSlv) const {
    if (std::holds_alternative<PVarselSlv_0_4_0>(pVarselSlv)) {
        return Unpack(std::get<PVarselSlv_0_4_0>(pVarselSlv));
    } else {
        return Unpack(std::get<PVarselSlv_0_0_0>(pVarselSlv));
    }
}

Byttegruppe FestDeserializer::Unpack(const PByttegruppe_0_0_0 &pByttegruppe) const {
    return {
        Unpack(pByttegruppe.id).ToString(),
        Unpack(pByttegruppe.kode),
        Unpack(pByttegruppe.gyldigFraDato),
        {},
        Unpack(pByttegruppe.beskrivelseByttbarhet),
        pByttegruppe.merknadTilByttbarhet
    };
}

Byttegruppe FestDeserializer::Unpack(const PByttegruppe_1_5_0 &pByttegruppe) const {
    return {
        Unpack(pByttegruppe.id).ToString(),
        Unpack(pByttegruppe.kode),
        Unpack(pByttegruppe.gyldigFraDato),
        Unpack(pByttegruppe.gyldigTilDato),
        Unpack(pByttegruppe.beskrivelseByttbarhet),
        pByttegruppe.merknadTilByttbarhet
    };
}

Byttegruppe FestDeserializer::Unpack(const PByttegruppe &pByttegruppe) const {
    return std::visit(
        [this] (const auto &src) { return Unpack(src); },
        pByttegruppe
    );
}

Interaksjon FestDeserializer::Unpack(const PInteraksjon &pInteraksjon) const {
    std::vector<Visningsregel> visningsregel{};
    {
        auto list = Unpack(valueWithCodesetList, numValueWithCodesetList, pInteraksjon.visningsregel);
        for (const auto &item : list) {
            visningsregel.emplace_back(Unpack(item));
        }
    }
    std::vector<Referanse> referanse{};
    {
        auto list = Unpack(referanseList, numReferanseList, pInteraksjon.referanse);
        for (const auto &item : list) {
            referanse.emplace_back(Unpack(item));
        }
    }
    std::vector<Substansgruppe> substansgruppe{};
    {
        auto list = Unpack(substansgruppeList, numSubstansgruppeList, pInteraksjon.substansgruppe);
        for (const auto &item : list) {
            substansgruppe.emplace_back(Unpack(item));
        }
    }
    return {
        Unpack(pInteraksjon.id).ToString(),
        {Unpack(pInteraksjon.relevans)},
        Unpack(pInteraksjon.kliniskKonsekvens),
        Unpack(pInteraksjon.interaksjonsmekanisme),
        Unpack(pInteraksjon.kildegrunnlag),
        Unpack(pInteraksjon.handtering),
        visningsregel,
        referanse,
        substansgruppe,
        Unpack(pInteraksjon.situasjonskriterium)
    };
}

InteraksjonIkkeVurdert FestDeserializer::Unpack(const PInteraksjonIkkeVurdert &pInteraksjonIkkeVurdert) const {
    return {Unpack(pInteraksjonIkkeVurdert.atc)};
}

Kortdose FestDeserializer::Unpack(const PKortdose &pKortdose) const {
    std::vector<Legemiddelforbruk> legemiddelforbruk{};
    {
        auto list = Unpack(legemiddelforbrukList, numLegemiddelforbrukList, pKortdose.legemiddelforbruk);
        for (const auto &item : list) {
            legemiddelforbruk.emplace_back(Unpack(item));
        }
    }
    return {
        Unpack(pKortdose.kortdose),
        Unpack(pKortdose.beskrivelseTerm),
        legemiddelforbruk
    };
}

Legemiddel FestDeserializer::Unpack(const PLegemiddel_0_0_0 &pLegemiddel) const {
    std::vector<std::string> sortertVirkestoffMedStyrke{};
    {
        auto sv = Unpack(festUuidList_0_0_0, numFestUuidList_0_0_0, pLegemiddel.sortertVirkestoffMedStyrke);
        for (const auto &v : sv) {
            sortertVirkestoffMedStyrke.push_back(Unpack(v).ToString());
        }
    }
    return {
        Unpack(static_cast<PLegemiddelCore_0_0_0>(pLegemiddel)),
        Unpack(pLegemiddel.administreringLegemiddel),
        sortertVirkestoffMedStyrke
    };
}

Legemiddel FestDeserializer::Unpack(const PLegemiddel_0_4_0 &pLegemiddel) const {
    std::vector<std::string> sortertVirkestoffMedStyrke{};
    {
        auto sv = Unpack(festUuidList_0_4_0, numFestUuidList_0_4_0, pLegemiddel.sortertVirkestoffMedStyrke);
        for (const auto &v : sv) {
            sortertVirkestoffMedStyrke.push_back(Unpack(v).ToString());
        }
    }
    return {
            Unpack(static_cast<PLegemiddelCore_0_4_0>(pLegemiddel)),
            Unpack(pLegemiddel.administreringLegemiddel),
            sortertVirkestoffMedStyrke
    };
}

Legemiddel FestDeserializer::Unpack(const PLegemiddel &pLegemiddel) const {
    const std::variant<PLegemiddel_0_0_0,PLegemiddel_0_4_0> &v = pLegemiddel;
    if (std::holds_alternative<PLegemiddel_0_4_0>(v)) {
        return Unpack(std::get<PLegemiddel_0_4_0>(v));
    } else {
        return Unpack(std::get<PLegemiddel_0_0_0>(v));
    }
}

LegemiddelCore FestDeserializer::Unpack(const PLegemiddelCore_0_0_0 &pLegemiddelCore) const {
    std::vector<std::string> refVilkar{};
    {
        auto rv = Unpack(festUuidList_0_0_0, numFestUuidList_0_0_0, pLegemiddelCore.refVilkar);
        for (const auto &v : rv) {
            refVilkar.push_back(Unpack(v).ToString());
        }
    }
    return {{Unpack(pLegemiddelCore.atc)}, Unpack(pLegemiddelCore.navnFormStyrke),
            {Unpack(pLegemiddelCore.reseptgruppe)}, {Unpack(pLegemiddelCore.legemiddelformKort)},
            refVilkar, {Unpack(pLegemiddelCore.typeSoknadSlv)}, FromRaw(pLegemiddelCore.opioidsoknad),
            {Unpack(pLegemiddelCore.svartTrekant)}};
}

LegemiddelCore FestDeserializer::Unpack(const PLegemiddelCore_0_4_0 &pLegemiddelCore) const {
    std::vector<std::string> refVilkar{};
    {
        auto rv = Unpack(festUuidList_0_4_0, numFestUuidList_0_4_0, pLegemiddelCore.refVilkar);
        for (const auto &v : rv) {
            refVilkar.push_back(Unpack(v).ToString());
        }
    }
    return {{Unpack(pLegemiddelCore.atc)}, Unpack(pLegemiddelCore.navnFormStyrke),
            {Unpack(pLegemiddelCore.reseptgruppe)}, {Unpack(pLegemiddelCore.legemiddelformKort)},
            refVilkar, {Unpack(pLegemiddelCore.typeSoknadSlv)}, FromRaw(pLegemiddelCore.opioidsoknad),
            {Unpack(pLegemiddelCore.svartTrekant)}};
}

LegemiddelCore FestDeserializer::Unpack(const PLegemiddelCore &pLegemiddelCore) const {
    if (std::holds_alternative<PLegemiddelCore_0_4_0>(pLegemiddelCore)) {
        return Unpack(std::get<PLegemiddelCore_0_4_0>(pLegemiddelCore));
    } else {
        return Unpack(std::get<PLegemiddelCore_0_0_0>(pLegemiddelCore));
    }
}

AdministreringLegemiddel FestDeserializer::Unpack(const PAdministreringLegemiddel &pAdministreringLegemiddel) const {
    std::vector<BruksomradeEtikett> bruksomradeEtikett{};
    {
        auto vc = Unpack(valueWithCodesetList, numValueWithCodesetList, pAdministreringLegemiddel.bruksomradeEtikett);
        for (const auto &v : vc) {
            bruksomradeEtikett.emplace_back(Unpack(v));
        }
    }
    std::vector<ForhandsregelInntak> forhandsregelInntak{};
    {
        auto vc = Unpack(valueWithCodesetList, numValueWithCodesetList, pAdministreringLegemiddel.forhandsregelInntak);
        for (const auto &v : vc) {
            forhandsregelInntak.emplace_back(Unpack(v));
        }
    }
    std::vector<ValueWithCodeSet> kortdose{};
    {
        auto vc = Unpack(valueWithCodesetList, numValueWithCodesetList, pAdministreringLegemiddel.kortdose);
        for (const auto &v : vc) {
            kortdose.push_back(Unpack(v));
        }
    }
    return {
            {Unpack(pAdministreringLegemiddel.administrasjonsvei)},
            {Unpack(pAdministreringLegemiddel.enhetDosering)},
            bruksomradeEtikett,
            {Unpack(pAdministreringLegemiddel.kanKnuses)},
            forhandsregelInntak,
            kortdose,
            {Unpack(pAdministreringLegemiddel.deling)},
            {Unpack(pAdministreringLegemiddel.kanApnes)},
            {Unpack(pAdministreringLegemiddel.bolus)},
            {Unpack(pAdministreringLegemiddel.injeksjonshastighetBolus)},
            FromRaw(pAdministreringLegemiddel.blandingsveske)
    };
}

Preparatomtaleavsnitt FestDeserializer::Unpack(const PPreparatomtaleavsnitt &pPreparatomtaleavsnitt) const {
    return {
            Unpack(pPreparatomtaleavsnitt.avsnittoverskrift),
            Unpack(pPreparatomtaleavsnitt.lenke)
    };
}

Pakningskomponent FestDeserializer::Unpack(const PPakningskomponent &pPakningskomponent) const {
    return {{Unpack(pPakningskomponent.pakningstype), Unpack(pPakningskomponent.mengde)}, pPakningskomponent.antall};
}

PakningskomponentInfo FestDeserializer::Unpack(const PPakningskomponentInfo &pPakningskomponentInfo) const {
    return {Unpack(pPakningskomponentInfo.pakningstype), Unpack(pPakningskomponentInfo.mengde)};
}

Pakningsinfo FestDeserializer::Unpack(const PPakningsinfo &pakningsinfo) const {
    std::vector<Pakningskomponent> pakningskomponent{};
    {
        auto list = Unpack(pakningskomponentList, numPakningskomponent, pakningsinfo.pakningskomponent);
        for (const auto &p : list) {
            pakningskomponent.emplace_back(Unpack(p));
        }
    }
    return {
        Unpack(pakningsinfo.merkevareId).ToString(),
        Unpack(pakningsinfo.pakningsstr),
        {Unpack(pakningsinfo.enhetPakning)},
        {Unpack(pakningsinfo.pakningstype)},
        Unpack(pakningsinfo.mengde),
        {Unpack(pakningsinfo.ddd)},
        pakningskomponent,
        pakningsinfo.statistikkfaktor,
        pakningsinfo.antall,
        pakningsinfo.multippel
    };
}

PrisVare FestDeserializer::Unpack(const PPrisVare &prisVare) const {
    return {Unpack(prisVare.type), Unpack(prisVare.pris), Unpack(prisVare.gyldigFraDato), Unpack(prisVare.gyldigTilDato)};
}

Markedsforingsinfo FestDeserializer::Unpack(const PMarkedsforingsinfo &pmarkedsforingsinfo) const {
    return {
        Unpack(pmarkedsforingsinfo.markedsforingsdato),
        Unpack(pmarkedsforingsinfo.varenrUtgaende),
        Unpack(pmarkedsforingsinfo.midlUtgattDato),
        Unpack(pmarkedsforingsinfo.avregDato)
    };
}

Refusjon FestDeserializer::Unpack(const PRefusjon &pRefusjon) const {
    std::vector<std::string> refRefusjonsgruppe{};
    {
        auto list = Unpack(stringList, numStringList, pRefusjon.refRefusjonsgruppe);
        for (const auto &id : list) {
            refRefusjonsgruppe.push_back(Unpack(id));
        }
    }
    return {
        refRefusjonsgruppe,
        Unpack(pRefusjon.gyldigFraDato),
        Unpack(pRefusjon.forskrivesTilDato),
        Unpack(pRefusjon.utleveresTilDato)
    };
}

PakningByttegruppe FestDeserializer::Unpack(const PPakningByttegruppe &pPakningByttegruppe) const {
    return {
        Unpack(pPakningByttegruppe.refByttegruppe).ToString(),
        Unpack(pPakningByttegruppe.gyldigFraDato)
    };
}

ProduktInfoVare FestDeserializer::Unpack(const PProduktInfoVare &pProduktInfoVare) const {
    return {
        Unpack(pProduktInfoVare.produktNr),
        Unpack(pProduktInfoVare.volum),
        {Unpack(pProduktInfoVare.enhetStorrelse)},
        pProduktInfoVare.antPerPakning,
        FromRaw(pProduktInfoVare.tillattMerMakspris)
    };
}

Leverandor FestDeserializer::Unpack(const PLeverandor &pLeverandor) const {
    return {
        Unpack(pLeverandor.navn),
        Unpack(pLeverandor.adresse),
        Unpack(pLeverandor.telefon)
    };
}

Element FestDeserializer::Unpack(const PElement_0_0_0 &pElement) const {
    return {
        Unpack(pElement.id),
        Unpack(pElement.kode),
        { Unpack(static_cast<PTerm>(pElement)) }
    };
}

Element FestDeserializer::Unpack(const PElement_0_3_0 &pElement) const {
    std::vector<Term> terms{};
    {
        std::vector<PTerm> pTerms = Unpack(termList, numTerm, pElement.term);
        for (const auto &pTerm : pTerms) {
            terms.emplace_back(Unpack(pTerm));
        }
    }
    return {
            Unpack(pElement.id),
            Unpack(pElement.kode),
            terms
    };
}

Element FestDeserializer::Unpack(const PElement &pElement) const {
    if (std::holds_alternative<PElement_0_3_0>(pElement)) {
        return Unpack(std::get<PElement_0_3_0>(pElement));
    } else {
        return Unpack(std::get<PElement_0_0_0>(pElement));
    }
}

Term FestDeserializer::Unpack(const PTerm &pTerm) const {
   return {
       Unpack(pTerm.term),
       Unpack(pTerm.beskrivelseTerm),
       {Unpack(pTerm.sprak)}
   };
}

RefRefusjonsvilkar FestDeserializer::Unpack(const PRefRefusjonsvilkar_0_0_0 &pref) const {
    return {
        Unpack(pref.id).ToString(),
        Unpack(pref.fraDato),
        {}
    };
}

RefRefusjonsvilkar FestDeserializer::Unpack(const PRefRefusjonsvilkar_1_2_0 &pref) const {
    return {
            Unpack(pref.id).ToString(),
            Unpack(pref.fraDato),
            Unpack(pref.tilDato)
    };
}

RefRefusjonsvilkar FestDeserializer::Unpack(const PRefRefusjonsvilkar &pref) const {
    if (std::holds_alternative<PRefRefusjonsvilkar_1_2_0>(pref)) {
        return Unpack(std::get<PRefRefusjonsvilkar_1_2_0>(pref));
    } else {
        return Unpack(std::get<PRefRefusjonsvilkar_0_0_0>(pref));
    }
}

Refusjonskode FestDeserializer::Unpack(const PRefusjonskode_0_0_0 &pref) const {
    std::vector<std::string> underterm{};
    {
        auto list = Unpack(stringList, numStringList, pref.underterm);
        for (const auto &put : list) {
            underterm.emplace_back(Unpack(put));
        }
    }
    std::vector<RefRefusjonsvilkar> refusjonsvilkar{};
    {
        auto list = Unpack(refRefusjonsvilkarList_0_0_0, numRefRefusjonsvilkar_0_0_0, pref.refusjonsvilkar);
        for (const auto &pr : list) {
            refusjonsvilkar.emplace_back(Unpack(pr));
        }
    }
    return {
            Unpack(pref.refusjonskode),
            Unpack(pref.gyldigFraDato),
            Unpack(pref.forskrivesTilDato),
            {},
            underterm,
            refusjonsvilkar
    };
}

Refusjonskode FestDeserializer::Unpack(const PRefusjonskode_0_1_0 &pref) const {
    std::vector<std::string> underterm{};
    {
        auto list = Unpack(stringList, numStringList, pref.underterm);
        for (const auto &put : list) {
            underterm.emplace_back(Unpack(put));
        }
    }
    std::vector<RefRefusjonsvilkar> refusjonsvilkar{};
    {
        auto list = Unpack(refRefusjonsvilkarList_0_0_0, numRefRefusjonsvilkar_0_0_0, pref.refusjonsvilkar);
        for (const auto &pr : list) {
            refusjonsvilkar.emplace_back(Unpack(pr));
        }
    }
    return {
        Unpack(pref.refusjonskode),
        Unpack(pref.gyldigFraDato),
        Unpack(pref.forskrivesTilDato),
        Unpack(pref.utleveresTilDato),
        underterm,
        refusjonsvilkar
    };
}

Refusjonskode FestDeserializer::Unpack(const PRefusjonskode_1_2_0 &pref) const {
    std::vector<std::string> underterm{};
    {
        auto list = Unpack(stringList, numStringList, pref.underterm);
        for (const auto &put : list) {
            underterm.emplace_back(Unpack(put));
        }
    }
    std::vector<RefRefusjonsvilkar> refusjonsvilkar{};
    {
        auto list = Unpack(refRefusjonsvilkarList_1_2_0, numRefRefusjonsvilkar_1_2_0, pref.refusjonsvilkar);
        for (const auto &pr : list) {
            refusjonsvilkar.emplace_back(Unpack(pr));
        }
    }
    return {
            Unpack(pref.refusjonskode),
            Unpack(pref.gyldigFraDato),
            Unpack(pref.forskrivesTilDato),
            Unpack(pref.utleveresTilDato),
            underterm,
            refusjonsvilkar
    };
}

Refusjonskode FestDeserializer::Unpack(const PRefusjonskode &pref) const {
    if (std::holds_alternative<PRefusjonskode_1_2_0>(pref)) {
        return Unpack(std::get<PRefusjonskode_1_2_0>(pref));
    } else if (std::holds_alternative<PRefusjonskode_0_1_0>(pref)) {
        return Unpack(std::get<PRefusjonskode_0_1_0>(pref));
    } else {
        return Unpack(std::get<PRefusjonskode_0_0_0>(pref));
    }
}

Refusjonsgruppe FestDeserializer::Unpack(const PRefusjonsgruppe &pRefusjonsgruppe) const {
    std::vector<Refusjonskode> refusjonskode{};
    if (versionMajor > 1 || (versionMajor == 1 && versionMinor > 1)) {
        auto list = Unpack(refusjonskodeList_1_2_0, numRefusjonskode_1_2_0, pRefusjonsgruppe.refusjonskode);
        for (const auto &item : list) {
            refusjonskode.emplace_back(Unpack(item));
        }
    } else if (versionMajor > 0 || versionMinor > 0) {
        auto list = Unpack(refusjonskodeList_0_1_0, numRefusjonskode_0_1_0, pRefusjonsgruppe.refusjonskode);
        for (const auto &item : list) {
            refusjonskode.emplace_back(Unpack(item));
        }
    } else {
        auto list = Unpack(refusjonskodeList_0_0_0, numRefusjonskode_0_0_0, pRefusjonsgruppe.refusjonskode);
        for (const auto &item : list) {
            refusjonskode.emplace_back(Unpack(item));
        }
    }
    std::vector<std::string> refVilkar{};
    {
        auto list = Unpack(stringList, numStringList, pRefusjonsgruppe.refVilkar);
        for (const auto &item : list) {
            refVilkar.emplace_back(Unpack(item));
        }
    }
    return {
        Unpack(pRefusjonsgruppe.id),
        Unpack(pRefusjonsgruppe.gruppeNr),
        Unpack(pRefusjonsgruppe.atc),
        Unpack(pRefusjonsgruppe.refusjonsberettigetBruk),
        refusjonskode,
        refVilkar,
        pRefusjonsgruppe.kreverRefusjonskode
    };
}

StrukturertVilkar FestDeserializer::Unpack(const PStrukturertVilkar &pStrukturertVilkar) const {
    return {
        Unpack(pStrukturertVilkar.type),
        Unpack(pStrukturertVilkar.verdiKodet),
        Unpack(pStrukturertVilkar.verdiTekst)
    };
}

Referanseelement FestDeserializer::Unpack(const PReferanseelement_0_0_0 &pReferanseelement) const {
    std::vector<std::string> refs{};
    {
        auto list = Unpack(festUuidList_0_0_0, numFestUuidList_0_0_0, pReferanseelement.refs);
        for (const auto &item : list) {
            refs.emplace_back(Unpack(item).ToString());
        }
    }
    return {
        Unpack(pReferanseelement.klasse),
        refs
    };
}

Referanseelement FestDeserializer::Unpack(const PReferanseelement_0_4_0 &pReferanseelement) const {
    std::vector<std::string> refs{};
    {
        auto list = Unpack(festUuidList_0_4_0, numFestUuidList_0_4_0, pReferanseelement.refs);
        for (const auto &item : list) {
            refs.emplace_back(Unpack(item).ToString());
        }
    }
    return {
            Unpack(pReferanseelement.klasse),
            refs
    };
}

Referanseelement FestDeserializer::Unpack(const PReferanseelement &pReferanseelement) const {
    if (std::holds_alternative<PReferanseelement_0_4_0>(pReferanseelement)) {
        return Unpack(std::get<PReferanseelement_0_4_0>(pReferanseelement));
    } else {
        return Unpack(std::get<PReferanseelement_0_0_0>(pReferanseelement));
    }
}

Referanse FestDeserializer::Unpack(const PReferanse &pReferanse) const {
    return {
        Unpack(pReferanse.kilde),
        Unpack(pReferanse.lenke)
    };
}

Substansgruppe FestDeserializer::Unpack(const PSubstansgruppe &pSubstansgruppe) const {
    std::vector<Substans> substans{};
    {
        auto list = Unpack(substansList, numSubstansList, pSubstansgruppe.substans);
        for (const auto &item : list) {
            substans.emplace_back(Unpack(item));
        }
    }
    return {
        substans,
        Unpack(pSubstansgruppe.navn)
    };
}

Substans FestDeserializer::Unpack(const PSubstans &pSubstans) const {
    return {
        Unpack(pSubstans.substans),
        Unpack(pSubstans.atc),
        Unpack(pSubstans.refVirkestoff).ToString()
    };
}

DoseFastTidspunkt FestDeserializer::Unpack(const PDoseFastTidspunkt &pDoseFastTidspunkt) const {
    return {
        Unpack(pDoseFastTidspunkt.mengde),
        Unpack(pDoseFastTidspunkt.intervall),
        Unpack(pDoseFastTidspunkt.tidsomrade),
        pDoseFastTidspunkt.gisEksakt,
        {pDoseFastTidspunkt.dagerPa, pDoseFastTidspunkt.dagerAv}
    };
}

Dosering FestDeserializer::Unpack(const PDosering &pDosering) const {
    std::vector<DoseFastTidspunkt> doseFastTidspunkt{};
    {
        auto list = Unpack(doseFastTidspunktList, numDoseFastTidspunktList, static_cast<const GenericListItems32>(pDosering));
        for (const auto &item : list) {
            doseFastTidspunkt.emplace_back(Unpack(item));
        }
    }
    return {doseFastTidspunkt};
}

Legemiddelforbruk FestDeserializer::Unpack(const PLegemiddelforbruk &pLegemiddelforbruk) const {
    std::vector<Dosering> dosering{};
    {
        auto list = Unpack(doseringList, numDoseringList, pLegemiddelforbruk.dosering);
        for (const auto &item : list) {
            dosering.emplace_back(Unpack(item));
        }
    }
    return {
        (int) pLegemiddelforbruk.lopenr,
        pLegemiddelforbruk.iterasjoner,
        pLegemiddelforbruk.mengde,
        Unpack(pLegemiddelforbruk.periode),
        dosering
    };
}

Lenke FestDeserializer::Unpack(const PLenke &lenke) const {
    return {Unpack(lenke.beskrivelse), Unpack(lenke.www)};
}

std::vector<PPakningsinfo> FestDeserializer::GetPakningsinfoList(const PLegemiddelpakning_0_0_0 &ppakning) const {
    return Unpack(pakningsinfoList, numPakningsinfo, ppakning.pakningsinfo);
}

std::vector<PPakningsinfo> FestDeserializer::GetPakningsinfoList(const PLegemiddelpakning_0_4_0 &ppakning) const {
    return Unpack(pakningsinfoList, numPakningsinfo, ppakning.pakningsinfo);
}

std::vector<PPakningsinfo> FestDeserializer::GetPakningsinfoList(const PLegemiddelpakning_1_3_0 &ppakning) const {
    return Unpack(pakningsinfoList, numPakningsinfo, ppakning.pakningsinfo);
}

std::vector<PPakningsinfo> FestDeserializer::GetPakningsinfoList(const PLegemiddelpakning &lp) const {
    const std::variant<PLegemiddelpakning_0_0_0,PLegemiddelpakning_0_4_0,PLegemiddelpakning_1_3_0> &p = lp;
    if (std::holds_alternative<PLegemiddelpakning_1_3_0>(p)) {
        return GetPakningsinfoList(std::get<PLegemiddelpakning_1_3_0>(p));
    } else if (std::holds_alternative<PLegemiddelpakning_0_4_0>(p)) {
        return GetPakningsinfoList(std::get<PLegemiddelpakning_0_4_0>(p));
    } else {
        return GetPakningsinfoList(std::get<PLegemiddelpakning_0_0_0>(p));
    }
}

std::vector<PElement_0_0_0> FestDeserializer::GetElementList(const POppfKodeverk_0_0_0 &pkodeverk) const {
    return Unpack(elementList_0_0_0, numElement_0_0_0, pkodeverk.elements);;
}

std::vector<PElement_0_3_0> FestDeserializer::GetElementList(const POppfKodeverk_0_3_0 &pkodeverk) const {
    return Unpack(elementList_0_3_0, numElement_0_3_0, pkodeverk.elements);;
}

std::vector<PElement> FestDeserializer::GetElementList(const POppfKodeverk &kodeverk) const {
    std::vector<PElement> element{};
    if (std::holds_alternative<POppfKodeverk_0_3_0>(kodeverk)) {
        auto element_0_3_0 = GetElementList(std::get<POppfKodeverk_0_3_0>(kodeverk));
        element.reserve(element_0_3_0.size());
        for (const auto &e : element_0_3_0) {
            element.emplace_back(e);
        }
    } else {
        auto element_0_0_0 = GetElementList(std::get<POppfKodeverk_0_0_0>(kodeverk));
        element.reserve(element_0_0_0.size());
        for (const auto &e : element_0_0_0) {
            element.emplace_back(e);
        }
    }
    return element;
}

std::vector<PReseptgyldighet> FestDeserializer::GetReseptgyldighetList(const PLegemiddelMerkevare_0_4_0 &pmerkevare) const {
    return Unpack(reseptgyldighetList, numReseptgyldighet, pmerkevare.reseptgyldighet);;
}

std::vector<PReseptgyldighet> FestDeserializer::GetReseptgyldighetList(const PLegemiddelMerkevare_0_0_0 &pmerkevare) const {
    return Unpack(reseptgyldighetList, numReseptgyldighet, pmerkevare.reseptgyldighet);;
}

std::vector<PReseptgyldighet> FestDeserializer::GetReseptgyldighetList(const PLegemiddelMerkevare &pmerkevare) const {
    const auto &pvar = static_cast<const std::variant<PLegemiddelMerkevare_0_4_0,PLegemiddelMerkevare_0_0_0> &>(pmerkevare);
    if (std::holds_alternative<PLegemiddelMerkevare_0_4_0>(pvar)) {
        return GetReseptgyldighetList(std::get<PLegemiddelMerkevare_0_4_0>(pvar));
    } else {
        return GetReseptgyldighetList(std::get<PLegemiddelMerkevare_0_0_0>(pvar));
    }
}

std::vector<FestUuid> FestDeserializer::GetRefMerkevare(const PLegemiddelVirkestoff &pvirkestoff) const {
    const auto &pvar = static_cast<std::variant<PLegemiddelVirkestoff_0_4_0,PLegemiddelVirkestoff_0_0_0>>(pvirkestoff);
    if (std::holds_alternative<PLegemiddelVirkestoff_0_4_0>(pvar)) {
        auto pv = std::get<PLegemiddelVirkestoff_0_4_0>(pvar);
        return GetFestUuids(pv.GetRefLegemiddelMerkevare());
    } else {
        auto pv = std::get<PLegemiddelVirkestoff_0_0_0>(pvar);
        return GetFestUuids(pv.GetRefLegemiddelMerkevare());
    }
}

std::vector<PFestId> FestDeserializer::GetSortertVirkestoffMedStyrke(const PLegemiddel &pLegemiddel) const {
    struct {
        const FestDeserializer *deserializer;
        std::vector<PFestId> operator () (const PLegemiddel_0_0_0 &pLegemiddel) const {
            return deserializer->Unpack(deserializer->festUuidList_0_0_0, deserializer->numFestUuidList_0_0_0, pLegemiddel.sortertVirkestoffMedStyrke);
        }
        std::vector<PFestId> operator () (const PLegemiddel_0_4_0 &pLegemiddel) const {
            return deserializer->Unpack(deserializer->festUuidList_0_4_0, deserializer->numFestUuidList_0_4_0, pLegemiddel.sortertVirkestoffMedStyrke);
        }
    } visitor{.deserializer = this};
    return std::visit(visitor, static_cast<const std::variant<PLegemiddel_0_0_0,PLegemiddel_0_4_0> &>(pLegemiddel));
}

std::vector<PFestId> FestDeserializer::GetSortertVirkestoffUtenStyrke(const PLegemiddelMerkevare &pLegemiddelMerkevare) const {
    struct {
        const FestDeserializer *deserializer;
        std::vector<PFestId> operator () (const PLegemiddelMerkevare_0_0_0 &pLegemiddel) const {
            return deserializer->Unpack(deserializer->festUuidList_0_0_0, deserializer->numFestUuidList_0_0_0, pLegemiddel.sortertVirkestoffUtenStyrke);
        }
        std::vector<PFestId> operator () (const PLegemiddelMerkevare_0_4_0 &pLegemiddel) const {
            return deserializer->Unpack(deserializer->festUuidList_0_4_0, deserializer->numFestUuidList_0_4_0, pLegemiddel.sortertVirkestoffUtenStyrke);
        }
    } visitor{.deserializer = this};
    return std::visit(visitor, static_cast<const std::variant<PLegemiddelMerkevare_0_4_0,PLegemiddelMerkevare_0_0_0> &>(pLegemiddelMerkevare));
}

std::vector<FestUuid> FestDeserializer::GetFestUuids(const GenericListItems32 &items) const {
    std::vector<FestUuid> ids{};
    {
        auto pf = Unpack(festUuidList_0_0_0, numFestUuidList_0_0_0, items);
        for (const auto &pid : pf) {
            ids.emplace_back(Unpack(pid));
        }
    }
    return ids;
}

std::vector<FestUuid> FestDeserializer::GetFestUuids(const GenericListItems64 &items) const {
    std::vector<FestUuid> ids{};
    {
        auto pf = Unpack(festUuidList_0_4_0, numFestUuidList_0_4_0, items);
        for (const auto &pid : pf) {
            ids.emplace_back(Unpack(pid));
        }
    }
    return ids;
}

std::vector<FestUuid>
FestDeserializer::GetFestUuids(const std::variant<GenericListItems32, GenericListItems64> &v) const {
    if (std::holds_alternative<GenericListItems64>(v)) {
        return GetFestUuids(std::get<GenericListItems64>(v));
    } else {
        return GetFestUuids(std::get<GenericListItems32>(v));
    }
}

void Quota(std::vector<FestDbQuota> &quotas, const std::string &name, size_t num, size_t compatMax=std::numeric_limits<uint16_t>::max(), size_t hardMax=std::numeric_limits<uint16_t>::max()) {
    FestDbQuota q{
        .name = name,
        .total = num,
        .compatMax = compatMax,
        .hardMax = hardMax
    };
    quotas.emplace_back(std::move(q));
}

constexpr uint64_t min(uint64_t first, uint64_t second) {
    if (first < second) {
        return first;
    }
    return second;
}

std::vector<FestDbQuota> FestDeserializer::GetQuotas() const {
    std::vector<FestDbQuota> quotas{};
    Quota(quotas, "Merkevare 0.0.0", numMerkevare_0_0_0);
    Quota(quotas, "Merkevare 0.4.0", numMerkevare_0_4_0, std::numeric_limits<uint32_t>::max(), std::numeric_limits<uint32_t>::max());
    Quota(quotas, "Pakning 0.0.0", numPakning_0_0_0, min(GenericListItems64::max_address, std::numeric_limits<uint16_t>::max()), min(GenericListItems64::max_address, std::numeric_limits<uint32_t>::max()));
    Quota(quotas, "Pakning 0.4.0", numPakning_0_4_0, min(GenericListItems64::max_address, std::numeric_limits<uint32_t>::max()), min(GenericListItems64::max_address, std::numeric_limits<uint32_t>::max()));
    Quota(quotas, "Legemiddel virkestoff 0.0.0", numLegemiddelVirkestoff_0_0_0);
    Quota(quotas, "Legemiddel virkestoff 0.4.0", numLegemiddelVirkestoff_0_4_0, std::numeric_limits<uint32_t>::max(), std::numeric_limits<uint32_t>::max());
    Quota(quotas, "Med forbr matr", numMedForbrMatr);
    Quota(quotas, "Naringsmiddel", numNaringsmiddel);
    Quota(quotas, "Brystprotese", numBrystprotese);
    Quota(quotas, "Legemiddeldose 0.0.0", numLegemiddeldose_0_0_0);
    Quota(quotas, "Legemiddeldose 0.4.0", numLegemiddeldose_0_4_0, std::numeric_limits<uint32_t>::max(), std::numeric_limits<uint32_t>::max());
    Quota(quotas, "Virkestoff med styrke", numVirkestoffMedStyrke);
    Quota(quotas, "Virkestoff v0.0.0", numVirkestoff_0_0_0);
    Quota(quotas, "Virkestoff v0.4.0", numVirkestoff_0_4_0, std::numeric_limits<uint32_t>::max(), std::numeric_limits<uint32_t>::max());
    Quota(quotas, "Kodeverk v0.0.0", numKodeverk_0_0_0);
    Quota(quotas, "Kodeverk v0.3.0", numKodeverk_0_3_0);
    Quota(quotas, "Refusjon v0.0.0", numRefusjon_0_0_0);
    Quota(quotas, "Refusjon v1.4.0", numRefusjon_1_4_0);
    Quota(quotas, "Vilkar", numVilkar);
    Quota(quotas, "Varsel slv v0.0.0", numVarselSlv_0_0_0);
    Quota(quotas, "Varsel slv v0.4.0", numVarselSlv_0_4_0, std::numeric_limits<uint32_t>::max(), std::numeric_limits<uint32_t>::max());
    Quota(quotas, "Byttegruppe", numByttegruppe);
    Quota(quotas, "Interaksjon", numInteraksjon);
    Quota(quotas, "Interaksjon ikke vurdert", numInteraksjonIkkeVurdert);
    Quota(quotas, "Str dosering", numStrDosering);
    Quota(quotas, "Fest UUID", numFestUuid, 16777215, 16777215);
    Quota(quotas, "Fest UUID list 0.0.0", numFestUuidList_0_0_0, min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()), min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()));
    Quota(quotas, "Fest UUID list 0.4.0", numFestUuidList_0_4_0, min(GenericListItems64::max_address, std::numeric_limits<uint32_t>::max()), min(GenericListItems64::max_address, std::numeric_limits<uint32_t>::max()));
    Quota(quotas, "Value with codeset list", numValueWithCodesetList, min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()), min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()));
    Quota(quotas, "Reseptgyldighet", numReseptgyldighet, min(GenericListItems32::max_address, 255), min(GenericListItems32::max_address, 255));
    Quota(quotas, "Pakningskomponent", numPakningskomponent, min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()), min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()));
    Quota(quotas, "Pakningskomponent info", numPakningskomponentInfo, min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()), min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()));
    Quota(quotas, "Pakningsinfo", numPakningsinfo, min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()), min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()));
    Quota(quotas, "Pris vare", numPrisVare, min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()), min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()));
    Quota(quotas, "Refusjon list", numRefusjonList, min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()), min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()));
    Quota(quotas, "Element 0.0.0", numElement_0_0_0, min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()), min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()));
    Quota(quotas, "Element 0.3.0", numElement_0_3_0, min(GenericListItems64::max_address, std::numeric_limits<uint32_t>::max()), min(GenericListItems64::max_address, std::numeric_limits<uint32_t>::max()));
    Quota(quotas, "Term", numTerm, min(GenericListItems64::max_address, std::numeric_limits<uint32_t>::max()), min(GenericListItems64::max_address, std::numeric_limits<uint32_t>::max()));
    Quota(quotas, "Ref refusjonsvilkar 0.0.0", numRefRefusjonsvilkar_0_0_0, min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()), min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()));
    Quota(quotas, "Ref refusjonsvilkar 1.2.0", numRefRefusjonsvilkar_1_2_0, min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()), min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()));
    Quota(quotas, "Refusjonskode 0.0.0", numRefusjonskode_0_0_0, min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()), min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()));
    Quota(quotas, "Refusjonskode 0.1.0", numRefusjonskode_0_1_0, min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()), min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()));
    Quota(quotas, "Refusjonskode 1.2.0", numRefusjonskode_1_2_0, min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()), min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()));
    Quota(quotas, "Referanse list", numReferanseList, min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()), min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()));
    Quota(quotas, "Substansgruppe list", numSubstansgruppeList, min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()), min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()));
    Quota(quotas, "Substans list", numSubstansList, min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()), min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()));
    Quota(quotas, "Dose fast tidspunkt list", numDoseFastTidspunktList, min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()), min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()));
    Quota(quotas, "Dosering list", numDoseringList, min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()), min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()));
    Quota(quotas, "Legemiddelforbruk list", numLegemiddelforbrukList, min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()), min(GenericListItems32::max_address, std::numeric_limits<uint16_t>::max()));
    Quota(quotas, "Uint16_t list 0.0.0", numUint16List_V_0_0_0, min(GenericListItems32::max_address, 4194303), min(GenericListItems32::max_address, 4194303));
    Quota(quotas, "Uint16_t list", numUint16List, min(GenericListItems64::max_address, std::numeric_limits<uint32_t>::max()), min(GenericListItems64::max_address, std::numeric_limits<uint32_t>::max()));
    Quota(quotas, "Uint32_t list", numUint32List, min(GenericListItems64::max_address, std::numeric_limits<uint32_t>::max()), min(GenericListItems64::max_address, std::numeric_limits<uint32_t>::max()));
    Quota(quotas, "FEST Versions 0.0.0", numFests_V_0_0_0, 1023, 1023);
    Quota(quotas, "FEST Versions 0.2.0", numFests_V_0_2_0, std::numeric_limits<uint16_t>::max(), std::numeric_limits<uint16_t>::max());
    Quota(quotas, "FEST Versions 0.3.0", numFests_V_0_3_0, std::numeric_limits<uint16_t>::max(), std::numeric_limits<uint16_t>::max());
    Quota(quotas, "FEST Versions 0.4.0", numFests_V_0_4_0, std::numeric_limits<uint16_t>::max(), std::numeric_limits<uint16_t>::max());
    Quota(quotas, "String list", numStringList);
    Quota(quotas, "Stringblock", stringblocksize, std::numeric_limits<uint32_t>::max(), std::numeric_limits<uint32_t>::max());
    return quotas;
}