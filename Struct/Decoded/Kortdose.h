//
// Created by sigsegv on 12/11/22.
//

#ifndef LEGEMFEST_KORTDOSE_H
#define LEGEMFEST_KORTDOSE_H

#include "ValueWithCodeSet.h"

class Kortdose : public ValueWithCodeSet {
public:
    Kortdose() : ValueWithCodeSet() {}
    Kortdose(const ValueWithCodeSet &valueWithCodeSet) : ValueWithCodeSet(valueWithCodeSet) {}
};

#endif //LEGEMFEST_KORTDOSE_H
