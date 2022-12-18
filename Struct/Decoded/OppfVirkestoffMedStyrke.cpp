//
// Created by sigsegv on 12/17/22.
//

#include "OppfVirkestoffMedStyrke.h"

std::string OppfVirkestoffMedStyrke::GetId() const {
    return id;
}

std::string OppfVirkestoffMedStyrke::GetTidspunkt() const {
    return tidspunkt;
}

Status OppfVirkestoffMedStyrke::GetStatus() const {
    return status;
}

VirkestoffMedStyrke OppfVirkestoffMedStyrke::GetVirkestoffMedStyrke() const {
    return virkestoffMedStyrke;
}