//
// Created by sigsegv on 12/25/22.
//

#include "Refusjonskode.h"

ValueWithCodeSet Refusjonskode::GetRefusjonskode() const {
    return refusjonskode;
}

std::string Refusjonskode::GetGyldigFraDato() const {
    return gyldigFraDato;
}

std::string Refusjonskode::GetForskrivesTilDato() const {
    return forskrivesTilDato;
}

std::vector<std::string> Refusjonskode::GetUnderterm() const {
    return underterm;
}

std::vector<RefRefusjonsvilkar> Refusjonskode::GetRefusjonsvilkar() const {
    return refusjonsvilkar;
}