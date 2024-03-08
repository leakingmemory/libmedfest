//
// Created by sigsegv on 12/26/22.
//

#include <Struct/Decoded/StrukturertVilkar.h>

ValueWithCodeSet StrukturertVilkar::GetType() const {
    return type;
}

ValueWithCodeSet StrukturertVilkar::GetVerdiKodet() const {
    return verdiKodet;
}

std::string StrukturertVilkar::GetVerdiTekst() const {
    return verdiTekst;
}