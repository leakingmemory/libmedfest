//
// Created by sigsegv on 12/30/22.
//

#include "OppfStrDosering.h"

std::string OppfStrDosering::GetId() const {
    return id;
}

std::string OppfStrDosering::GetTidspunkt() const {
    return tidspunkt;
}

Status OppfStrDosering::GetStatus() const {
    return status;
}

Kortdose OppfStrDosering::GetKortdose() const {
    return kortdose;
}