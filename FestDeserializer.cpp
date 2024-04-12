//
// Created by sigsegv on 1/13/23.
//

#include "FestDeserializer.h"
#include "FestSerializer.h"
#include "FestVectors.h"
#include "DbVersion.h"
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/mman.h>
#include <iostream>
#include <type_traits>

FestDeserializer::FestDeserializer(const std::string &filename) : mapping(nullptr), mapsize(0) {
    auto fd = open(filename.c_str(), O_RDONLY);
    if (fd < 0) {
        std::cerr << "Error: Open file: " << filename << ": " << strerror(errno) << "\n";
        throw PackException("Open file");
    }
    auto size = lseek(fd, 0, SEEK_END);
    if (lseek(fd, 0, SEEK_SET) != 0) {
        std::cerr << "Error: Seek start: " << strerror(errno) << "\n";
        if (close(fd) != 0) {
            std::cerr << "Error: Close file: " << strerror(errno )<< "\n";
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
        std::cerr << "Error: Close file: " << strerror(errno )<< "\n";
    }
    FestFirstHeader *header = (FestFirstHeader *) mapping;
    size_t offset = sizeof(*header);
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
        if (version.major != 0) {
            std::cerr << "Error: Major version " << version.major << " can not be read\n";
            throw PackException("Major version of file");
        }
        if (version.minor != 0) {
            std::cerr << "Warning: Minor version " << version.minor << " contains unsupported data (ignored)\n";
        }
    }
    merkevare = (POppfLegemiddelMerkevare *) (void *) (((uint8_t *) mapping) + offset);
    numMerkevare = header->numLegemiddelMerkevare;
    offset += ((size_t) numMerkevare) * sizeof(*merkevare);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    pakning = (POppfLegemiddelpakning *) (void *) (((uint8_t *) mapping) + offset);
    numPakning = header->numPakning;
    offset += ((size_t) numPakning) * sizeof(*pakning);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    legemiddelVirkestoff = (POppfLegemiddelVirkestoff *) (void *) (((uint8_t *) mapping) + offset);
    numLegemiddelVirkestoff = header->numLegemiddelVirkestoff;
    offset += ((size_t) numLegemiddelVirkestoff) * sizeof(*legemiddelVirkestoff);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
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
    legemiddeldose = (POppfLegemiddeldose *) (void *) (((uint8_t *) mapping) + offset);
    numLegemiddeldose = header->numLegemiddeldose;
    offset += ((size_t) numLegemiddeldose) * sizeof(*legemiddeldose);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
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
    virkestoff = (POppfVirkestoff *) (void *) (((uint8_t *) mapping) + offset);
    numVirkestoff = header->numVirkestoff;
    offset += ((size_t) numVirkestoff) * sizeof(*virkestoff);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    kodeverk = (POppfKodeverk *) (void *) (((uint8_t *) mapping) + offset);
    numKodeverk = header->numKodeverk;
    offset += ((size_t) numKodeverk) * sizeof(*kodeverk);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    refusjon = (POppfRefusjon *) (void *) (((uint8_t *) mapping) + offset);
    numRefusjon = header->numRefusjon;
    offset += ((size_t) numRefusjon) * sizeof(*refusjon);
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
    varselSlv = (POppfVarselSlv *) (void *) (((uint8_t *) mapping) + offset);
    numVarselSlv = header->numVarselSlv;
    offset += ((size_t) numVarselSlv) * sizeof(*varselSlv);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    byttegruppe = (POppfByttegruppe *) (void *) (((uint8_t *) mapping) + offset);
    numByttegruppe = header->numByttegruppe;
    offset += ((size_t) numByttegruppe) * sizeof(*byttegruppe);
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
    festUuidList = (const PFestId *) (void *) (((uint8_t *) mapping) + offset);
    numFestUuidList = header->numUuidLists;
    offset += ((size_t) numFestUuidList) * sizeof(*festUuidList);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
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
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    elementList = (const PElement *) (void *) (((uint8_t *) mapping) + offset);
    numElement = header->numElement;
    offset += ((size_t) numElement) * sizeof(*elementList);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    refRefusjonsvilkarList = (const PRefRefusjonsvilkar *) (void *) (((uint8_t *) mapping) + offset);
    numRefRefusjonsvilkar = header->numRefRefusjonsvilkar;
    offset += ((size_t) numRefRefusjonsvilkar) * sizeof(*refRefusjonsvilkarList);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    refusjonskodeList = (const PRefusjonskode *) (void *) (((uint8_t *) mapping) + offset);
    numRefusjonskode = header->numRefusjonskode;
    offset += ((size_t) numRefusjonskode) * sizeof(*refusjonskodeList);
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
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    uint16List = (const uint16_t *) (void *) (((uint8_t *) mapping) + offset);
    numUint16List = header->numUint16List;
    offset += ((size_t) numUint16List) * sizeof(*uint16List);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            offset += off;
        }
    }
    fests = (const PFest *) (void *) (((uint8_t *) mapping) + offset);
    numFests = header->numFests;
    offset += ((size_t) numFests) * sizeof(*fests);
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
    if (offset < size) {
        stringblocksize = size - offset;
    } else {
        stringblocksize = 0;
        if (offset > size) {
            std::cerr << "Error: File is truncated\n";
            throw PackException("Truncated file");
        }
    }
}

FestDeserializer::~FestDeserializer() {
    if (mapping != nullptr) {
        munmap(mapping, mapsize);
    }
}

std::vector<POppfLegemiddelMerkevare> FestDeserializer::GetLegemiddelMerkevare() const {
    std::vector<POppfLegemiddelMerkevare> result{};
    ForEachMerkevare([&result] (const auto &oppf) {
        result.emplace_back(oppf);
    });
    return result;
}

std::vector<POppfLegemiddelpakning> FestDeserializer::GetLegemiddelPakning() const {
    std::vector<POppfLegemiddelpakning> result{};
    ForEachPakning([&result] (const auto &oppf) {
        result.emplace_back(oppf);
    });
    return result;
}

std::vector<POppfLegemiddelVirkestoff> FestDeserializer::GetLegemiddelVirkestoff() const {
    std::vector<POppfLegemiddelVirkestoff> result{};
    ForEachLegemiddelVirkestoff([&result] (const auto &oppf) {
        result.emplace_back(oppf);
    });
    return result;
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

std::vector<POppfLegemiddeldose> FestDeserializer::GetLegemiddeldose() const {
    std::vector<POppfLegemiddeldose> result{};
    ForEachLegemiddeldose([&result] (const auto &oppf) {
        result.emplace_back(oppf);
    });
    return result;
}

std::vector<POppfVirkestoffMedStyrke> FestDeserializer::GetVirkestoffMedStyrke() const {
    std::vector<POppfVirkestoffMedStyrke> result{};
    for (std::remove_const<typeof(numVirkestoffMedStyrke)>::type i = 0; i < numVirkestoffMedStyrke; i++) {
        result.emplace_back(this->virkestoffMedStyrke[i]);
    }
    return result;
}

std::vector<POppfVirkestoff> FestDeserializer::GetVirkestoff() const {
    std::vector<POppfVirkestoff> result{};
    for (std::remove_const<typeof(numVirkestoff)>::type i = 0; i < numVirkestoff; i++) {
        result.emplace_back(this->virkestoff[i]);
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
    for (std::remove_const<typeof(numPrisVare)>::type i = 0; i < numPrisVare; i++) {
        prisVare.emplace_back(this->prisVareList[i]);
    }
    return prisVare;
}

std::vector<PPakningsinfo> FestDeserializer::GetPakningsinfo() const {
    std::vector<PPakningsinfo> pakningsinfo{};
    pakningsinfo.reserve(numPakningsinfo);
    for (std::remove_const<typeof(numPakningsinfo)>::type i = 0; i < numPakningsinfo; i++) {
        pakningsinfo.emplace_back(this->pakningsinfoList[i]);
    }
    return pakningsinfo;
}

std::vector<PPakningskomponent> FestDeserializer::GetPakningskomponent() const {
    std::vector<PPakningskomponent> pakningskomponent{};
    pakningskomponent.reserve(numPakningskomponent);
    for (std::remove_const<typeof(numPakningskomponent)>::type i = 0; i < numPakningskomponent; i++) {
        pakningskomponent.emplace_back(this->pakningskomponentList[i]);
    }
    return pakningskomponent;
}

std::vector<PPakningskomponentInfo> FestDeserializer::GetPakningskomponentInfo() const {
    std::vector<PPakningskomponentInfo> pakningskomponentInfo{};
    pakningskomponentInfo.reserve(numPakningskomponentInfo);
    for (std::remove_const<typeof(numPakningskomponentInfo)>::type i = 0; i < numPakningskomponentInfo; i++) {
        pakningskomponentInfo.emplace_back(this->pakningskomponentInfoList[i]);
    }
    return pakningskomponentInfo;
}

std::vector<PReseptgyldighet> FestDeserializer::GetReseptgyldighet() const {
    std::vector<PReseptgyldighet> reseptgyldighet{};
    reseptgyldighet.reserve(numReseptgyldighet);
    for (std::remove_const<typeof(numReseptgyldighet)>::type i = 0; i < numReseptgyldighet; i++) {
        reseptgyldighet.emplace_back(this->reseptgyldighetList[i]);
    }
    return reseptgyldighet;
}

std::vector<PValueWithCodeset> FestDeserializer::GetValueWithCodeset() const {
    std::vector<PValueWithCodeset> valueWithCodeset{};
    valueWithCodeset.reserve(numValueWithCodesetList);
    for (std::remove_const<typeof(numValueWithCodesetList)>::type i = 0; i < numValueWithCodesetList; i++) {
        valueWithCodeset.emplace_back(this->valueWithCodesetList[i]);
    }
    return valueWithCodeset;
}

std::vector<FestUuid> FestDeserializer::GetFestIds() const {
    std::vector<FestUuid> uuids{};
    uuids.reserve(numFestUuid);
    for (std::remove_const<typeof(numFestUuid)>::type i = 0; i < numFestUuid; i++) {
        uuids.emplace_back(festUuid[i]);
    }
    return uuids;
}

std::vector<PFestId> FestDeserializer::GetFestIdLists() const {
    std::vector<PFestId> festIds{};
    festIds.reserve(numFestUuidList);
    for (std::remove_const<typeof(numFestUuidList)>::type i = 0; i < numFestUuidList; i++) {
        festIds.emplace_back(this->festUuidList[i]);
    }
    return festIds;
}

std::vector<PRefusjon> FestDeserializer::GetRefusjon() const {
    std::vector<PRefusjon> refusjon{};
    refusjon.reserve(numRefusjonList);
    for (std::remove_const<typeof(numRefusjonList)>::type i = 0; i < numRefusjonList; i++) {
        refusjon.emplace_back(this->refusjonList[i]);
    }
    return refusjon;
}

std::vector<PElement> FestDeserializer::GetElement() const {
    std::vector<PElement> element{};
    element.reserve(numElement);
    for (std::remove_const<typeof(numElement)>::type i = 0; i < numElement; i++) {
        element.emplace_back(this->elementList[i]);
    }
    return element;
}

std::vector<PRefRefusjonsvilkar> FestDeserializer::GetRefRefusjonsvilkar() const {
    std::vector<PRefRefusjonsvilkar> refRefusjonsvilkar{};
    refRefusjonsvilkar.reserve(numRefRefusjonsvilkar);
    for (std::remove_const<typeof(numRefRefusjonsvilkar)>::type i = 0; i < numRefRefusjonsvilkar; i++) {
        refRefusjonsvilkar.emplace_back(this->refRefusjonsvilkarList[i]);
    }
    return refRefusjonsvilkar;
}

std::vector<PRefusjonskode> FestDeserializer::GetRefusjonskode() const {
    std::vector<PRefusjonskode> refusjonskode{};
    refusjonskode.reserve(numRefusjonskode);
    for (std::remove_const<typeof(numRefusjonskode)>::type i = 0; i < numRefusjonskode; i++) {
        refusjonskode.emplace_back(this->refusjonskodeList[i]);
    }
    return refusjonskode;
}

std::vector<PReferanse> FestDeserializer::GetReferanse() const {
    std::vector<PReferanse> referanse{};
    referanse.reserve(numReferanseList);
    for (std::remove_const<typeof(numReferanseList)>::type i = 0; i < numReferanseList; i++) {
        referanse.emplace_back(this->referanseList[i]);
    }
    return referanse;
}

std::vector<PSubstansgruppe> FestDeserializer::GetSubstansgruppe() const {
    std::vector<PSubstansgruppe> substansgruppe{};
    substansgruppe.reserve(numSubstansgruppeList);
    for (std::remove_const<typeof(numSubstansgruppeList)>::type i = 0; i < numSubstansgruppeList; i++) {
        substansgruppe.emplace_back(this->substansgruppeList[i]);
    }
    return substansgruppe;
}

std::vector<PSubstans> FestDeserializer::GetSubstans() const {
    std::vector<PSubstans> substans{};
    substans.reserve(numSubstansList);
    for (std::remove_const<typeof(numSubstansList)>::type i = 0; i < numSubstansList; i++) {
        substans.emplace_back(this->substansList[i]);
    }
    return substans;
}

std::vector<PDoseFastTidspunkt> FestDeserializer::GetDoseFastTidspunkt() const {
    std::vector<PDoseFastTidspunkt> doseFastTidspunkt{};
    doseFastTidspunkt.reserve(numDoseFastTidspunktList);
    for (std::remove_const<typeof(numDoseFastTidspunktList)>::type i = 0; i < numDoseFastTidspunktList; i++) {
        doseFastTidspunkt.emplace_back(this->doseFastTidspunktList[i]);
    }
    return doseFastTidspunkt;
}

std::vector<PDosering> FestDeserializer::GetDosering() const {
    std::vector<PDosering> dosering{};
    dosering.reserve(numDoseringList);
    for (std::remove_const<typeof(numDoseringList)>::type i = 0; i < numDoseringList; i++) {
        dosering.emplace_back(this->doseringList[0]);
    }
    return dosering;
}

std::vector<PLegemiddelforbruk> FestDeserializer::GetLegemiddelforbruk() const {
    std::vector<PLegemiddelforbruk> legemiddelforbruk{};
    legemiddelforbruk.reserve(numLegemiddelforbrukList);
    for (std::remove_const<typeof(numLegemiddelforbrukList)>::type i = 0; i < numLegemiddelforbrukList; i++) {
        legemiddelforbruk.emplace_back(this->legemiddelforbrukList[i]);
    }
    return legemiddelforbruk;
}

std::vector<PString> FestDeserializer::GetStringList() const {
    std::vector<PString> strings{};
    strings.reserve(numStringList);
    for (std::remove_const<typeof(numStringList)>::type i = 0; i < numStringList; i++) {
        strings.emplace_back(this->stringList[i]);
    }
    return strings;
}

void FestDeserializer::ForEachMerkevare(const std::function<void(const POppfLegemiddelMerkevare &)> &func) const {
    for (std::remove_const<typeof(numMerkevare)>::type i = 0; i < numMerkevare; i++) {
        func(this->merkevare[i]);
    }
}

void FestDeserializer::ForEachPakning(const std::function<void(const POppfLegemiddelpakning &)> &func) const {
    for (std::remove_const<typeof(numPakning)>::type i = 0; i < numPakning; i++) {
        func(this->pakning[i]);
    }
}

void FestDeserializer::ForEachLegemiddelVirkestoff(const std::function<void(const POppfLegemiddelVirkestoff &)> &func) const {
    for (std::remove_const<typeof(numLegemiddelVirkestoff)>::type i = 0; i < numLegemiddelVirkestoff; i++) {
        func(this->legemiddelVirkestoff[i]);
    }
}

void FestDeserializer::ForEachMedForbrMatr(const std::function<void(const POppfMedForbrMatr &)> &func) const {
    for (std::remove_const<typeof(numMedForbrMatr)>::type i = 0; i < numMedForbrMatr; i++) {
        func(this->medForbrMatr[i]);
    }
}

void FestDeserializer::ForEachNaringsmiddel(const std::function<void(const POppfNaringsmiddel &)> &func) const {
    for (std::remove_const<typeof(numNaringsmiddel)>::type i = 0; i < numNaringsmiddel; i++) {
        func(this->naringsmiddel[i]);
    }
}

void FestDeserializer::ForEachBrystprotese(const std::function<void(const POppfBrystprotese &)> &func) const {
    for (std::remove_const<typeof(numBrystprotese)>::type i = 0; i < numBrystprotese; i++) {
        func(this->brystprotese[i]);
    }
}

void FestDeserializer::ForEachLegemiddeldose(const std::function<void(const POppfLegemiddeldose &)> &func) const {
    for (std::remove_const<typeof(numLegemiddeldose)>::type i = 0; i < numLegemiddeldose; i++) {
        func(this->legemiddeldose[i]);
    }
}

void FestDeserializer::ForEachVirkestoffMedStyrke(const std::function<void(const POppfVirkestoffMedStyrke &)> &func) const {
    for (std::remove_const<typeof(numVirkestoffMedStyrke)>::type i = 0; i < numVirkestoffMedStyrke; i++) {
        func(this->virkestoffMedStyrke[i]);
    }
}

void FestDeserializer::ForEachVirkestoff(const std::function<void(const POppfVirkestoff &)> &func) const {
    for (std::remove_const<typeof(numVirkestoff)>::type i = 0; i < numVirkestoff; i++) {
        func(this->virkestoff[i]);
    }
}

void FestDeserializer::ForEachKodeverk(const std::function<void(const POppfKodeverk &)> &func) const {
    for (std::remove_const<typeof(numKodeverk)>::type i = 0; i < numKodeverk; i++) {
        func(this->kodeverk[i]);
    }
}

void FestDeserializer::ForEachRefusjon(const std::function<void(const POppfRefusjon &)> &func) const {
    for (std::remove_const<typeof(numRefusjon)>::type i = 0; i < numRefusjon; i++) {
        func(this->refusjon[i]);
    }
}

void FestDeserializer::ForEachVilkar(const std::function<void(const POppfVilkar &)> &func) const {
    for (std::remove_const<typeof(numVilkar)>::type i = 0; i < numVilkar; i++) {
        func(this->vilkar[i]);
    }
}

void FestDeserializer::ForEachVarselSlv(const std::function<void(const POppfVarselSlv &)> &func) const {
    for (std::remove_const<typeof(numVarselSlv)>::type i = 0; i < numVarselSlv; i++) {
        func(this->varselSlv[i]);
    }
}

void FestDeserializer::ForEachByttegruppe(const std::function<void(const POppfByttegruppe &)> &func) const {
    for (std::remove_const<typeof(numByttegruppe)>::type i = 0; i < numByttegruppe; i++) {
        func(this->byttegruppe[i]);
    }
}

void FestDeserializer::ForEachInteraksjon(const std::function<void(const POppfInteraksjon &)> &func) const {
    for (std::remove_const<typeof(numInteraksjon)>::type i = 0; i < numInteraksjon; i++) {
        func(this->interaksjon[i]);
    }
}

void FestDeserializer::ForEachInteraksjonIkkeVurdert(const std::function<void(const POppfInteraksjonIkkeVurdert &)> &func) const {
    for (std::remove_const<typeof(numInteraksjonIkkeVurdert)>::type i = 0; i < numInteraksjonIkkeVurdert; i++) {
        func(this->interaksjonIkkeVurdert[i]);
    }
}

void FestDeserializer::ForEachStrDosering(const std::function<void(const POppfStrDosering &)> &func) const {
    for (std::remove_const<typeof(numStrDosering)>::type i = 0; i < numStrDosering; i++) {
        func(this->strDosering[i]);
    }
}

void FestDeserializer::ForEachFests(const std::function<void(const PFest &)> &func) const {
    for (std::remove_const<typeof(numFests)>::type i = 0; i < numFests; i++) {
        func(this->fests[i]);
    }
}

FestVectors FestDeserializer::Unpack(const PFest &pFest) const {
    return {pFest, Unpack(pFest.dato), uint16List, numUint16List};
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

OppfLegemiddelMerkevare FestDeserializer::Unpack(const POppfLegemiddelMerkevare &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<PLegemiddelMerkevare>(poppf))};
}

OppfLegemiddelpakning FestDeserializer::Unpack(const POppfLegemiddelpakning &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<PLegemiddelpakning>(poppf))};
}

OppfLegemiddelVirkestoff FestDeserializer::Unpack(const POppfLegemiddelVirkestoff &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<const PLegemiddelVirkestoff>(poppf))};
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

OppfLegemiddeldose FestDeserializer::Unpack(const POppfLegemiddeldose &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<const PLegemiddeldose>(poppf))};
}

OppfVirkestoffMedStyrke FestDeserializer::Unpack(const POppfVirkestoffMedStyrke &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<const PVirkestoffMedStyrke>(poppf))};
}

OppfVirkestoff FestDeserializer::Unpack(const POppfVirkestoff &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<const PVirkestoff>(poppf))};
}

OppfKodeverk FestDeserializer::Unpack(const POppfKodeverk &poppf) const {
    std::vector<Element> element{};
    {
        auto list = Unpack(elementList, numElement, poppf.elements);
        for (const auto &item : list) {
            element.emplace_back(Unpack(item));
        }
    }
    return {Unpack(static_cast<POppf>(poppf)), Unpack(static_cast<PInfo>(poppf)), element};
}

OppfRefusjon FestDeserializer::Unpack(const POppfRefusjon &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<const PRefusjonshjemmel>(poppf))};
}

OppfVilkar FestDeserializer::Unpack(const POppfVilkar &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<const PVilkar>(poppf))};
}

OppfVarselSlv FestDeserializer::Unpack(const POppfVarselSlv &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<const PVarselSlv>(poppf))};
}

OppfByttegruppe FestDeserializer::Unpack(const POppfByttegruppe &poppf) const {
    return {Unpack(static_cast<const POppf>(poppf)), Unpack(static_cast<const PByttegruppe>(poppf))};
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

LegemiddelMerkevare FestDeserializer::Unpack(const PLegemiddelMerkevare &pmerkevare) const {
    std::vector<Reseptgyldighet> reseptgyldighet{};
    {
        auto rg = Unpack(reseptgyldighetList, numReseptgyldighet, pmerkevare.reseptgyldighet);
        for (const auto &r : rg) {
            reseptgyldighet.push_back(Unpack(r));
        }
    }
    std::vector<std::string> sortertVirkestoffUtenStyrke{};
    {
        auto sv = Unpack(festUuidList, numFestUuidList, pmerkevare.sortertVirkestoffUtenStyrke);
        for (const auto &v : sv) {
            sortertVirkestoffUtenStyrke.push_back(Unpack(v).ToString());
        }
    }
    return {
        Unpack(static_cast<PLegemiddel>(pmerkevare)),
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

Legemiddelpakning FestDeserializer::Unpack(const PLegemiddelpakning &ppakning) const {
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
            Unpack(static_cast<PLegemiddelCore>(ppakning)),
            {Unpack(ppakning.preparattype)},
            Unpack(ppakning.id).ToString(),
            Unpack(ppakning.varenr),
            {Unpack(ppakning.oppbevaring)},
            pakningsinfo,
            Unpack(ppakning.markedsforingsinfo),
            Unpack(ppakning.ean),
            prisVare,
            Unpack(ppakning.refusjon),
            Unpack(ppakning.pakningByttegruppe),
            Unpack(ppakning.preparatomtaleavsnitt),
            ppakning.ikkeKonservering
    };
}

LegemiddelVirkestoff FestDeserializer::Unpack(const PLegemiddelVirkestoff &pvirkestoff) const {
    std::vector<Refusjon> refusjon{};
    {
        auto list = Unpack(this->refusjonList, numRefusjonList, pvirkestoff.refusjon);
        for (const auto &item : list) {
            refusjon.emplace_back(Unpack(item));
        }
    }
    std::vector<std::string> refLegemiddelMerkevare{};
    {
        auto list = Unpack(festUuidList, numFestUuidList, pvirkestoff.refLegemiddelMerkevare);
        for (const auto &id : list) {
            refLegemiddelMerkevare.emplace_back(Unpack(id).ToString());
        }
    }
    std::vector<std::string> refPakning{};
    {
        auto list = Unpack(festUuidList, numFestUuidList, pvirkestoff.refPakning);
        for (const auto &id : list) {
            refPakning.emplace_back(Unpack(id).ToString());
        }
    }
    return {
        Unpack(static_cast<PLegemiddel>(pvirkestoff)),
        Unpack(pvirkestoff.id).ToString(),
        refusjon,
        refLegemiddelMerkevare,
        refPakning,
        {Unpack(pvirkestoff.forskrivningsenhetResept)}
    };
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

Legemiddeldose FestDeserializer::Unpack(const PLegemiddeldose &pLegemiddeldose) const {
    std::vector<std::string> refLegemiddelMerkevare{};
    {
        auto list = Unpack(festUuidList, numFestUuidList, pLegemiddeldose.refLegemiddelMerkevare);
        for (const auto &pid : list) {
            refLegemiddelMerkevare.emplace_back(Unpack(pid).ToString());
        }
    }
    std::vector<std::string> refPakning{};
    {
        auto list = Unpack(festUuidList, numFestUuidList, pLegemiddeldose.refPakning);
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
        Unpack(static_cast<PLegemiddelCore>(pLegemiddeldose)),
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

Virkestoff FestDeserializer::Unpack(const PVirkestoff &pVirkestoff) const {
    std::vector<std::string> refVirkestoff{};
    {
        auto list = Unpack(festUuidList, numFestUuidList, pVirkestoff.refVirkestoff);
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

Info FestDeserializer::Unpack(const PInfo &pInfo) const {
    return {
        Unpack(pInfo.id),
        Unpack(pInfo.betegnelse),
        Unpack(pInfo.kortnavn),
        Unpack(pInfo.ansvarligUtgiver)
    };
}

Refusjonshjemmel FestDeserializer::Unpack(const PRefusjonshjemmel &pRefusjonshjemmel) const {
    return {
        Unpack(pRefusjonshjemmel.refusjonshjemmel),
        pRefusjonshjemmel.kreverVarekobling,
        pRefusjonshjemmel.kreverVedtak,
        Unpack(static_cast<const PRefusjonsgruppe>(pRefusjonshjemmel))
    };
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

VarselSlv FestDeserializer::Unpack(const PVarselSlv &pVarselSlv) const {
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

Byttegruppe FestDeserializer::Unpack(const PByttegruppe &pByttegruppe) const {
    return {
        Unpack(pByttegruppe.id).ToString(),
        Unpack(pByttegruppe.kode),
        Unpack(pByttegruppe.gyldigFraDato),
        Unpack(pByttegruppe.beskrivelseByttbarhet),
        pByttegruppe.merknadTilByttbarhet
    };
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

Legemiddel FestDeserializer::Unpack(const PLegemiddel &pLegemiddel) const {
    std::vector<std::string> sortertVirkestoffMedStyrke{};
    {
        auto sv = Unpack(festUuidList, numFestUuidList, pLegemiddel.sortertVirkestoffMedStyrke);
        for (const auto &v : sv) {
            sortertVirkestoffMedStyrke.push_back(Unpack(v).ToString());
        }
    }
    return {
        Unpack(static_cast<PLegemiddelCore>(pLegemiddel)),
        Unpack(pLegemiddel.administreringLegemiddel),
        sortertVirkestoffMedStyrke
    };
}


LegemiddelCore FestDeserializer::Unpack(const PLegemiddelCore &pLegemiddelCore) const {
    std::vector<std::string> refVilkar{};
    {
        auto rv = Unpack(festUuidList, numFestUuidList, pLegemiddelCore.refVilkar);
        for (const auto &v : rv) {
            refVilkar.push_back(Unpack(v).ToString());
        }
    }
    return {{Unpack(pLegemiddelCore.atc)}, Unpack(pLegemiddelCore.navnFormStyrke),
            {Unpack(pLegemiddelCore.reseptgruppe)}, {Unpack(pLegemiddelCore.legemiddelformKort)},
            refVilkar, {Unpack(pLegemiddelCore.typeSoknadSlv)}, FromRaw(pLegemiddelCore.opioidsoknad),
            {Unpack(pLegemiddelCore.svartTrekant)}};
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

Element FestDeserializer::Unpack(const PElement &pElement) const {
    return {
        Unpack(pElement.id),
        Unpack(pElement.kode),
        Unpack(static_cast<PTerm>(pElement))
    };
}

Term FestDeserializer::Unpack(const PTerm &pTerm) const {
   return {
       Unpack(pTerm.term),
       Unpack(pTerm.beskrivelseTerm),
       {Unpack(pTerm.sprak)}
   };
}

RefRefusjonsvilkar FestDeserializer::Unpack(const PRefRefusjonsvilkar &pref) const {
    return {
        Unpack(pref.id).ToString(),
        Unpack(pref.fraDato)
    };
}

Refusjonskode FestDeserializer::Unpack(const PRefusjonskode &pref) const {
    std::vector<std::string> underterm{};
    {
        auto list = Unpack(stringList, numStringList, pref.underterm);
        for (const auto &put : list) {
            underterm.emplace_back(Unpack(put));
        }
    }
    std::vector<RefRefusjonsvilkar> refusjonsvilkar{};
    {
        auto list = Unpack(refRefusjonsvilkarList, numRefRefusjonsvilkar, pref.refusjonsvilkar);
        for (const auto &pr : list) {
            refusjonsvilkar.emplace_back(Unpack(pr));
        }
    }
    return {
        Unpack(pref.refusjonskode),
        Unpack(pref.gyldigFraDato),
        Unpack(pref.forskrivesTilDato),
        underterm,
        refusjonsvilkar
    };
}

Refusjonsgruppe FestDeserializer::Unpack(const PRefusjonsgruppe &pRefusjonsgruppe) const {
    std::vector<Refusjonskode> refusjonskode{};
    {
        auto list = Unpack(refusjonskodeList, numRefusjonskode, pRefusjonsgruppe.refusjonskode);
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

Referanseelement FestDeserializer::Unpack(const PReferanseelement &pReferanseelement) const {
    std::vector<std::string> refs{};
    {
        auto list = Unpack(festUuidList, numFestUuidList, pReferanseelement.refs);
        for (const auto &item : list) {
            refs.emplace_back(Unpack(item).ToString());
        }
    }
    return {
        Unpack(pReferanseelement.klasse),
        refs
    };
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
        auto list = Unpack(doseFastTidspunktList, numDoseFastTidspunktList, static_cast<const GenericListItems>(pDosering));
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

std::vector<PPakningsinfo> FestDeserializer::GetPakningsinfoList(const PLegemiddelpakning &ppakning) const {
    return Unpack(pakningsinfoList, numPakningsinfo, ppakning.pakningsinfo);
}

std::vector<FestUuid> FestDeserializer::GetFestUuids(const GenericListItems &items) const {
    std::vector<FestUuid> ids{};
    {
        auto pf = Unpack(festUuidList, numFestUuidList, items);
        for (const auto &pid : pf) {
            ids.emplace_back(Unpack(pid));
        }
    }
    return ids;
}
