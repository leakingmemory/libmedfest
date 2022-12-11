//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_LEGEMIDDEL_H
#define LEGEMFEST_LEGEMIDDEL_H


#include "AdministreringLegemiddel.h"
#include "LegemiddelCore.h"
#include <vector>

class Legemiddel : public LegemiddelCore {
private:
    AdministreringLegemiddel administreringLegemiddel; // Ikke pakning
    std::vector<std::string> sortertVirkestoffMedStyrke; // Ikke pakning
public:
    Legemiddel() : LegemiddelCore(), administreringLegemiddel(), sortertVirkestoffMedStyrke() {}
    Legemiddel(const LegemiddelCore &legemiddelCore, const AdministreringLegemiddel &administreringLegemiddel,
               const std::vector<std::string> &sortertVirkestoffMedStyrke) :
            LegemiddelCore(legemiddelCore), administreringLegemiddel(administreringLegemiddel),
            sortertVirkestoffMedStyrke(sortertVirkestoffMedStyrke) {}
    [[nodiscard]] AdministreringLegemiddel GetAdministreringLegemiddel() const;
    [[nodiscard]] std::vector<std::string> GetSortertVirkestoffMedStyrke() const;
};


#endif //LEGEMFEST_LEGEMIDDEL_H
