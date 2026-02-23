//
// Created by sigsegv on 2/11/23.
//

#ifndef LEGEMFEST_PSUBSTANS_H
#define LEGEMFEST_PSUBSTANS_H

#include "PValueWithCodeset.h"
#include "PFestId.h"
#include <vector>

class FestDeserializer_0;
class FestDeserializer_1;
class Substans;

class PSubstans {
    friend FestDeserializer_0;
    friend FestDeserializer_1;
private:
    PValueWithCodeset atc;
    PFestId refVirkestoff;
    PString substans;
public:
    PSubstans(const Substans &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PSubstans &other) const;
};

#endif //LEGEMFEST_PSUBSTANS_H
