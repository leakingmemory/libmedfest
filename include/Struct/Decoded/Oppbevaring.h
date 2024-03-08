//
// Created by sigsegv on 12/12/22.
//

#ifndef LEGEMFEST_OPPBEVARING_H
#define LEGEMFEST_OPPBEVARING_H

#include "ValueWithDistinguishedName.h"

class Oppbevaring : public ValueWithDistinguishedName {
public:
    Oppbevaring() : ValueWithDistinguishedName() {}
    Oppbevaring(const ValueWithDistinguishedName &valueWithDistinguishedName) : ValueWithDistinguishedName(valueWithDistinguishedName) {}
};

#endif //LEGEMFEST_OPPBEVARING_H
