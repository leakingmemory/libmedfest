//
// Created by sigsegv on 12/29/22.
//

#include <Struct/Decoded/Interaksjon.h>

std::string Interaksjon::GetId() const {
    return id;
}

Relevans Interaksjon::GetRelevans() const {
    return relevans;
}

std::string Interaksjon::GetKliniskKonsekvens() const {
    return kliniskKonsekvens;
}

std::string Interaksjon::GetInteraksjonsmekanisme() const {
    return interaksjonsmekanisme;
}

Kildegrunnlag Interaksjon::GetKildegrunnlag() const {
    return kildegrunnlag;
}

std::string Interaksjon::GetHandtering() const {
    return handtering;
}

std::vector<Visningsregel> Interaksjon::GetVisningsregel() const {
    return visningsregel;
}

std::vector<Referanse> Interaksjon::GetReferanse() const {
    return referanse;
}

std::vector<Substansgruppe> Interaksjon::GetSubstansgruppe() const {
    return substansgruppe;
}

std::string Interaksjon::GetSituasjonskriterium() const {
    return situasjonskriterium;
}