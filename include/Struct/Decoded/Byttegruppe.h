//
// Created by sigsegv on 12/29/22.
//

#ifndef LEGEMFEST_BYTTEGRUPPE_H
#define LEGEMFEST_BYTTEGRUPPE_H

#include "ValueWithDistinguishedName.h"
#include <string>

class PByttegruppe_0_0_0;
class PByttegruppe_1_5_0;

class Byttegruppe {
    friend PByttegruppe_0_0_0;
    friend PByttegruppe_1_5_0;
private:
    std::string id;
    ValueWithDistinguishedName kode;
    std::string gyldigFraDato;
    std::string gyldigTilDato;
    std::string beskrivelseByttbarhet;
    bool merknadTilByttbarhet;
public:
    Byttegruppe();
    Byttegruppe(const std::string &id, const ValueWithDistinguishedName &kode, const std::string &gyldigFraDato,
                const std::string &gyldigTilDato, const std::string &beskrivelseByttbarhet, bool merknadTilByttbarhet);
    ~Byttegruppe();
    [[nodiscard]] std::string GetId() const;
    [[nodiscard]] ValueWithDistinguishedName GetKode() const;
    [[nodiscard]] std::string GetGyldigFraDato() const;
    [[nodiscard]] std::string GetGyldigTilDato() const;
    [[nodiscard]] std::string GetBeskrivelseByttbarhet() const;
    [[nodiscard]] bool GetMerknadTilByttbarhet() const;
};


#endif //LEGEMFEST_BYTTEGRUPPE_H
