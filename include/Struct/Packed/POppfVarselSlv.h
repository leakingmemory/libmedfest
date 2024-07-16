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

class POppfVarselSlv_0_0_0 : public POppf, public PVarselSlv_0_0_0 {
    friend FestDeserializer;
public:
    POppfVarselSlv_0_0_0(const OppfVarselSlv &, ValueWithCodesetList &, FestUuidList_0_0_0 &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const POppfVarselSlv_0_0_0 &) const;
};

class POppfVarselSlv_0_4_0 : public POppf, public PVarselSlv_0_4_0 {
    friend FestDeserializer;
public:
    POppfVarselSlv_0_4_0(const OppfVarselSlv &, ValueWithCodesetList &, FestUuidList_0_4_0 &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    POppfVarselSlv_0_4_0(const POppfVarselSlv_0_0_0 &);
    bool operator == (const POppfVarselSlv_0_4_0 &) const;
};

class POppfVarselSlv : public POppf, public PVarselSlv {
public:
    POppfVarselSlv(const POppfVarselSlv_0_0_0 &);
    POppfVarselSlv(const POppfVarselSlv_0_4_0 &);
};

#endif //LEGEMFEST_POPPFVARSELSLV_H
