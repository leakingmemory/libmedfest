//
// Created by sigsegv on 12/16/22.
//

#ifndef LEGEMFEST_OPPFVIRKESTOFF_H
#define LEGEMFEST_OPPFVIRKESTOFF_H

#include "Status.h"
#include "Virkestoff.h"
#include "Oppf.h"

class POppfVirkestoff;

class OppfVirkestoff : public Oppf {
    friend POppfVirkestoff;
private:
    Virkestoff virkestoff;
public:
    OppfVirkestoff() : Oppf(), virkestoff() {}
    OppfVirkestoff(const Oppf &oppf, const Virkestoff &virkestoff) :
            Oppf(oppf), virkestoff(virkestoff) {}
    OppfVirkestoff(const std::string &id, const std::string &tidspunkt, const Status &status, const Virkestoff &virkestoff) :
            Oppf(id, tidspunkt, status), virkestoff(virkestoff) {}
    [[nodiscard]] Virkestoff GetVirkestoff() const;
};


#endif //LEGEMFEST_OPPFVIRKESTOFF_H
