//
// Created by jeo on 12/9/22.
//

#include "LegemiddelMerkevare.h"

Preparattype LegemiddelMerkevare::GetPreparattype() const {
    return preparattype;
}

std::string LegemiddelMerkevare::GetVarenavn() const {
    return varenavn;
}

std::string LegemiddelMerkevare::GetLegemiddelformLang() const {
    return legemiddelformLang;
}

std::string LegemiddelMerkevare::GetProdusent() const {
    return produsent;
}

std::vector<Reseptgyldighet> LegemiddelMerkevare::GetReseptgyldighet() const {
    return reseptgyldighet;
}

MaybeBoolean LegemiddelMerkevare::GetVarseltrekant() const {
    return varseltrekant;
}

std::string LegemiddelMerkevare::GetReferanseprodukt() const {
    return referanseprodukt;
}

Preparatomtaleavsnitt LegemiddelMerkevare::GetPreparatomtaleavsnitt() const {
    return preparatomtaleavsnitt;
}

Smak LegemiddelMerkevare::GetSmak() const {
    return smak;
}

std::vector<std::string> LegemiddelMerkevare::GetSortertVirkestoffUtenStyrke() const {
    return sortertVirkestoffUtenStyrke;
}

Vaksinestandard LegemiddelMerkevare::GetVaksinestandard() const {
    return vaksinestandard;
}