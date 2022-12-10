//
// Created by sigsegv on 12/10/22.
//

#ifndef LEGEMFEST_FORHANDSREGELINNTAK_H
#define LEGEMFEST_FORHANDSREGELINNTAK_H

#include "ValueWithCodeSet.h"

class ForhandsregelInntak : public ValueWithCodeSet {
public:
    ForhandsregelInntak() : ValueWithCodeSet() {}
    ForhandsregelInntak(const ValueWithCodeSet &valueWithCodeSet) : ValueWithCodeSet(valueWithCodeSet) {}
};

#endif //LEGEMFEST_FORHANDSREGELINNTAK_H
