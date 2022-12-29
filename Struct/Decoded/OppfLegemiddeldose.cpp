//
// Created by sigsegv on 12/29/22.
//

#include "OppfLegemiddeldose.h"

std::string OppfLegemiddeldose::GetId() const {
    return id;
}

std::string OppfLegemiddeldose::GetTidspunkt() const {
    return tidspunkt;
}

Status OppfLegemiddeldose::GetStatus() const {
    return status;
}

Legemiddeldose OppfLegemiddeldose::GetLegemiddeldose() const {
    return legemiddeldose;
}