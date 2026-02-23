//
// Created by sigsegv on 1/18/23.
//

#ifndef LEGEMFEST_PVALUEUNIT_H
#define LEGEMFEST_PVALUEUNIT_H

#include "PString.h"

class FestDeserializer_0;
class FestDeserializer_1;
class ValueUnit;

class PValueUnit {
    friend FestDeserializer_0;
    friend FestDeserializer_1;
private:
    double value;
    PString unit;
public:
    PValueUnit(const ValueUnit &, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PValueUnit &other) const;
};


#endif //LEGEMFEST_PVALUEUNIT_H
