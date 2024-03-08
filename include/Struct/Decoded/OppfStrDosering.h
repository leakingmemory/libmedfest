//
// Created by sigsegv on 12/30/22.
//

#ifndef LEGEMFEST_OPPFSTRDOSERING_H
#define LEGEMFEST_OPPFSTRDOSERING_H

#include "Oppf.h"
#include "Kortdose.h"

class POppfStrDosering;

class OppfStrDosering : public Oppf {
    friend POppfStrDosering;
private:
    Kortdose kortdose;
public:
    OppfStrDosering() : Oppf(), kortdose() {}
    OppfStrDosering(const Oppf &oppf, const Kortdose &kortdose) : Oppf(oppf), kortdose(kortdose) {}
    OppfStrDosering(const std::string &id, const std::string &tidspunkt, const Status &status, const Kortdose &kortdose) :
            Oppf(id, tidspunkt, status), kortdose(kortdose) {}
    [[nodiscard]] Kortdose GetKortdose() const;
};


#endif //LEGEMFEST_OPPFSTRDOSERING_H
