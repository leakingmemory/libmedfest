//
// Created by sigsegv on 12/17/22.
//

#include "VirkestoffMedStyrke.h"

std::string VirkestoffMedStyrke::GetId() const {
    return id;
}

std::string VirkestoffMedStyrke::GetRefVirkestoff() const {
    return refVirkestoff;
}

Styrke VirkestoffMedStyrke::GetStyrke() const {
    return styrke;
}

Styrkenevner VirkestoffMedStyrke::GetStyrkenevner() const {
    return styrkenevner;
}

Styrkeoperator VirkestoffMedStyrke::GetStyrkeoperator() const {
    return styrkeoperator;
}

Styrke VirkestoffMedStyrke::GetAlternativStyrke() const {
    return alternativStyrke;
}

Styrkenevner VirkestoffMedStyrke::GetAlternativStyrkenevner() const {
    return alternativStyrkenevner;
}

Atc VirkestoffMedStyrke::GetAtcKombipreparat() const {
    return atcKombipreparat;
}

double VirkestoffMedStyrke::GetStyrkeOvreVerdi() const {
    return styrkeOvreVerdi;
}