//
// Created by sigsegv on 2/11/23.
//

#ifndef LEGEMFEST_PSUBSTANS_H
#define LEGEMFEST_PSUBSTANS_H

#include "PValueWithCodeset.h"
#include "PFestId.h"
#include <vector>

class FestDeserializer;
class Substans;

class PSubstans {
    friend FestDeserializer;
private:
    PValueWithCodeset atc;
    PFestId refVirkestoff;
    PString substans;
public:
    PSubstans(const Substans &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PSubstans &other) const;
};

#endif //LEGEMFEST_PSUBSTANS_H
