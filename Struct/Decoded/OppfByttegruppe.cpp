//
// Created by sigsegv on 12/28/22.
//

#include "OppfByttegruppe.h"

std::string OppfByttegruppe::GetId() const {
    return id;
}

std::string OppfByttegruppe::GetTidspunkt() const {
    return tidspunkt;
}

Status OppfByttegruppe::GetStatus() const {
    return status;
}

Byttegruppe OppfByttegruppe::GetByttegruppe() const {
    return byttegruppe;
}