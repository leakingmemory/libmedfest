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
#include "Kortdose.h"
#include "Deling.h"
#include "KanApnes.h"
#include "Bolus.h"
#include <vector>

class AdministreringLegemiddel {
private:
    Administrasjonsvei administrasjonsvei;
    EnhetDosering enhetDosering;
    std::vector<BruksomradeEtikett> bruksomradeEtikett;
    KanKnuses kanKnuses;
    std::vector<ForhandsregelInntak> forhandsregelInntak;
    std::vector<Kortdose> kortdose;
    Deling deling;
    KanApnes kanApnes;
    Bolus bolus;
public:
    AdministreringLegemiddel() : administrasjonsvei(), enhetDosering(), bruksomradeEtikett(), kanKnuses(), kortdose(),
            deling(), kanApnes(), bolus() {}
    AdministreringLegemiddel(
            const Administrasjonsvei &administrasjonsvei, const EnhetDosering &enhetDosering,
            const std::vector<BruksomradeEtikett> &bruksomradeEtikett, const KanKnuses &kanKnuses,
            const std::vector<ForhandsregelInntak> &forhandsregelInntak, const std::vector<Kortdose> &kortdose,
            const Deling &deling, const KanApnes &kanApnes, const Bolus &bolus
        ) :
            administrasjonsvei(administrasjonsvei), enhetDosering(enhetDosering),
            bruksomradeEtikett(bruksomradeEtikett), kanKnuses(kanKnuses), forhandsregelInntak(forhandsregelInntak),
            kortdose(kortdose), deling(deling), kanApnes(kanApnes), bolus(bolus) {}
    [[nodiscard]] Administrasjonsvei GetAdministrasjonsvei() const;
    [[nodiscard]] EnhetDosering GetEnhetDosering() const;
    [[nodiscard]] std::vector<BruksomradeEtikett> GetBruksomradeEtikett() const;
    [[nodiscard]] KanKnuses GetKanKnuses() const;
    [[nodiscard]] std::vector<ForhandsregelInntak> GetForhandsregelInntak() const;
    [[nodiscard]] std::vector<Kortdose> GetKortdose() const;
    [[nodiscard]] Deling GetDeling() const;
    [[nodiscard]] KanApnes GetKanApnes() const;
    [[nodiscard]] Bolus GetBolus() const;
};


#endif //LEGEMFEST_ADMINISTRERINGLEGEMIDDEL_H
