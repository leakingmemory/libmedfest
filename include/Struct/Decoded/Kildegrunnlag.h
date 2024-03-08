//
// Created by sigsegv on 12/30/22.
//

#ifndef LEGEMFEST_KILDEGRUNNLAG_H
#define LEGEMFEST_KILDEGRUNNLAG_H

#include "ValueWithDistinguishedName.h"

class Kildegrunnlag : public ValueWithDistinguishedName {
public:
    Kildegrunnlag() : ValueWithDistinguishedName() {}
    Kildegrunnlag(const ValueWithDistinguishedName &valueWithDistinguishedName) : ValueWithDistinguishedName(valueWithDistinguishedName) {}
};

#endif //LEGEMFEST_KILDEGRUNNLAG_H
