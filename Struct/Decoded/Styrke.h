//
// Created by sigsegv on 12/17/22.
//

#ifndef LEGEMFEST_STYRKE_H
#define LEGEMFEST_STYRKE_H

#include "ValueUnit.h"

class Styrke : public ValueUnit {
public:
    Styrke() : ValueUnit() {}
    Styrke(const ValueUnit &valueUnit) : ValueUnit(valueUnit) {}
};


#endif //LEGEMFEST_STYRKE_H
