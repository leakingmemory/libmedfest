//
// Created by sigsegv on 12/30/22.
//

#ifndef LEGEMFEST_OPPFSTRDOSERING_H
#define LEGEMFEST_OPPFSTRDOSERING_H

#include "Status.h"
#include "Kortdose.h"

class OppfStrDosering {
private:
    std::string id;
    std::string tidspunkt;
    Status status;
    Kortdose kortdose;
public:
    OppfStrDosering() : id(), tidspunkt(), status(), kortdose() {}
    OppfStrDosering(const std::string &id, const std::string &tidspunkt, const Status &status, const Kortdose &kortdose) :
            id(id), tidspunkt(tidspunkt), status(status), kortdose(kortdose) {}
    [[nodiscard]] std::string GetId() const;
    [[nodiscard]] std::string GetTidspunkt() const;
    [[nodiscard]] Status GetStatus() const;
    [[nodiscard]] Kortdose GetKortdose() const;
};


#endif //LEGEMFEST_OPPFSTRDOSERING_H
