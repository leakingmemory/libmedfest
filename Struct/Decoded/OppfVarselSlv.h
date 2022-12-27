//
// Created by sigsegv on 12/26/22.
//

#ifndef LEGEMFEST_OPPFVARSELSLV_H
#define LEGEMFEST_OPPFVARSELSLV_H

#include "Status.h"
#include "VarselSlv.h"

class OppfVarselSlv {
private:
    std::string id;
    std::string tidspunkt;
    Status status;
    VarselSlv varselSlv;
public:
    OppfVarselSlv() : id(), tidspunkt(), status() {}
    OppfVarselSlv(const std::string &id, const std::string &tidspunkt, const Status &status, const VarselSlv &varselSlv) :
            id(id), tidspunkt(tidspunkt), status(status), varselSlv(varselSlv) {}
    [[nodiscard]] std::string GetId() const;
    [[nodiscard]] std::string GetTidspunkt() const;
    [[nodiscard]] Status GetStatus() const;
    [[nodiscard]] VarselSlv GetVarselSlv() const;
};


#endif //LEGEMFEST_OPPFVARSELSLV_H
