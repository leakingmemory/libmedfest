//
// Created by sigsegv on 12/30/22.
//

#include <Struct/Decoded/Substansgruppe.h>

std::vector<Substans> Substansgruppe::GetSubstans() const {
    return substans;
}

std::string Substansgruppe::GetNavn() const {
    return navn;
}