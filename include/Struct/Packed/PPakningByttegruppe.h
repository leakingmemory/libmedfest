//
// Created by sigsegv on 1/19/23.
//

#ifndef LEGEMFEST_PPAKNINGBYTTEGRUPPE_H
#define LEGEMFEST_PPAKNINGBYTTEGRUPPE_H


#include "PFestId.h"
#include "PString.h"

class FestDeserializer_0;
class FestDeserializer_1;
class PakningByttegruppe;

class PPakningByttegruppe {
    friend FestDeserializer_0;
    friend FestDeserializer_1;
private:
    PFestId refByttegruppe;
    PString gyldigFraDato;
public:
    PPakningByttegruppe(const PakningByttegruppe &, std::vector<FestUuid> &uuidblock, std::string &strblock,
                        std::map<std::string,uint32_t> &cache);
    bool operator == (const PPakningByttegruppe &) const;
};


#endif //LEGEMFEST_PPAKNINGBYTTEGRUPPE_H
