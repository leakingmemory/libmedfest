//
// Created by sigsegv on 12/26/22.
//

#ifndef LEGEMFEST_OPPFVILKAR_H
#define LEGEMFEST_OPPFVILKAR_H

#include "Oppf.h"
#include "Vilkar.h"

class POppfVilkar;

class OppfVilkar : public Oppf {
    friend POppfVilkar;
private:
    Vilkar vilkar;
public:
    OppfVilkar() : Oppf(), vilkar() {}
    OppfVilkar(const Oppf &oppf, const Vilkar &vilkar) :
            Oppf(oppf), vilkar(vilkar) {}
    OppfVilkar(const std::string &id, const std::string &tidspunkt, const Status &status, const Vilkar &vilkar) :
            Oppf(id, tidspunkt, status), vilkar(vilkar) {}
    [[nodiscard]] Vilkar GetVilkar() const;
};


#endif //LEGEMFEST_OPPFVILKAR_H
