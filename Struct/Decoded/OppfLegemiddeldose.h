//
// Created by sigsegv on 12/29/22.
//

#ifndef LEGEMFEST_OPPFLEGEMIDDELDOSE_H
#define LEGEMFEST_OPPFLEGEMIDDELDOSE_H

#include "Status.h"
#include "Legemiddeldose.h"

class OppfLegemiddeldose {
private:
    std::string id;
    std::string tidspunkt;
    Status status;
    Legemiddeldose legemiddeldose;
public:
    OppfLegemiddeldose() : id(), tidspunkt(), status(), legemiddeldose() {}
    OppfLegemiddeldose(const std::string &id, const std::string &tidspunkt, const Status &status,
                       const Legemiddeldose &legemiddeldose) :
            id(id), tidspunkt(tidspunkt), status(status), legemiddeldose(legemiddeldose) {}
    [[nodiscard]] std::string GetId() const;
    [[nodiscard]] std::string GetTidspunkt() const;
    [[nodiscard]] Status GetStatus() const;
    [[nodiscard]] Legemiddeldose GetLegemiddeldose() const;
};


#endif //LEGEMFEST_OPPFLEGEMIDDELDOSE_H
