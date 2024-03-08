//
// Created by sigsegv on 12/17/22.
//

#ifndef LEGEMFEST_STYRKEOPERATOR_H
#define LEGEMFEST_STYRKEOPERATOR_H

#include "ValueWithCodeSet.h"

class Styrkeoperator : public ValueWithCodeSet {
public:
    Styrkeoperator() : ValueWithCodeSet() {}
    Styrkeoperator(const ValueWithCodeSet &valueWithCodeSet) : ValueWithCodeSet(valueWithCodeSet) {}
};


#endif //LEGEMFEST_STYRKEOPERATOR_H
