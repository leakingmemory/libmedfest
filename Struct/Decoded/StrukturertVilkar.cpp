//
// Created by sigsegv on 12/26/22.
//

#include "StrukturertVilkar.h"

ValueWithCodeSet StrukturertVilkar::GetType() const {
    return type;
}

ValueWithCodeSet StrukturertVilkar::GetVerdiKodet() const {
    return verdiKodet;
}

std::string StrukturertVilkar::GetVerdiTekst() const {
    return verdiTekst;
}