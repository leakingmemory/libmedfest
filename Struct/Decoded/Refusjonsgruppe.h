//
// Created by sigsegv on 12/25/22.
//

#ifndef LEGEMFEST_REFUSJONSGRUPPE_H
#define LEGEMFEST_REFUSJONSGRUPPE_H

#include "GruppeNr.h"
#include "Atc.h"
#include "Refusjonskode.h"
#include <vector>

class Refusjonsgruppe {
private:
    std::string id;
    GruppeNr gruppeNr;
    Atc atc;
    std::string refusjonsberettigetBruk;
    std::vector<Refusjonskode> refusjonskode;
    std::vector<std::string> refVilkar;
    bool kreverRefusjonskode;
public:
    Refusjonsgruppe() : id(), gruppeNr(), atc(), refusjonsberettigetBruk(), refusjonskode(), refVilkar(),
                        kreverRefusjonskode() {}
    Refusjonsgruppe(const std::string &id, const GruppeNr &gruppeNr, const Atc &atc,
                    const std::string &refusjonsberettigetBruk, const std::vector<Refusjonskode> &refusjonskode,
                    const std::vector<std::string> &refVilkar, bool kreverRefusjonskode) :
            id(id), gruppeNr(gruppeNr), atc(atc), refusjonsberettigetBruk(refusjonsberettigetBruk),
            refusjonskode(refusjonskode), refVilkar(refVilkar), kreverRefusjonskode(kreverRefusjonskode) {}
    [[nodiscard]] std::string GetId() const;
    [[nodiscard]] GruppeNr GetGruppeNr() const;
    [[nodiscard]] Atc GetAtc() const;
    [[nodiscard]] std::string GetRefusjonsberettigetBruk() const;
    [[nodiscard]] std::vector<Refusjonskode> GetRefusjonskode() const;
    [[nodiscard]] std::vector<std::string> GetRefVilkar() const;
    [[nodiscard]] bool GetKreverRefusjonskode() const;
};


#endif //LEGEMFEST_REFUSJONSGRUPPE_H
