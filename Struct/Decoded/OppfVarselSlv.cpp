//
// Created by sigsegv on 12/26/22.
//

#include "OppfVarselSlv.h"

std::string OppfVarselSlv::GetId() const {
    return id;
}

std::string OppfVarselSlv::GetTidspunkt() const {
    return tidspunkt;
}

Status OppfVarselSlv::GetStatus() const {
    return status;
}

VarselSlv OppfVarselSlv::GetVarselSlv() const {
    return varselSlv;
}