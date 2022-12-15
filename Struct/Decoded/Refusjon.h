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
public:
    Refusjon() : refRefusjonsgruppe(), gyldigFraDato(), forskrivesTilDato() {}
    Refusjon(const std::string &refRefusjonsgruppe, const std::string &gyldigFraDato, const std::string &forskrivesTilDato) :
            refRefusjonsgruppe(refRefusjonsgruppe), gyldigFraDato(gyldigFraDato), forskrivesTilDato{forskrivesTilDato} {}
    [[nodiscard]] std::string GetRefRefusjonsgruppe() const;
    [[nodiscard]] std::string GetGyldigFraDato() const;
    [[nodiscard]] std::string GetForskrivesTilDato() const;
};


#endif //LEGEMFEST_REFUSJON_H
