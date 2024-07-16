//
// Created by sigsegv on 12/29/22.
//

#ifndef LEGEMFEST_OPPFLEGEMIDDELDOSE_H
#define LEGEMFEST_OPPFLEGEMIDDELDOSE_H

#include "Status.h"
#include "Legemiddeldose.h"
#include "Oppf.h"

class POppfLegemiddeldose_0_0_0;
class POppfLegemiddeldose_0_4_0;

class OppfLegemiddeldose : public Oppf {
    friend POppfLegemiddeldose_0_0_0;
    friend POppfLegemiddeldose_0_4_0;
private:
    Legemiddeldose legemiddeldose;
public:
    OppfLegemiddeldose() : Oppf(), legemiddeldose() {}
    OppfLegemiddeldose(const Oppf &oppf, const Legemiddeldose &legemiddeldose) :
            Oppf(oppf), legemiddeldose(legemiddeldose) {}
    OppfLegemiddeldose(const std::string &id, const std::string &tidspunkt, const Status &status,
                       const Legemiddeldose &legemiddeldose) :
            Oppf(id, tidspunkt, status), legemiddeldose(legemiddeldose) {}
    [[nodiscard]] Legemiddeldose GetLegemiddeldose() const;
};


#endif //LEGEMFEST_OPPFLEGEMIDDELDOSE_H
