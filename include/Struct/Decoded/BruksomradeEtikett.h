//
// Created by sigsegv on 12/10/22.
//

#ifndef LEGEMFEST_BRUKSOMRADEETIKETT_H
#define LEGEMFEST_BRUKSOMRADEETIKETT_H

#include "ValueWithCodeSet.h"

class BruksomradeEtikett : public ValueWithCodeSet {
public:
    BruksomradeEtikett() : ValueWithCodeSet() {}
    BruksomradeEtikett(const ValueWithCodeSet &valueWithCodeSet) : ValueWithCodeSet(valueWithCodeSet) {}
};

#endif //LEGEMFEST_BRUKSOMRADEETIKETT_H
