//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_PREPARATTYPE_H
#define LEGEMFEST_PREPARATTYPE_H

#include "ValueWithDistinguishedName.h"

class Preparattype : public ValueWithDistinguishedName {
public:
    Preparattype() : ValueWithDistinguishedName() {}
    Preparattype(const ValueWithDistinguishedName &valueWithDistinguishedName) : ValueWithDistinguishedName(valueWithDistinguishedName) {}
};

#endif //LEGEMFEST_PREPARATTYPE_H
