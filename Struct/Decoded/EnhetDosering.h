//
// Created by sigsegv on 12/10/22.
//

#ifndef LEGEMFEST_ENHETDOSERING_H
#define LEGEMFEST_ENHETDOSERING_H

#include "ValueWithCodeSet.h"

class EnhetDosering : public ValueWithCodeSet {
public:
    EnhetDosering() : ValueWithCodeSet() {}
    EnhetDosering(const ValueWithCodeSet &valueWithCodeSet) : ValueWithCodeSet(valueWithCodeSet) {}
};

#endif //LEGEMFEST_ENHETDOSERING_H
