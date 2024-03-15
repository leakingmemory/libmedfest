//
// Created by sigsegv on 12/10/22.
//

#ifndef LEGEMFEST_MAYBEBOOLEAN_H
#define LEGEMFEST_MAYBEBOOLEAN_H

#include <cstdint>

enum class MaybeBoolean {
    MFALSE = 0,
    MTRUE = 1,
    UNSPECIFIED = -1
};

constexpr uint8_t ToRaw(MaybeBoolean maybeBoolean) {
    if (maybeBoolean == MaybeBoolean::MFALSE) {
        return 0;
    } else if (maybeBoolean == MaybeBoolean::MTRUE) {
        return 1;
    } else {
        return 3;
    }
}

constexpr MaybeBoolean FromRaw(uint8_t raw) {
    switch (raw) {
        case 0:
            return MaybeBoolean::MFALSE;
        case 1:
            return MaybeBoolean::MTRUE;
        default:
            return MaybeBoolean::UNSPECIFIED;
    }
}

#endif