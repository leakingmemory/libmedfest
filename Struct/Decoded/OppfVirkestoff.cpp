//
// Created by sigsegv on 12/16/22.
//

#include "OppfVirkestoff.h"

std::string OppfVirkestoff::GetId() const {
    return id;
}

Status OppfVirkestoff::GetStatus() const {
    return status;
}

std::string OppfVirkestoff::GetTidspunkt() const {
    return tidspunkt;
}

Virkestoff OppfVirkestoff::GetVirkestoff() const {
    return virkestoff;
}