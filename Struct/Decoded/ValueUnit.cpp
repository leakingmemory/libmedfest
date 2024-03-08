//
// Created by sigsegv on 12/12/22.
//

#include <Struct/Decoded/ValueUnit.h>

double ValueUnit::GetValue() const {
    return value;
}

std::string ValueUnit::GetUnit() const {
    return unit;
}