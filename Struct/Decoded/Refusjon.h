//
// Created by sigsegv on 12/13/22.
//

#ifndef LEGEMFEST_REFUSJON_H
#define LEGEMFEST_REFUSJON_H

#include <string>

class Refusjon {
private:
    std::string refRefusjonsgruppe;
    std::string gyldigFraDato;
    std::string forskrivesTilDato;
    std::string utleveresTilDato;
public:
    Refusjon() : refRefusjonsgruppe(), gyldigFraDato(), forskrivesTilDato(), utleveresTilDato() {}
    Refusjon(const std::string &refRefusjonsgruppe, const std::string &gyldigFraDato,
             const std::string &forskrivesTilDato, const std::string &utleveresTilDato) :
            refRefusjonsgruppe(refRefusjonsgruppe), gyldigFraDato(gyldigFraDato), forskrivesTilDato{forskrivesTilDato},
            utleveresTilDato(utleveresTilDato) {}
    [[nodiscard]] std::string GetRefRefusjonsgruppe() const;
    [[nodiscard]] std::string GetGyldigFraDato() const;
    [[nodiscard]] std::string GetForskrivesTilDato() const;
    [[nodiscard]] std::string GetUtleveresTilDato() const;
};


#endif //LEGEMFEST_REFUSJON_H
