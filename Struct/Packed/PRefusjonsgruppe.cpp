//
// Created by sigsegv on 2/5/23.
//

#include <Struct/Packed/PRefusjonsgruppe.h>
#include <Struct/Packed/RefusjonskodeList.h>
#include <Struct/Packed/RefRefusjonsvilkarList.h>
#include <Struct/Packed/FestUuid.h>
#include <Struct/Packed/StringList.h>
#include <Struct/Decoded/Refusjonsgruppe.h>
#include "Struct/Packed/PackException.h"

PRefusjonsgruppe::PRefusjonsgruppe(const Refusjonsgruppe &refusjonsgruppe, RefusjonskodeList_0_0_0 &refusjonskodeList_0_0_0, RefusjonskodeList &refusjonskodeList, RefRefusjonsvilkarList &refRefusjonsvilkarList,
                                   StringList &stringList, std::vector<FestUuid> &idblock, std::string &strblock,
                                   std::map<std::string, uint32_t> &cache) :
        gruppeNr(refusjonsgruppe.GetGruppeNr(), strblock, cache),
        id(refusjonsgruppe.GetId(), strblock, cache),
        refusjonsberettigetBruk(refusjonsgruppe.GetRefusjonsberettigetBruk(), strblock, cache),
        refusjonskode(),
        refVilkar(),
        atc(refusjonsgruppe.GetAtc(), strblock, cache),
        kreverRefusjonskode(refusjonsgruppe.GetKreverRefusjonskode())
{
    {
        std::vector<PRefusjonskode_0_0_0> refusjonskode_0_0_0{};
        std::vector<PRefusjonskode> refusjonskode{};
        for (const auto &r: refusjonsgruppe.GetRefusjonskode()) {
            refusjonskode_0_0_0.emplace_back(r, refRefusjonsvilkarList, stringList, idblock, strblock, cache);
            refusjonskode.emplace_back(r, refRefusjonsvilkarList, stringList, idblock, strblock, cache);
        }
        this->refusjonskode = refusjonskodeList.StoreList(refusjonskode);
        auto refusjonskode_0_0_0_list = refusjonskodeList_0_0_0.StoreList(refusjonskode_0_0_0, this->refusjonskode.start);
        if (refusjonskode_0_0_0_list.start != this->refusjonskode.start) {
            throw PackException("Refusjonskode compat 0.0.0 mismatching start");
        }
        if (refusjonskode_0_0_0_list.size != this->refusjonskode.size) {
            throw PackException("Refusjonskode compat 0.0.0 mismatching size");
        }
    }
    {
        std::vector<PString> refVilkar{};
        for (const auto &str : refusjonsgruppe.GetRefVilkar()) {
            refVilkar.emplace_back(str, strblock, cache);
        }
        this->refVilkar = stringList.StoreList(refVilkar);
    }
}

bool PRefusjonsgruppe::operator==(const PRefusjonsgruppe &other) const {
    return id == other.id &&
           gruppeNr == other.gruppeNr &&
           refusjonsberettigetBruk == other.refusjonsberettigetBruk &&
           refusjonskode == other.refusjonskode &&
           refVilkar == other.refVilkar &&
           atc == other.atc &&
           kreverRefusjonskode == other.kreverRefusjonskode;
}
