//
// Created by sigsegv on 12/18/22.
//

#ifndef LEGEMFEST_ENHETFORSKRIVNING_H
#define LEGEMFEST_ENHETFORSKRIVNING_H

#include "ValueWithCodeSet.h"

class EnhetForskrivning : public ValueWithCodeSet {
public:
    EnhetForskrivning() : ValueWithCodeSet() {}
    EnhetForskrivning(const ValueWithCodeSet &valueWithCodeSet) : ValueWithCodeSet(valueWithCodeSet) {}
};

#endif //LEGEMFEST_ENHETFORSKRIVNING_H
