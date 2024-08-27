//
// Created by sigsegv on 2/19/23.
//

#ifndef LEGEMFEST_DBVERSION_H
#define LEGEMFEST_DBVERSION_H

#include <cstdint>

constexpr uint64_t magicConst  = 0xFE5700000025;
constexpr uint64_t versionMask = 0x0000FFFFFF00;

constexpr uint64_t GetMagicNumbber(uint8_t major = 1, uint8_t minor = 2, uint8_t patch = 0) {
    uint64_t majorConst{((uint64_t) major) << 24};
    uint64_t minorConst{((uint64_t) minor) << 16};
    uint64_t patchConst{((uint64_t) patch) << 8};
    return magicConst | majorConst | minorConst | patchConst;
}

struct DbVersion {
    uint8_t major;
    uint8_t minor;
    uint8_t patch;
    bool valid : 1;
};
static_assert(sizeof(DbVersion) == 4);

constexpr DbVersion GetDbVersion(uint64_t magic) {
    if ((magic & (~versionMask)) != magicConst) {
        return {
                .major = 0,
                .minor = 0,
                .patch = 0,
                .valid = false
        };
    }
    uint64_t versions{(magic & versionMask) >> 8};
    return {
            .major = (uint8_t) ((versions >> 16) & 0xFF),
            .minor = (uint8_t) ((versions >> 8) & 0xFF),
            .patch = (uint8_t) (versions & 0xFF),
            .valid = true
    };
}

#endif //LEGEMFEST_DBVERSION_H
