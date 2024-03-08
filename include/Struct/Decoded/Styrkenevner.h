//
// Created by sigsegv on 12/17/22.
//

#ifndef LEGEMFEST_STYRKENEVNER_H
#define LEGEMFEST_STYRKENEVNER_H

#include "ValueUnit.h"

class Styrkenevner : public ValueUnit {
public:
    Styrkenevner() : ValueUnit() {}
    Styrkenevner(const ValueUnit &valueUnit) : ValueUnit(valueUnit) {}
};


#endif //LEGEMFEST_STYRKENEVNER_H
