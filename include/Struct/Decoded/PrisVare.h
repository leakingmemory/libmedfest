//
// Created by sigsegv on 12/12/22.
//

#ifndef LEGEMFEST_PRISVARE_H
#define LEGEMFEST_PRISVARE_H

#include "ValueWithCodeSet.h"
#include "Pris.h"

class PrisVare {
private:
    ValueWithCodeSet type;
    Pris pris;
    std::string gyldigFraDato;
    std::string gyldigTilDato;
public:
    PrisVare() : type(), pris(), gyldigFraDato(), gyldigTilDato() {}
    PrisVare(const ValueWithCodeSet &type, const Pris &pris, const std::string &gyldigFraDato,
             const std::string &gyldigTilDato) :
            type(type), pris(pris), gyldigFraDato(gyldigFraDato), gyldigTilDato(gyldigTilDato) {}
    [[nodiscard]] ValueWithCodeSet GetType() const;
    [[nodiscard]] Pris GetPris() const;
    [[nodiscard]] std::string GetGyldigFraDato() const;
    [[nodiscard]] std::string GetGyldigTilDato() const;
};


#endif //LEGEMFEST_PRISVARE_H
