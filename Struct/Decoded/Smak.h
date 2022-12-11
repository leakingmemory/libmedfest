//
// Created by sigsegv on 12/11/22.
//

#ifndef LEGEMFEST_SMAK_H
#define LEGEMFEST_SMAK_H

#include "ValueWithDistinguishedName.h"

class Smak : public ValueWithDistinguishedName {
public:
    Smak() : ValueWithDistinguishedName() {}
    Smak(const ValueWithDistinguishedName &valueWithDistinguishedName) : ValueWithDistinguishedName(valueWithDistinguishedName) {}
};

#endif //LEGEMFEST_SMAK_H
