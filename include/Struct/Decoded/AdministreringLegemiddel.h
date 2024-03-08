//
// Created by sigsegv on 12/9/22.
//

#ifndef LEGEMFEST_ADMINISTRERINGLEGEMIDDEL_H
#define LEGEMFEST_ADMINISTRERINGLEGEMIDDEL_H

#include "Administrasjonsvei.h"
#include "EnhetDosering.h"
#include "BruksomradeEtikett.h"
#include "KanKnuses.h"
#include "ForhandsregelInntak.h"
#include "Deling.h"
#include "KanApnes.h"
#include "Bolus.h"
#include "InjeksjonshastighetBolus.h"
#include "MaybeBoolean.h"
#include <vector>

class AdministreringLegemiddel {
private:
    Administrasjonsvei administrasjonsvei;
    EnhetDosering enhetDosering;
    std::vector<BruksomradeEtikett> bruksomradeEtikett;
    KanKnuses kanKnuses;
    std::vector<ForhandsregelInntak> forhandsregelInntak;
    std::vector<ValueWithCodeSet> kortdose;
    Deling deling;
    KanApnes kanApnes;
    Bolus bolus;
    InjeksjonshastighetBolus injeksjonshastighetBolus;
    MaybeBoolean blandingsveske;
public:
    AdministreringLegemiddel() : administrasjonsvei(), enhetDosering(), bruksomradeEtikett(), kanKnuses(), kortdose(),
            deling(), kanApnes(), bolus(), injeksjonshastighetBolus(), blandingsveske(MaybeBoolean::UNSPECIFIED) {}
    AdministreringLegemiddel(
            const Administrasjonsvei &administrasjonsvei, const EnhetDosering &enhetDosering,
            const std::vector<BruksomradeEtikett> &bruksomradeEtikett, const KanKnuses &kanKnuses,
            const std::vector<ForhandsregelInntak> &forhandsregelInntak, const std::vector<ValueWithCodeSet> &kortdose,
            const Deling &deling, const KanApnes &kanApnes, const Bolus &bolus,
            const InjeksjonshastighetBolus &injeksjonshastighetBolus, MaybeBoolean blandingsveske
        ) :
            administrasjonsvei(administrasjonsvei), enhetDosering(enhetDosering),
            bruksomradeEtikett(bruksomradeEtikett), kanKnuses(kanKnuses), forhandsregelInntak(forhandsregelInntak),
            kortdose(kortdose), deling(deling), kanApnes(kanApnes), bolus(bolus),
            injeksjonshastighetBolus(injeksjonshastighetBolus), blandingsveske(blandingsveske) {}
    [[nodiscard]] Administrasjonsvei GetAdministrasjonsvei() const;
    [[nodiscard]] EnhetDosering GetEnhetDosering() const;
    [[nodiscard]] std::vector<BruksomradeEtikett> GetBruksomradeEtikett() const;
    [[nodiscard]] KanKnuses GetKanKnuses() const;
    [[nodiscard]] std::vector<ForhandsregelInntak> GetForhandsregelInntak() const;
    [[nodiscard]] std::vector<ValueWithCodeSet> GetKortdose() const;
    [[nodiscard]] Deling GetDeling() const;
    [[nodiscard]] KanApnes GetKanApnes() const;
    [[nodiscard]] Bolus GetBolus() const;
    [[nodiscard]] InjeksjonshastighetBolus GetInjeksjonshastighetBolus() const;
    [[nodiscard]] MaybeBoolean GetBlandingsveske();
};


#endif //LEGEMFEST_ADMINISTRERINGLEGEMIDDEL_H
