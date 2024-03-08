//
// Created by sigsegv on 12/20/22.
//

#ifndef LEGEMFEST_ENHETSTORRELSE_H
#define LEGEMFEST_ENHETSTORRELSE_H

#include "ValueWithCodeSet.h"

class EnhetStorrelse : public ValueWithCodeSet {
public:
    EnhetStorrelse() : ValueWithCodeSet() {}
    EnhetStorrelse(const ValueWithCodeSet &valueWithCodeSet) : ValueWithCodeSet(valueWithCodeSet) {}
};

#endif //LEGEMFEST_ENHETSTORRELSE_H
