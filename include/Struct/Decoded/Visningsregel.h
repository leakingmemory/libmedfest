//
// Created by sigsegv on 12/27/22.
//

#ifndef LEGEMFEST_VISNINGSREGEL_H
#define LEGEMFEST_VISNINGSREGEL_H

#include "ValueWithCodeSet.h"

class Visningsregel : public ValueWithCodeSet {
public:
    Visningsregel() : ValueWithCodeSet() {}
    Visningsregel(const ValueWithCodeSet &visningsregel) : ValueWithCodeSet(visningsregel) {}
};

#endif //LEGEMFEST_VISNINGSREGEL_H
