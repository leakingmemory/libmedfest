//
// Created by sigsegv on 12/26/22.
//

#ifndef LEGEMFEST_VILKAR_H
#define LEGEMFEST_VILKAR_H

#include "Gruppe.h"
#include "GjelderFor.h"
#include "StrukturertVilkar.h"
#include <string>

class PVilkar;

class Vilkar {
    friend PVilkar;
private:
    std::string id;
    std::string vilkarNr;
    Gruppe gruppe;
    GjelderFor gjelderFor;
    std::string tekst;
    std::string gyldigFraDato;
    StrukturertVilkar strukturertVilkar;
public:
    Vilkar() : id(), vilkarNr(), gruppe(), gjelderFor(), tekst(), gyldigFraDato(), strukturertVilkar() {}
    Vilkar(const std::string &id, const std::string &vilkarNr, const Gruppe &gruppe, const GjelderFor &gjelderFor,
           const std::string &tekst, const std::string &gyldigFraDato, const StrukturertVilkar &strukturertVilkar) :
            id(id), vilkarNr(vilkarNr), gruppe(gruppe), gjelderFor(gjelderFor), tekst(tekst),
            gyldigFraDato(gyldigFraDato), strukturertVilkar(strukturertVilkar) {}
    [[nodiscard]] std::string GetId() const;
    [[nodiscard]] std::string GetVilkarNr() const;
    [[nodiscard]] Gruppe GetGruppe() const;
    [[nodiscard]] GjelderFor GetGjelderFor() const;
    [[nodiscard]] std::string GetTekst() const;
    [[nodiscard]] std::string GetGyldigFraDato() const;
    [[nodiscard]] StrukturertVilkar GetStrukturertVilkar() const;
};


#endif //LEGEMFEST_VILKAR_H
