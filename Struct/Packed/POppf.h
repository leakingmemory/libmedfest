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

class Oppf;

class POppf {
private:
    PFestId id;
    PString tidspunkt;
    PValueWithDistinguishedName status;
public:
    POppf(const Oppf &oppf, std::vector<FestUuid> &uuidblock, std::string &strblock);
};

#endif //LEGEMFEST_POPPF_H
