//
// Created by sigsegv on 12/11/22.
//

#ifndef LEGEMFEST_OPPFLEGEMIDDELPAKNING_H
#define LEGEMFEST_OPPFLEGEMIDDELPAKNING_H

#include "Oppf.h"
#include "Status.h"
#include "Legemiddelpakning.h"

class OppfLegemiddelpakning : public Oppf {
private:
    Legemiddelpakning legemiddelpakning;
public:
    OppfLegemiddelpakning() :
            Oppf(), legemiddelpakning() {}
    OppfLegemiddelpakning(const std::string &id, const std::string &tidspunkt, const Status &status, const Legemiddelpakning &legemiddelpakning) :
            Oppf(id, tidspunkt, status), legemiddelpakning(legemiddelpakning) {}
    [[nodiscard]] Legemiddelpakning GetLegemiddelpakning() const;
};

#endif //LEGEMFEST_OPPFLEGEMIDDELPAKNING_H
