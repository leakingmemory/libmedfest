//
// Created by sigsegv on 2/5/23.
//

#include <Struct/Packed/PRefusjonsgruppe.h>
#include <Struct/Packed/RefusjonskodeList.h>
#include <Struct/Packed/RefRefusjonsvilkarList.h>
#include <Struct/Packed/FestUuid.h>
#include <Struct/Packed/StringList.h>
#include <Struct/Decoded/Refusjonsgruppe.h>

PRefusjonsgruppe::PRefusjonsgruppe(const Refusjonsgruppe &refusjonsgruppe, RefusjonskodeList &refusjonskodeList, RefRefusjonsvilkarList &refRefusjonsvilkarList,
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
        std::vector<PRefusjonskode> refusjonskode{};
        for (const auto &r: refusjonsgruppe.GetRefusjonskode()) {
            refusjonskode.emplace_back(r, refRefusjonsvilkarList, stringList, idblock, strblock, cache);
        }
        this->refusjonskode = refusjonskodeList.StoreList(refusjonskode);
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
