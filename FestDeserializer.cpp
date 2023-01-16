//
// Created by sigsegv on 1/13/23.
//

#include "FestDeserializer.h"
#include "FestSerializer.h"
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
        return;
    }
    auto size = lseek(fd, 0, SEEK_END);
    if (lseek(fd, 0, SEEK_SET) != 0) {
        std::cerr << "Error: Seek start: " << strerror(errno) << "\n";
        if (close(fd) != 0) {
            std::cerr << "Error: Close file: " << strerror(errno )<< "\n";
        }
        return;
    }
    mapsize = size;
    mapping = mmap(nullptr, size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (mapping == MAP_FAILED) {
        std::cerr << "Error: Map failed: " << strerror(errno) << "\n";
        mapping = nullptr;
        return;
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
    stringblock = (const char *) (void *) (((uint8_t *) mapping) + offset);
    if (offset < size) {
        stringblocksize = size - offset;
    } else {
        stringblocksize = 0;
    }
}

FestDeserializer::~FestDeserializer() {
    if (mapping != nullptr) {
        munmap(mapping, mapsize);
    }
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

FestUuid FestDeserializer::Unpack(PFestId festId) const {
    if (festId.id >= 0 && festId.id < numFestUuid) {
        return this->festUuid[festId.id];
    } else {
        return {};
    }
}
