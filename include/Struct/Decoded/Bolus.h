//
// Created by sigsegv on 12/11/22.
//

#ifndef LEGEMFEST_BOLUS_H
#define LEGEMFEST_BOLUS_H

#include "ValueWithDistinguishedName.h"

class Bolus : public ValueWithDistinguishedName {
public:
    Bolus() : ValueWithDistinguishedName() {}
    Bolus(const ValueWithDistinguishedName &valueWithDistinguishedName) : ValueWithDistinguishedName(valueWithDistinguishedName) {}
};

#endif //LEGEMFEST_BOLUS_H
