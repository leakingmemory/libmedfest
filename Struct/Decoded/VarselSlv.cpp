//
// Created by sigsegv on 12/27/22.
//

#include "VarselSlv.h"

ValueWithCodeSet VarselSlv::GetType() const {
    return type;
}

std::string VarselSlv::GetOverskrift() const {
    return overskrift;
}

std::string VarselSlv::GetVarseltekst() const {
    return varseltekst;
}

std::vector<Visningsregel> VarselSlv::GetVisningsregel() const {
    return visningsregel;
}

std::string VarselSlv::GetFraDato() const {
    return fraDato;
}

Lenke VarselSlv::GetLenke() const {
    return lenke;
}

Referanseelement VarselSlv::GetReferanseelement() const {
    return referanseelement;
}
