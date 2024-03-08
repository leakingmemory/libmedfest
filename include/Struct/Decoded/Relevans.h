//
// Created by sigsegv on 12/29/22.
//

#ifndef LEGEMFEST_RELEVANS_H
#define LEGEMFEST_RELEVANS_H

#include "ValueWithDistinguishedName.h"

class Relevans : public ValueWithDistinguishedName {
public:
    Relevans() : ValueWithDistinguishedName() {}
    Relevans(const ValueWithDistinguishedName &valueWithDistinguishedName) : ValueWithDistinguishedName(valueWithDistinguishedName) {}
};

#endif //LEGEMFEST_RELEVANS_H
