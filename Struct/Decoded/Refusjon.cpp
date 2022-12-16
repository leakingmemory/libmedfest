//
// Created by sigsegv on 12/13/22.
//

#include "Refusjon.h"

std::string Refusjon::GetRefRefusjonsgruppe() const {
    return refRefusjonsgruppe;
}

std::string Refusjon::GetGyldigFraDato() const {
    return gyldigFraDato;
}

std::string Refusjon::GetForskrivesTilDato() const {
    return forskrivesTilDato;
}

std::string Refusjon::GetUtleveresTilDato() const {
    return utleveresTilDato;
}