//
// Created by sigsegv on 12/26/22.
//

#include "Vilkar.h"

std::string Vilkar::GetId() const {
    return id;
}

std::string Vilkar::GetVilkarNr() const {
    return vilkarNr;
}

Gruppe Vilkar::GetGruppe() const {
    return gruppe;
}

GjelderFor Vilkar::GetGjelderFor() const {
    return gjelderFor;
}

std::string Vilkar::GetTekst() const {
    return tekst;
}

std::string Vilkar::GetGyldigFraDato() const {
    return gyldigFraDato;
}

StrukturertVilkar Vilkar::GetStrukturertVilkar() const {
    return strukturertVilkar;
}