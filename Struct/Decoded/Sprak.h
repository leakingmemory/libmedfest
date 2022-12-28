//
// Created by sigsegv on 12/28/22.
//

#ifndef LEGEMFEST_SPRAK_H
#define LEGEMFEST_SPRAK_H

#include "ValueWithDistinguishedName.h"

class Sprak : public ValueWithDistinguishedName {
public:
    Sprak() : ValueWithDistinguishedName() {}
    Sprak(const ValueWithDistinguishedName &sprak) : ValueWithDistinguishedName(sprak) {}
};

#endif //LEGEMFEST_SPRAK_H
