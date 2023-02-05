//
// Created by sigsegv on 1/2/23.
//

#include "PackException.h"

const char *PackException::what() const noexcept {
    return message != nullptr ? message : "Packing error";
}