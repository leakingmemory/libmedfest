//
// Created by sigsegv on 12/9/22.
//

#ifndef LEGEMFEST_TYPESOKNADSLV_H
#define LEGEMFEST_TYPESOKNADSLV_H

#include "ValueWithDistinguishedName.h"

class TypeSoknadSlv : public ValueWithDistinguishedName {
public:
    TypeSoknadSlv() : ValueWithDistinguishedName() {}
    TypeSoknadSlv(const ValueWithDistinguishedName &valueWithDistinguishedName) : ValueWithDistinguishedName(valueWithDistinguishedName) {}
};

#endif //LEGEMFEST_TYPESOKNADSLV_H
