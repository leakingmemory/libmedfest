//
// Created by sigsegv on 1/19/23.
//

#ifndef LEGEMFEST_PPAKNINGBYTTEGRUPPE_H
#define LEGEMFEST_PPAKNINGBYTTEGRUPPE_H


#include "PFestId.h"
#include "PString.h"

class FestDeserializer;
class PakningByttegruppe;

class PPakningByttegruppe {
private:
    PFestId refByttegruppe;
    PString gyldigFraDato;
public:
    PPakningByttegruppe(const PakningByttegruppe &, std::vector<FestUuid> &uuidblock, std::string &strblock);
};


#endif //LEGEMFEST_PPAKNINGBYTTEGRUPPE_H