//
// Created by sigsegv on 2/9/23.
//

#ifndef LEGEMFEST_POPPFVARSELSLV_H
#define LEGEMFEST_POPPFVARSELSLV_H

#include "POppf.h"
#include "PVarselSlv.h"

class FestDeserializer;
class OppfVarselSlv;
class ValueWithCodesetList;
class FestUuidList;
class FestUuid;

class POppfVarselSlv : public POppf, public PVarselSlv {
    friend FestDeserializer;
public:
    POppfVarselSlv(const OppfVarselSlv &, ValueWithCodesetList &, FestUuidList &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
};


#endif //LEGEMFEST_POPPFVARSELSLV_H
