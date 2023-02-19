//
// Created by sigsegv on 2/11/23.
//

#include "PInteraksjon.h"
#include "PValueWithCodeset.h"
#include "ReferanseList.h"
#include "SubstansgruppeList.h"
#include "ValueWithCodesetList.h"
#include "../Decoded/Interaksjon.h"

PInteraksjon::PInteraksjon(const Interaksjon &interaksjon, ReferanseList &referanseList,
                           SubstansgruppeList &substansgruppeList, SubstansList &substansList,
                           ValueWithCodesetList &valueWithCodesetList, std::vector<FestUuid> &idblock,
                           std::string &strblock, std::map<std::string, uint32_t> &cache) :
        relevans(interaksjon.relevans, strblock, cache),
        kildegrunnlag(interaksjon.kildegrunnlag, strblock, cache),
        visningsregel(),
        referanse(),
        substansgruppe(),
        id(interaksjon.id, idblock),
        kliniskKonsekvens(interaksjon.kliniskKonsekvens, strblock, cache),
        interaksjonsmekanisme(interaksjon.interaksjonsmekanisme, strblock, cache),
        handtering(interaksjon.handtering, strblock, cache),
        situasjonskriterium(interaksjon.situasjonskriterium, strblock, cache)
{
    {
        std::vector<PValueWithCodeset> visningsregel{};
        for (const auto &vr : interaksjon.visningsregel) {
            visningsregel.emplace_back(vr, strblock, cache);
        }
        this->visningsregel = valueWithCodesetList.StoreList(visningsregel);
    }
    {
        std::vector<PReferanse> referanse{};
        for (const auto &r : interaksjon.referanse) {
            referanse.emplace_back(r, strblock, cache);
        }
        this->referanse = referanseList.StoreList(referanse);
    }
    {
        std::vector<PSubstansgruppe> substansgruppe{};
        for (const auto &s : interaksjon.substansgruppe) {
            substansgruppe.emplace_back(s, substansList, idblock, strblock, cache);
        }
        this->substansgruppe = substansgruppeList.StoreList(substansgruppe);
    }
}

bool PInteraksjon::operator==(const PInteraksjon &other) const {
    return id == other.id &&
           relevans == other.relevans &&
           kildegrunnlag == other.kildegrunnlag &&
           visningsregel == other.visningsregel &&
           referanse == other.referanse &&
           substansgruppe == other.substansgruppe &&
           kliniskKonsekvens == other.kliniskKonsekvens &&
           interaksjonsmekanisme == other.interaksjonsmekanisme &&
           handtering == other.handtering &&
           situasjonskriterium == other.situasjonskriterium;
}