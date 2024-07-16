//
// Created by sigsegv on 2/9/23.
//

#include <Struct/Packed/POppfVarselSlv.h>
#include <Struct/Decoded/OppfVarselSlv.h>

POppfVarselSlv_0_0_0::POppfVarselSlv_0_0_0(const OppfVarselSlv &oppf, ValueWithCodesetList &valueWithCodesetList,
                               FestUuidList_0_0_0 &festUuidList, std::vector<FestUuid> &idblock, std::string &strblock,
                               std::map<std::string, uint32_t> &cache) :
        POppf(oppf, idblock, strblock, cache),
        PVarselSlv_0_0_0(oppf.varselSlv, valueWithCodesetList, festUuidList, strblock, cache)
{}

bool POppfVarselSlv_0_0_0::operator==(const POppfVarselSlv_0_0_0 &other) const {
    return POppf::operator==(other) &&
           PVarselSlv_0_0_0::operator==(other);
}

POppfVarselSlv_0_4_0::POppfVarselSlv_0_4_0(const OppfVarselSlv &oppf, ValueWithCodesetList &valueWithCodesetList,
                               FestUuidList_0_4_0 &festUuidList, std::vector<FestUuid> &idblock, std::string &strblock,
                               std::map<std::string, uint32_t> &cache) :
        POppf(oppf, idblock, strblock, cache),
        PVarselSlv_0_4_0(oppf.varselSlv, valueWithCodesetList, festUuidList, strblock, cache)
{}

POppfVarselSlv_0_4_0::POppfVarselSlv_0_4_0(const POppfVarselSlv_0_0_0 &poppf) :
        POppf(static_cast<const POppf &>(poppf)),
        PVarselSlv_0_4_0(static_cast<const PVarselSlv_0_0_0 &>(poppf))
{}

bool POppfVarselSlv_0_4_0::operator==(const POppfVarselSlv_0_4_0 &other) const {
    return POppf::operator==(other) &&
           PVarselSlv_0_4_0::operator==(other);
}

POppfVarselSlv::POppfVarselSlv(const POppfVarselSlv_0_0_0 &v) :
        POppf(static_cast<const POppf &>(v)),
        PVarselSlv(static_cast<const PVarselSlv_0_0_0 &>(v))
{}
POppfVarselSlv::POppfVarselSlv(const POppfVarselSlv_0_4_0 &v) :
        POppf(static_cast<const POppf &>(v)),
        PVarselSlv(static_cast<const PVarselSlv_0_4_0 &>(v))
{}
