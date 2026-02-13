//
// Created by sigsegv on 12/29/22.
//

#include <Struct/Decoded/Byttegruppe.h>

Byttegruppe::Byttegruppe() : id(), kode(), gyldigFraDato(), gyldigTilDato(), beskrivelseByttbarhet(), merknadTilByttbarhet() {}
Byttegruppe::Byttegruppe(const std::string &id, const ValueWithDistinguishedName &kode, const std::string &gyldigFraDato,
            const std::string &gyldigTilDato, const std::string &beskrivelseByttbarhet, bool merknadTilByttbarhet) :
        id(id), kode(kode), gyldigFraDato(gyldigFraDato), gyldigTilDato(gyldigTilDato), beskrivelseByttbarhet(beskrivelseByttbarhet),
        merknadTilByttbarhet(merknadTilByttbarhet) {}

Byttegruppe::~Byttegruppe() = default;

std::string Byttegruppe::GetId() const {
    return id;
}

ValueWithDistinguishedName Byttegruppe::GetKode() const {
    return kode;
}

std::string Byttegruppe::GetGyldigFraDato() const {
    return gyldigFraDato;
}

std::string Byttegruppe::GetGyldigTilDato() const {
    return gyldigTilDato;
}

std::string Byttegruppe::GetBeskrivelseByttbarhet() const {
    return beskrivelseByttbarhet;
}

bool Byttegruppe::GetMerknadTilByttbarhet() const {
    return merknadTilByttbarhet;
}