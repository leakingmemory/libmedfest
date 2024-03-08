//
// Created by sigsegv on 12/30/22.
//

#include <Struct/Decoded/Legemiddelforbruk.h>

int Legemiddelforbruk::GetLopenr() const {
    return lopenr;
}

int Legemiddelforbruk::GetIterasjoner() const {
    return iterasjoner;
}

double Legemiddelforbruk::GetMengde() const {
    return mengde;
}

std::string Legemiddelforbruk::GetPeriode() const {
    return periode;
}

std::vector<Dosering> Legemiddelforbruk::GetDosering() const {
    return dosering;
}
