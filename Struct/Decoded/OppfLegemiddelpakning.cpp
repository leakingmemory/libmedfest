//
// Created by sigsegv on 12/11/22.
//

#include "OppfLegemiddelpakning.h"

std::string OppfLegemiddelpakning::GetId() const {
    return id;
}

std::string OppfLegemiddelpakning::GetTidspunkt() const {
    return tidspunkt;
}

Status OppfLegemiddelpakning::GetStatus() const {
    return status;
}

Legemiddelpakning OppfLegemiddelpakning::GetLegemiddelpakning() const {
    return legemiddelpakning;
}