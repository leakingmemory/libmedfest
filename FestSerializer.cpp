//
// Created by sigsegv on 1/9/23.
//

#include "FestSerializer.h"
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
    FestFirstHeader firstHeader{
        .numUuids = (uint32_t) festidblock.size(),
        .numReseptgyldighet = (uint8_t) reseptgyldighetList.size(),
        .numLegemiddelMerkevare = (uint16_t) legemiddelMerkevare.size(),
        .numValueCodeset = (uint16_t) valueWithCodesetList.size(),
        .numUuidLists = (uint32_t) festUuidList.size()
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
        //offset += size;
    }
    output.write(stringblock.c_str(), stringblock.size());
    output.close();
    return true;
}

bool FestSerializer::Visit(const OppfLegemiddelMerkevare &merkevare) {
    this->legemiddelMerkevare.emplace_back(merkevare, stringblock, festidblock, festUuidList, valueWithCodesetList, reseptgyldighetList);
    return true;
}
