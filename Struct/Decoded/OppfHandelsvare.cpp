//
// Created by sigsegv on 12/19/22.
//

#include "OppfHandelsvare.h"

std::string OppfHandelsvare::GetId() {
    return id;
}

std::string OppfHandelsvare::GetTidspunkt() {
    return tidspunkt;
}

Status OppfHandelsvare::GetStatus() {
    return status;
}
