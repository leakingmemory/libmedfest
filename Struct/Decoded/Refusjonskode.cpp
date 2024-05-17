//
// Created by sigsegv on 12/25/22.
//

#include <Struct/Decoded/Refusjonskode.h>

ValueWithCodeSet Refusjonskode::GetRefusjonskode() const {
    return refusjonskode;
}

std::string Refusjonskode::GetGyldigFraDato() const {
    return gyldigFraDato;
}

std::string Refusjonskode::GetForskrivesTilDato() const {
    return forskrivesTilDato;
}

std::string Refusjonskode::GetUtleveresTilDato() const {
    return utleveresTilDato;
}

std::vector<std::string> Refusjonskode::GetUnderterm() const {
    return underterm;
}

std::vector<RefRefusjonsvilkar> Refusjonskode::GetRefusjonsvilkar() const {
    return refusjonsvilkar;
}