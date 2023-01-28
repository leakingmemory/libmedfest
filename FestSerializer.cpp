//
// Created by sigsegv on 1/9/23.
//

#include "FestSerializer.h"
#include "Struct/Packed/PackException.h"
#include <iostream>

FestSerializer::FestSerializer(std::shared_ptr<Fest> fest, const std::string &filename)
: fest(fest), output(filename, std::ios::binary | std::ios::out | std::ios::trunc) {
}

bool FestSerializer::Serialize() {
    if (!is_open()) {
        std::cerr << "Error: Output file is not opened, or writeable\n";
        return false;
    }
    return fest->Accept(*this);
}

bool FestSerializer::Write() {
    char alignmentBlock[alignment] = {};
    if (festidblock.size() >= (1 << 24)) {
        throw PackException("Max size fest-id-block");
    }
    if (reseptgyldighetList.size() >= (1 << 8)) {
        throw PackException("Max size reseptgyldighet-list");
    }
    if (legemiddelMerkevare.size() >= (1 << 16)) {
        throw PackException("Max size merkevare-list");
    }
    if (valueWithCodesetList.size() >= (1 << 16)) {
        throw PackException("Max vc-list");
    }
    if (pakningskomponentList.size() >= (1 << 16)) {
        throw PackException("Max pakningskomponent-list");
    }
    if (pakningsinfoList.size() >= (1 << 16)) {
        throw PackException("Max pakningsinfo-list");
    }
    if (prisVareList.size() >= (1 << 16)) {
        throw PackException("Max pris-vare-list");
    }
    if (festUuidList.size() >= (1 << 16)) {
        throw PackException("Max size uuid-list-list");
    }
    if (legemiddelpakning.size() >= (1 << 16)) {
        throw PackException("Max size legemiddelpakning");
    }
    if (refusjonList.size() >= (1 << 16)) {
        throw PackException("Max size refusjon-list");
    }
    if (legemiddelVirkestoff.size() >= (1 << 16)) {
        throw PackException("Max size legemiddel-virkestoff");
    }
    FestFirstHeader firstHeader{
        .numUuids = (uint32_t) festidblock.size(),
        .numReseptgyldighet = (uint8_t) reseptgyldighetList.size(),
        .numLegemiddelMerkevare = (uint16_t) legemiddelMerkevare.size(),
        .numValueCodeset = (uint16_t) valueWithCodesetList.size(),
        .numPakningskomponent = (uint16_t) pakningskomponentList.size(),
        .numPakningsinfo = (uint16_t) pakningsinfoList.size(),
        .numPrisVare = (uint16_t) prisVareList.size(),
        .numUuidLists = (uint16_t) festUuidList.size(),
        .numPakning = (uint16_t) legemiddelpakning.size(),
        .numRefusjon = (uint16_t) refusjonList.size(),
        .numLegemiddelVirkestoff = (uint16_t) legemiddelVirkestoff.size()
    };
    size_t offset = sizeof(firstHeader);
    output.write((char *) (void *) &firstHeader, offset);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output.write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto *ptr = legemiddelMerkevare.data();
        auto size = legemiddelMerkevare.size() * sizeof(*ptr);
        output.write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output.write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto *ptr = legemiddelpakning.data();
        auto size = legemiddelpakning.size() * sizeof(*ptr);
        output.write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output.write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto *ptr = legemiddelVirkestoff.data();
        auto size = legemiddelVirkestoff.size() * sizeof(*ptr);
        output.write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output.write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto *ptr = festidblock.data();
        auto size = festidblock.size() * sizeof(*ptr);
        output.write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output.write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = festUuidList.GetStorageBlock();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output.write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output.write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = valueWithCodesetList.GetStorageBlock();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output.write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output.write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = reseptgyldighetList.GetStorageList();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output.write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output.write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = pakningskomponentList.GetStorageList();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output.write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output.write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = pakningsinfoList.GetStorageList();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output.write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output.write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = prisVareList.GetStorageList();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output.write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output.write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = refusjonList.GetStorageList();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output.write((char *) (void *) ptr, size);
        offset += size;
    }
    output.write(stringblock.c_str(), stringblock.size());
    output.close();
    return true;
}

bool FestSerializer::Visit(const OppfLegemiddelMerkevare &merkevare) {
    this->legemiddelMerkevare.emplace_back(merkevare, stringblock, festidblock, festUuidList, valueWithCodesetList, reseptgyldighetList);
    return true;
}

bool FestSerializer::Visit(const OppfLegemiddelpakning &pakning) {
    this->legemiddelpakning.emplace_back(pakning, pakningskomponentList, pakningsinfoList, prisVareList, festUuidList, festidblock, stringblock);
    return true;
}

bool FestSerializer::Visit(const OppfLegemiddelVirkestoff &virkestoff) {
    this->legemiddelVirkestoff.emplace_back(virkestoff, stringblock, festidblock, festUuidList, valueWithCodesetList, refusjonList);
    return true;
}
