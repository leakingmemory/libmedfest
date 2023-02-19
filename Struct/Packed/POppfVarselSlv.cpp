//
// Created by sigsegv on 2/9/23.
//

#include "POppfVarselSlv.h"
#include "../Decoded/OppfVarselSlv.h"

POppfVarselSlv::POppfVarselSlv(const OppfVarselSlv &oppf, ValueWithCodesetList &valueWithCodesetList,
                               FestUuidList &festUuidList, std::vector<FestUuid> &idblock, std::string &strblock,
                               std::map<std::string, uint32_t> &cache) :
        POppf(oppf, idblock, strblock, cache),
        PVarselSlv(oppf.varselSlv, valueWithCodesetList, festUuidList, strblock, cache)
{}

bool POppfVarselSlv::operator==(const POppfVarselSlv &other) const {
    return POppf::operator==(other) &&
           PVarselSlv::operator==(other);
}