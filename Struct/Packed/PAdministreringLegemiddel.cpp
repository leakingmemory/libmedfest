//
// Created by sigsegv on 1/10/23.
//

#include <Struct/Packed/PAdministreringLegemiddel.h>
#include <Struct/Decoded/AdministreringLegemiddel.h>
#include <Struct/Packed/ValueWithCodesetList.h>

PAdministreringLegemiddel::PAdministreringLegemiddel(const AdministreringLegemiddel &administreringLegemiddel,
                                                     std::string &strblock, std::map<std::string,uint32_t> &cache,
                                                     ValueWithCodesetList &valueWithCodesetList) :
        administrasjonsvei(administreringLegemiddel.GetAdministrasjonsvei(), strblock, cache),
        enhetDosering(administreringLegemiddel.GetEnhetDosering(), strblock, cache),
        bruksomradeEtikett(),
        forhandsregelInntak(),
        kortdose(),
        kanKnuses(administreringLegemiddel.GetKanKnuses(), strblock, cache),
        deling(administreringLegemiddel.GetDeling(), strblock, cache),
        kanApnes(administreringLegemiddel.GetKanApnes(), strblock, cache),
        bolus(administreringLegemiddel.GetBolus(), strblock, cache),
        injeksjonshastighetBolus(administreringLegemiddel.GetInjeksjonshastighetBolus(), strblock, cache) {
    {
        std::vector<PValueWithCodeset> list{};
        {
            auto bruksomradeEtikett = administreringLegemiddel.GetBruksomradeEtikett();
            for (const auto &v: bruksomradeEtikett) {
                list.emplace_back(v, strblock, cache);
            }
        }
        bruksomradeEtikett = valueWithCodesetList.StoreList(list);
    }
    {
        std::vector<PValueWithCodeset> list{};
        {
            auto forhandsregelInntak = administreringLegemiddel.GetForhandsregelInntak();
            for (const auto &v : forhandsregelInntak) {
                list.emplace_back(v, strblock, cache);
            }
        }
        forhandsregelInntak = valueWithCodesetList.StoreList(list);
    }
    {
        std::vector<PValueWithCodeset> list{};
        {
            auto kortdose = administreringLegemiddel.GetKortdose();
            for (const auto &v : kortdose) {
                list.emplace_back(v, strblock, cache);
            }
        }
        kortdose = valueWithCodesetList.StoreList(list);
    }
}

bool PAdministreringLegemiddel::operator==(const PAdministreringLegemiddel &other) const {
    return administrasjonsvei == other.administrasjonsvei &&
           enhetDosering == other.enhetDosering &&
           bruksomradeEtikett == other.bruksomradeEtikett &&
           forhandsregelInntak == other.forhandsregelInntak &&
           kortdose == other.kortdose &&
           kanKnuses == other.kanKnuses &&
           deling == other.deling &&
           kanApnes == other.kanApnes &&
           bolus == other.bolus &&
           injeksjonshastighetBolus == other.injeksjonshastighetBolus &&
           blandingsveske == other.blandingsveske;
}