//
// Created by sigsegv on 12/11/22.
//

#ifndef LEGEMFEST_DELING_H
#define LEGEMFEST_DELING_H

#include "ValueWithDistinguishedName.h"

class Deling : public ValueWithDistinguishedName {
public:
    Deling() : ValueWithDistinguishedName() {}
    Deling(const ValueWithDistinguishedName &valueWithDistinguishedName) : ValueWithDistinguishedName(valueWithDistinguishedName) {}
};

#endif //LEGEMFEST_DELING_H
