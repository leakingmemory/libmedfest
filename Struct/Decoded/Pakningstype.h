//
// Created by sigsegv on 12/12/22.
//

#ifndef LEGEMFEST_PAKNINGSTYPE_H
#define LEGEMFEST_PAKNINGSTYPE_H

#include "ValueWithCodeSet.h"

class Pakningstype : public ValueWithCodeSet {
public:
    Pakningstype() : ValueWithCodeSet() {}
    Pakningstype(const ValueWithCodeSet &valueWithCodeSet) : ValueWithCodeSet(valueWithCodeSet) {}
};

#endif //LEGEMFEST_PAKNINGSTYPE_H
