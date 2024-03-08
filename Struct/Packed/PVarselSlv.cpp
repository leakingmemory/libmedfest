//
// Created by sigsegv on 2/9/23.
//

#include <Struct/Packed/PVarselSlv.h>
#include <Struct/Packed/ValueWithCodesetList.h>
#include <Struct/Decoded/VarselSlv.h>

PVarselSlv::PVarselSlv(const VarselSlv &varselSlv, ValueWithCodesetList &valueWithCodesetList,
                       FestUuidList &festUuidList, std::string &strblock, std::map<std::string, uint32_t> &cache) :
        type(varselSlv.type, strblock, cache),
        referanseelement(varselSlv.referanseelement, festUuidList, strblock, cache),
        lenke(varselSlv.lenke, strblock, cache),
        visningsregel(),
        overskrift(varselSlv.overskrift, strblock, cache),
        varseltekst(varselSlv.varseltekst, strblock, cache),
        fraDato(varselSlv.fraDato, strblock, cache)
{
    std::vector<PValueWithCodeset> visningsregel{};
    for (const auto &v : varselSlv.visningsregel) {
        visningsregel.emplace_back(v, strblock, cache);
    }
    this->visningsregel = valueWithCodesetList.StoreList(visningsregel);
}

bool PVarselSlv::operator==(const PVarselSlv &other) const {
    return type == other.type &&
           referanseelement == other.referanseelement &&
           lenke == other.lenke &&
           visningsregel == other.visningsregel &&
           overskrift == other.overskrift &&
           varseltekst == other.varseltekst &&
           fraDato == other.fraDato;
}
