//
// Created by sigsegv on 12/11/22.
//

#ifndef LEGEMFEST_SVARTTREKANT_H
#define LEGEMFEST_SVARTTREKANT_H

#include "ValueWithCodeSet.h"

class SvartTrekant : public ValueWithCodeSet {
public:
    SvartTrekant() : ValueWithCodeSet() {}
    SvartTrekant(const ValueWithCodeSet &valueWithCodeSet) : ValueWithCodeSet(valueWithCodeSet) {}
};

#endif //LEGEMFEST_SVARTTREKANT_H
