//
// Created by sigsegv on 12/26/22.
//

#ifndef LEGEMFEST_OPPFVARSELSLV_H
#define LEGEMFEST_OPPFVARSELSLV_H

#include "Oppf.h"
#include "VarselSlv.h"

class POppfVarselSlv_0_4_0;
class POppfVarselSlv_0_0_0;

class OppfVarselSlv : public Oppf {
    friend POppfVarselSlv_0_4_0;
    friend POppfVarselSlv_0_0_0;
private:
    VarselSlv varselSlv;
public:
    OppfVarselSlv() : Oppf(), varselSlv() {}
    OppfVarselSlv(const Oppf &oppf, const VarselSlv &varselSlv) :
            Oppf(oppf), varselSlv(varselSlv) {}
    OppfVarselSlv(const std::string &id, const std::string &tidspunkt, const Status &status, const VarselSlv &varselSlv) :
            Oppf(id, tidspunkt, status), varselSlv(varselSlv) {}
    [[nodiscard]] VarselSlv GetVarselSlv() const;
};


#endif //LEGEMFEST_OPPFVARSELSLV_H
