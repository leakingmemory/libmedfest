//
// Created by sigsegv on 2/9/23.
//

#include <Struct/Packed/PVarselSlv.h>
#include <Struct/Packed/ValueWithCodesetList.h>
#include <Struct/Decoded/VarselSlv.h>

PVarselSlv_0_0_0::PVarselSlv_0_0_0(const VarselSlv &varselSlv, ValueWithCodesetList &valueWithCodesetList,
                       FestUuidList_0_0_0 &festUuidList, std::string &strblock, std::map<std::string, uint32_t> &cache) :
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

bool PVarselSlv_0_0_0::operator==(const PVarselSlv_0_0_0 &other) const {
    return type == other.type &&
           referanseelement == other.referanseelement &&
           lenke == other.lenke &&
           visningsregel == other.visningsregel &&
           overskrift == other.overskrift &&
           varseltekst == other.varseltekst &&
           fraDato == other.fraDato;
}

PVarselSlv_0_4_0::PVarselSlv_0_4_0(const VarselSlv &varselSlv, ValueWithCodesetList &valueWithCodesetList,
                       FestUuidList_0_4_0 &festUuidList, std::string &strblock, std::map<std::string, uint32_t> &cache) :
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

PVarselSlv_0_4_0::PVarselSlv_0_4_0(const PVarselSlv_0_0_0 &v) :
        type(v.type),
        referanseelement(v.referanseelement),
        lenke(v.lenke),
        visningsregel(v.visningsregel),
        overskrift(v.overskrift),
        varseltekst(v.varseltekst),
        fraDato(v.fraDato)
{
}

bool PVarselSlv_0_4_0::operator==(const PVarselSlv_0_4_0 &other) const {
    return type == other.type &&
           referanseelement == other.referanseelement &&
           lenke == other.lenke &&
           visningsregel == other.visningsregel &&
           overskrift == other.overskrift &&
           varseltekst == other.varseltekst &&
           fraDato == other.fraDato;
}

PVarselSlv::PVarselSlv(const PVarselSlv_0_0_0 &v) : std::variant<PVarselSlv_0_0_0,PVarselSlv_0_4_0>(v) {}
PVarselSlv::PVarselSlv(const PVarselSlv_0_4_0 &v) : std::variant<PVarselSlv_0_0_0,PVarselSlv_0_4_0>(v) {}
