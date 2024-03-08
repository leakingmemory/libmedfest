//
// Created by sigsegv on 12/18/22.
//

#ifndef LEGEMFEST_OPPFLEGEMIDDELVIRKESTOFF_H
#define LEGEMFEST_OPPFLEGEMIDDELVIRKESTOFF_H

#include "LegemiddelVirkestoff.h"
#include "Oppf.h"

class OppfLegemiddelVirkestoff : public Oppf {
private:
    LegemiddelVirkestoff legemiddelVirkestoff;
public:
    OppfLegemiddelVirkestoff() : Oppf(), legemiddelVirkestoff() {}
    OppfLegemiddelVirkestoff(const Oppf &oppf, const LegemiddelVirkestoff &virkestoff) :
            Oppf(oppf), legemiddelVirkestoff(virkestoff) {}
    OppfLegemiddelVirkestoff(const std::string &id, const std::string &tidspunkt, const Status &status,
                             const LegemiddelVirkestoff &legemiddelVirkestoff) :
            Oppf(id, tidspunkt, status), legemiddelVirkestoff(legemiddelVirkestoff) {}
    [[nodiscard]] LegemiddelVirkestoff GetLegemiddelVirkestoff() const;
};


#endif //LEGEMFEST_OPPFLEGEMIDDELVIRKESTOFF_H
