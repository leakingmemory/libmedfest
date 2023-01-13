//
// Created by sigsegv on 12/10/22.
//

#ifndef LEGEMFEST_MAYBEBOOLEAN_H
#define LEGEMFEST_MAYBEBOOLEAN_H

enum class MaybeBoolean {
    FALSE = 0,
    TRUE = 1,
    UNSPECIFIED = -1
};

constexpr uint8_t ToRaw(MaybeBoolean maybeBoolean) {
    if (maybeBoolean == MaybeBoolean::FALSE) {
        return 0;
    } else if (maybeBoolean == MaybeBoolean::TRUE) {
        return 1;
    } else {
        return 3;
    }
}

constexpr MaybeBoolean FromRaw(uint8_t raw) {
    switch (raw) {
        case 0:
            return MaybeBoolean::FALSE;
        case 1:
            return MaybeBoolean::TRUE;
        default:
            return MaybeBoolean::UNSPECIFIED;
    }
}

#endif