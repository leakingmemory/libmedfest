//
// Created by sigsegv on 12/23/22.
//

#include "OppfRefusjon.h"

std::string OppfRefusjon::GetId() const {
    return id;
}

std::string OppfRefusjon::GetTidspunkt() const {
    return tidspunkt;
}

Status OppfRefusjon::GetStatus() const {
    return status;
}
