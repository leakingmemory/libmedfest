//
// Created by jeo on 12/9/22.
//

#include "Legemiddel.h"

Atc Legemiddel::GetAtc() const {
    return atc;
}

std::string Legemiddel::GetNavnFormStyrke() const {
    return navnFormStyrke;
}

Reseptgruppe Legemiddel::GetReseptgruppe() const {
    return reseptgruppe;
}

LegemiddelformKort Legemiddel::GetLegemiddelformKort() const {
    return legemiddelformKort;
}

std::vector<std::string> Legemiddel::GetRefVilkar() const {
    return refVilkar;
}

TypeSoknadSlv Legemiddel::GetTypeSoknadSlv() const {
    return typeSoknadSlv;
}

AdministreringLegemiddel Legemiddel::GetAdministreringLegemiddel() const {
    return administreringLegemiddel;
}
