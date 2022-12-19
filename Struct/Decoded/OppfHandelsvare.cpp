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

MedForbrMatr OppfHandelsvare::GetMedForbrMatr() const {
    return medForbrMatr;
}