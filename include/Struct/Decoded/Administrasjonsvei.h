//
// Created by sigsegv on 12/9/22.
//

#ifndef LEGEMFEST_ADMINISTRASJONSVEI_H
#define LEGEMFEST_ADMINISTRASJONSVEI_H

#include "ValueWithCodeSet.h"

class Administrasjonsvei : public ValueWithCodeSet {
public:
    Administrasjonsvei() : ValueWithCodeSet() {}
    Administrasjonsvei(const ValueWithCodeSet &valueWithCodeSet) : ValueWithCodeSet(valueWithCodeSet) {}
};

#endif //LEGEMFEST_ADMINISTRASJONSVEI_H
