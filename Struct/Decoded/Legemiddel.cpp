//
// Created by jeo on 12/9/22.
//

#include "Legemiddel.h"

AdministreringLegemiddel Legemiddel::GetAdministreringLegemiddel() const {
    return administreringLegemiddel;
}

std::vector<std::string> Legemiddel::GetSortertVirkestoffMedStyrke() const {
    return sortertVirkestoffMedStyrke;
}
