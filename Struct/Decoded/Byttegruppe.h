//
// Created by sigsegv on 12/29/22.
//

#ifndef LEGEMFEST_BYTTEGRUPPE_H
#define LEGEMFEST_BYTTEGRUPPE_H

#include "ValueWithDistinguishedName.h"
#include <string>

class Byttegruppe {
private:
    std::string id;
    ValueWithDistinguishedName kode;
    std::string gyldigFraDato;
    std::string beskrivelseByttbarhet;
    bool merknadTilByttbarhet;
public:
    Byttegruppe() : id(), kode(), gyldigFraDato(), beskrivelseByttbarhet(), merknadTilByttbarhet() {}
    Byttegruppe(const std::string &id, const ValueWithDistinguishedName &kode, const std::string &gyldigFraDato,
                const std::string &beskrivelseByttbarhet, bool merknadTilByttbarhet) :
            id(id), kode(kode), gyldigFraDato(gyldigFraDato), beskrivelseByttbarhet(beskrivelseByttbarhet),
            merknadTilByttbarhet(merknadTilByttbarhet) {}
    [[nodiscard]] std::string GetId() const;
    [[nodiscard]] ValueWithDistinguishedName GetKode() const;
    [[nodiscard]] std::string GetGyldigFraDato() const;
    [[nodiscard]] std::string GetBeskrivelseByttbarhet() const;
    [[nodiscard]] bool GetMerknadTilByttbarhet() const;
};


#endif //LEGEMFEST_BYTTEGRUPPE_H
