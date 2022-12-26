//
// Created by sigsegv on 12/26/22.
//

#ifndef LEGEMFEST_GJELDERFOR_H
#define LEGEMFEST_GJELDERFOR_H

#include "ValueWithDistinguishedName.h"

class GjelderFor : public ValueWithDistinguishedName {
public:
    GjelderFor() : ValueWithDistinguishedName() {}
    GjelderFor(const ValueWithDistinguishedName &valueWithDistinguishedName) : ValueWithDistinguishedName(valueWithDistinguishedName) {}
};

#endif //LEGEMFEST_GJELDERFOR_H
