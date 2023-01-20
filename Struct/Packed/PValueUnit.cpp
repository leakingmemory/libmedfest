//
// Created by sigsegv on 1/18/23.
//

#include "PValueUnit.h"
#include "../Decoded/ValueUnit.h"

PValueUnit::PValueUnit(const ValueUnit &vu, std::string &strblock) :
        value(vu.GetValue()),
        unit(vu.GetUnit(), strblock) {
}

bool PValueUnit::operator==(const PValueUnit &other) const {
    return value == other.value && unit == other.unit;
}