//
// Created by sigsegv on 12/12/22.
//

#ifndef LEGEMFEST_PRIS_H
#define LEGEMFEST_PRIS_H

#include "ValueUnit.h"

class Pris : public ValueUnit {
public:
    Pris() : ValueUnit() {}
    Pris(const ValueUnit &valueUnit) : ValueUnit(valueUnit) {}
};

#endif //LEGEMFEST_PRIS_H
