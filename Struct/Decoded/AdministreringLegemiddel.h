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
#include <vector>

class AdministreringLegemiddel {
private:
    Administrasjonsvei administrasjonsvei;
    EnhetDosering enhetDosering;
    std::vector<BruksomradeEtikett> bruksomradeEtikett;
    KanKnuses kanKnuses;
    std::vector<ForhandsregelInntak> forhandsregelInntak;
public:
    AdministreringLegemiddel() : administrasjonsvei(), enhetDosering(), bruksomradeEtikett(), kanKnuses() {}
    AdministreringLegemiddel(
            const Administrasjonsvei &administrasjonsvei, const EnhetDosering &enhetDosering,
            const std::vector<BruksomradeEtikett> &bruksomradeEtikett, const KanKnuses &kanKnuses,
            const std::vector<ForhandsregelInntak> &forhandsregelInntak
        ) :
            administrasjonsvei(administrasjonsvei), enhetDosering(enhetDosering),
            bruksomradeEtikett(bruksomradeEtikett), kanKnuses(kanKnuses), forhandsregelInntak(forhandsregelInntak) {}
    [[nodiscard]] Administrasjonsvei GetAdministrasjonsvei() const;
    [[nodiscard]] EnhetDosering GetEnhetDosering() const;
    [[nodiscard]] std::vector<BruksomradeEtikett> GetBruksomradeEtikett() const;
    [[nodiscard]] KanKnuses GetKanKnuses() const;
    [[nodiscard]] std::vector<ForhandsregelInntak> GetForhandsregelInntak() const;
};


#endif //LEGEMFEST_ADMINISTRERINGLEGEMIDDEL_H
