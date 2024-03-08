//
// Created by sigsegv on 12/25/22.
//

#ifndef LEGEMFEST_REFUSJONSKODE_H
#define LEGEMFEST_REFUSJONSKODE_H

#include "ValueWithCodeSet.h"
#include "RefRefusjonsvilkar.h"
#include <vector>

class PRefusjonskode;

class Refusjonskode {
    friend PRefusjonskode;
private:
    ValueWithCodeSet refusjonskode;
    std::string gyldigFraDato;
    std::string forskrivesTilDato;
    std::vector<std::string> underterm;
    std::vector<RefRefusjonsvilkar> refusjonsvilkar;
public:
    Refusjonskode() : refusjonskode(), gyldigFraDato(), forskrivesTilDato(), underterm(), refusjonsvilkar() {}
    Refusjonskode(const ValueWithCodeSet &refusjonskode, const std::string &gyldigFraDato,
                  const std::string &forskrivesTilDato, const std::vector<std::string> &underterm,
                  const std::vector<RefRefusjonsvilkar> &refusjonsvilkar) :
            refusjonskode(refusjonskode), gyldigFraDato(gyldigFraDato), forskrivesTilDato(forskrivesTilDato),
            underterm(underterm), refusjonsvilkar(refusjonsvilkar) {}
    [[nodiscard]] ValueWithCodeSet GetRefusjonskode() const;
    [[nodiscard]] std::string GetGyldigFraDato() const;
    [[nodiscard]] std::string GetForskrivesTilDato() const;
    [[nodiscard]] std::vector<std::string> GetUnderterm() const;
    [[nodiscard]] std::vector<RefRefusjonsvilkar> GetRefusjonsvilkar() const;
};


#endif //LEGEMFEST_REFUSJONSKODE_H
