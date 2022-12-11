//
// Created by sigsegv on 12/11/22.
//

#ifndef LEGEMFEST_VAKSINESTANDARD_H
#define LEGEMFEST_VAKSINESTANDARD_H

#include "ValueWithCodeSet.h"

class Vaksinestandard : public ValueWithCodeSet {
public:
    Vaksinestandard() : ValueWithCodeSet() {}
    Vaksinestandard(const ValueWithCodeSet &valueWithCodeSet) : ValueWithCodeSet(valueWithCodeSet) {}
};

#endif //LEGEMFEST_VAKSINESTANDARD_H
