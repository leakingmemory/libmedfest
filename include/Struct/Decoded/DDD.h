//
// Created by sigsegv on 12/12/22.
//

#ifndef LEGEMFEST_DDD_H
#define LEGEMFEST_DDD_H

#include "ValueUnit.h"

class DDD : public ValueUnit {
public:
    DDD() : ValueUnit() {}
    DDD(const ValueUnit &valueUnit) : ValueUnit(valueUnit) {}
};

#endif //LEGEMFEST_DDD_H
