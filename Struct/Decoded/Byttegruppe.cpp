//
// Created by sigsegv on 12/29/22.
//

#include "Byttegruppe.h"

std::string Byttegruppe::GetId() const {
    return id;
}

ValueWithDistinguishedName Byttegruppe::GetKode() const {
    return kode;
}

std::string Byttegruppe::GetGyldigFraDato() const {
    return gyldigFraDato;
}

std::string Byttegruppe::GetBeskrivelseByttbarhet() const {
    return beskrivelseByttbarhet;
}

bool Byttegruppe::GetMerknadTilByttbarhet() const {
    return merknadTilByttbarhet;
}