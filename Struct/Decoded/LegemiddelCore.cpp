//
// Created by sigsegv on 12/11/22.
//

#include <Struct/Decoded/LegemiddelCore.h>

Atc LegemiddelCore::GetAtc() const {
    return atc;
}

std::string LegemiddelCore::GetNavnFormStyrke() const {
    return navnFormStyrke;
}

Reseptgruppe LegemiddelCore::GetReseptgruppe() const {
    return reseptgruppe;
}

LegemiddelformKort LegemiddelCore::GetLegemiddelformKort() const {
    return legemiddelformKort;
}

std::vector<std::string> LegemiddelCore::GetRefVilkar() const {
    return refVilkar;
}

TypeSoknadSlv LegemiddelCore::GetTypeSoknadSlv() const {
    return typeSoknadSlv;
}

MaybeBoolean LegemiddelCore::GetOpioidsoknad() const {
    return opioidsoknad;
}

SvartTrekant LegemiddelCore::GetSvartTrekant() const {
    return svartTrekant;
}