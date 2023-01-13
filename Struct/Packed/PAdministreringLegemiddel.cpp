//
// Created by sigsegv on 1/10/23.
//

#include "PAdministreringLegemiddel.h"
#include "../Decoded/AdministreringLegemiddel.h"
#include "ValueWithCodesetList.h"

PAdministreringLegemiddel::PAdministreringLegemiddel(const AdministreringLegemiddel &administreringLegemiddel,
                                                     std::string &strblock, ValueWithCodesetList &valueWithCodesetList) :
        administrasjonsvei(administreringLegemiddel.GetAdministrasjonsvei(), strblock),
        enhetDosering(administreringLegemiddel.GetEnhetDosering(), strblock),
        bruksomradeEtikett(),
        forhandsregelInntak(),
        kortdose(),
        kanKnuses(administreringLegemiddel.GetKanKnuses(), strblock),
        deling(administreringLegemiddel.GetDeling(), strblock),
        kanApnes(administreringLegemiddel.GetKanApnes(), strblock),
        bolus(administreringLegemiddel.GetBolus(), strblock),
        injeksjonshastighetBolus(administreringLegemiddel.GetInjeksjonshastighetBolus(), strblock) {
    {
        std::vector<PValueWithCodeset> list{};
        {
            auto bruksomradeEtikett = administreringLegemiddel.GetBruksomradeEtikett();
            for (const auto &v: bruksomradeEtikett) {
                list.emplace_back(v, strblock);
            }
        }
        bruksomradeEtikett = valueWithCodesetList.StoreList(list);
    }
    {
        std::vector<PValueWithCodeset> list{};
        {
            auto forhandsregelInntak = administreringLegemiddel.GetForhandsregelInntak();
            for (const auto &v : forhandsregelInntak) {
                list.emplace_back(v, strblock);
            }
        }
        forhandsregelInntak = valueWithCodesetList.StoreList(list);
    }
    {
        std::vector<PValueWithCodeset> list{};
        {
            auto kortdose = administreringLegemiddel.GetKortdose();
            for (const auto &v : kortdose) {
                list.emplace_back(v, strblock);
            }
        }
        kortdose = valueWithCodesetList.StoreList(list);
    }
}
