//
// Created by sigsegv on 12/19/22.
//

#include "OppfHandelsvare.h"

std::string OppfHandelsvare::GetId() const {
    return id;
}

std::string OppfHandelsvare::GetTidspunkt() const {
    return tidspunkt;
}

Status OppfHandelsvare::GetStatus() const {
    return status;
}

MedForbrMatr OppfMedForbrMatr::GetMedForbrMatr() const {
    return medForbrMatr;
}

Naringsmiddel OppfNaringsmiddel::GetNaringsmiddel() const {
    return naringsmiddel;
}