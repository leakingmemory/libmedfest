//
// Created by sigsegv on 12/11/22.
//

#ifndef LEGEMFEST_OPPFLEGEMIDDELPAKNING_H
#define LEGEMFEST_OPPFLEGEMIDDELPAKNING_H

#include "Status.h"
#include "Legemiddelpakning.h"

class OppfLegemiddelpakning {
private:
    std::string id;
    std::string tidspunkt;
    Status status;
    Legemiddelpakning legemiddelpakning;
public:
    OppfLegemiddelpakning() :
            id(), tidspunkt(), status(), legemiddelpakning() {}
    OppfLegemiddelpakning(const std::string &id, const std::string &tidspunkt, const Status &status, const Legemiddelpakning &legemiddelpakning) :
            id(id), tidspunkt(tidspunkt), status(status), legemiddelpakning(legemiddelpakning) {}
    [[nodiscard]] std::string GetId() const;
    [[nodiscard]] std::string GetTidspunkt() const;
    [[nodiscard]] Status GetStatus() const;
    [[nodiscard]] Legemiddelpakning GetLegemiddelpakning() const;
};

#endif //LEGEMFEST_OPPFLEGEMIDDELPAKNING_H
