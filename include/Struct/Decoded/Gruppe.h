//
// Created by sigsegv on 12/26/22.
//

#ifndef LEGEMFEST_GRUPPE_H
#define LEGEMFEST_GRUPPE_H

#include "ValueWithCodeSet.h"

class Gruppe : public ValueWithCodeSet {
public:
    Gruppe() : ValueWithCodeSet() {}
    Gruppe(const ValueWithCodeSet &valueWithCodeSet) : ValueWithCodeSet(valueWithCodeSet) {}
};

#endif //LEGEMFEST_GRUPPE_H
