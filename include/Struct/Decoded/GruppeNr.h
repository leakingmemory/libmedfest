//
// Created by sigsegv on 12/25/22.
//

#ifndef LEGEMFEST_GRUPPENR_H
#define LEGEMFEST_GRUPPENR_H

#include "ValueWithCodeSet.h"

class GruppeNr : public ValueWithCodeSet {
public:
    GruppeNr() : ValueWithCodeSet() {}
    GruppeNr(const ValueWithCodeSet &valueWithCodeSet) : ValueWithCodeSet(valueWithCodeSet) {}
};


#endif //LEGEMFEST_GRUPPENR_H
