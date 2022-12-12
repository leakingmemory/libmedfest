//
// Created by sigsegv on 12/12/22.
//

#ifndef LEGEMFEST_ENHETPAKNING_H
#define LEGEMFEST_ENHETPAKNING_H

#include "ValueWithCodeSet.h"

class EnhetPakning : public ValueWithCodeSet {
public:
    EnhetPakning() : ValueWithCodeSet() {}
    EnhetPakning(const ValueWithCodeSet &valueWithCodeSet) : ValueWithCodeSet(valueWithCodeSet) {}
};

#endif //LEGEMFEST_ENHETPAKNING_H
