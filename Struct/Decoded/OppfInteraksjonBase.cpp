//
// Created by sigsegv on 12/29/22.
//

#include "OppfInteraksjonBase.h"

std::string OppfInteraksjonBase::GetId() const {
    return id;
}

std::string OppfInteraksjonBase::GetTidspunkt() const {
    return tidstempel;
}

Status OppfInteraksjonBase::GetStatus() const {
    return status;
}
