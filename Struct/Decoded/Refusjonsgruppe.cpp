//
// Created by sigsegv on 12/25/22.
//

#include "Refusjonsgruppe.h"

std::string Refusjonsgruppe::GetId() const {
    return id;
}

GruppeNr Refusjonsgruppe::GetGruppeNr() const {
    return gruppeNr;
}

Atc Refusjonsgruppe::GetAtc() const {
    return atc;
}

std::string Refusjonsgruppe::GetRefusjonsberettigetBruk() const {
    return refusjonsberettigetBruk;
}

std::vector<Refusjonskode> Refusjonsgruppe::GetRefusjonskode() const {
    return refusjonskode;
}

std::vector<std::string> Refusjonsgruppe::GetRefVilkar() const {
    return refVilkar;
}

bool Refusjonsgruppe::GetKreverRefusjonskode() const {
    return kreverRefusjonskode;
}