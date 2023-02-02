//
// Created by sigsegv on 1/9/23.
//

#ifndef LEGEMFEST_POPPF_H
#define LEGEMFEST_POPPF_H

#include "PFestId.h"
#include "PString.h"
#include "PValueWithDistinguishedName.h"
#include "FestUuid.h"
#include <vector>

class FestDeserializer;
class Oppf;

class POppf {
    friend FestDeserializer;
private:
    PFestId id;
    PString tidspunkt;
    PValueWithDistinguishedName status;
public:
    POppf(const Oppf &oppf, std::vector<FestUuid> &uuidblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
};

#endif //LEGEMFEST_POPPF_H
