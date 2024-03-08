//
// Created by sigsegv on 12/17/22.
//

#ifndef LEGEMFEST_OPPFVIRKESTOFFMEDSTYRKE_H
#define LEGEMFEST_OPPFVIRKESTOFFMEDSTYRKE_H

#include "VirkestoffMedStyrke.h"
#include "Oppf.h"

class POppfVirkestoffMedStyrke;

class OppfVirkestoffMedStyrke : public Oppf {
    friend POppfVirkestoffMedStyrke;
private:
    VirkestoffMedStyrke virkestoffMedStyrke;
public:
    OppfVirkestoffMedStyrke() : Oppf(), virkestoffMedStyrke() {}
    OppfVirkestoffMedStyrke(const Oppf &oppf, const VirkestoffMedStyrke &virkestoffMedStyrke) :
            Oppf(oppf), virkestoffMedStyrke(virkestoffMedStyrke) {}
    OppfVirkestoffMedStyrke(const std::string &id, const std::string &tidspunkt, const Status &status,
                            const VirkestoffMedStyrke &virkestoffMedStyrke) :
            Oppf(id, tidspunkt, status), virkestoffMedStyrke(virkestoffMedStyrke) {}
    [[nodiscard]] VirkestoffMedStyrke GetVirkestoffMedStyrke() const;
};


#endif //LEGEMFEST_OPPFVIRKESTOFFMEDSTYRKE_H
