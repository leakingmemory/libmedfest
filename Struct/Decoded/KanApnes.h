//
// Created by sigsegv on 12/11/22.
//

#ifndef LEGEMFEST_KANAPNES_H
#define LEGEMFEST_KANAPNES_H

#include "ValueWithDistinguishedName.h"

class KanApnes : public ValueWithDistinguishedName {
public:
    KanApnes() : ValueWithDistinguishedName() {}
    KanApnes(const ValueWithDistinguishedName &valueWithDistinguishedName) : ValueWithDistinguishedName(valueWithDistinguishedName) {}
};

#endif //LEGEMFEST_KANAPNES_H
