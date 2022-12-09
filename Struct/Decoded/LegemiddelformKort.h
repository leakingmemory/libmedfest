//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_LEGEMIDDELFORMKORT_H
#define LEGEMFEST_LEGEMIDDELFORMKORT_H


#include "ValueWithCodeSet.h"

class LegemiddelformKort : public ValueWithCodeSet {
public:
    LegemiddelformKort() : ValueWithCodeSet() {}
    LegemiddelformKort(const ValueWithCodeSet &valueWithCodeSet) : ValueWithCodeSet(valueWithCodeSet) {}
};


#endif //LEGEMFEST_LEGEMIDDELFORMKORT_H
