//
// Created by sigsegv on 12/29/22.
//

#ifndef LEGEMFEST_OPPFINTERAKSJONBASE_H
#define LEGEMFEST_OPPFINTERAKSJONBASE_H

#include "Oppf.h"

class OppfInteraksjonBase : public Oppf {
public:
    OppfInteraksjonBase() : Oppf() {}
    OppfInteraksjonBase(const Oppf &oppf) : Oppf(oppf) {}
    OppfInteraksjonBase(const std::string &id, const std::string &tidsstempel, const Status &status) :
            Oppf(id, tidsstempel, status) {}
};


#endif //LEGEMFEST_OPPFINTERAKSJONBASE_H
