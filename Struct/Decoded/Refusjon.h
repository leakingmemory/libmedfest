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
public:
    Refusjon() : refRefusjonsgruppe(), gyldigFraDato() {}
    Refusjon(const std::string &refRefusjonsgruppe, const std::string &gyldigFraDato) :
            refRefusjonsgruppe(refRefusjonsgruppe), gyldigFraDato(gyldigFraDato) {}
    [[nodiscard]] std::string GetRefRefusjonsgruppe() const;
};


#endif //LEGEMFEST_REFUSJON_H
