//
// Created by sigsegv on 2/4/23.
//

#ifndef LEGEMFEST_PVIRKESTOFF_H
#define LEGEMFEST_PVIRKESTOFF_H

#include "GenericListStorage.h"
#include "PFestId.h"
#include "PString.h"
#include <vector>

class FestDeserializer;
class Virkestoff;
class FestUuidList;
class FestUuid;

class PVirkestoff {
    friend FestDeserializer;
private:
    GenericListItems32 refVirkestoff;
    PFestId id;
    PString navn;
    PString navnEngelsk;
public:
    PVirkestoff(const Virkestoff &, FestUuidList &festUuidList, std::vector<FestUuid> &idblock, std::string &strblock,
                std::map<std::string,uint32_t> &cache);
    bool operator == (const PVirkestoff &) const;
};


#endif //LEGEMFEST_PVIRKESTOFF_H
