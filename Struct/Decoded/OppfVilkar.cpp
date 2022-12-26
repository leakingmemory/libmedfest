//
// Created by sigsegv on 12/26/22.
//

#include "OppfVilkar.h"

std::string OppfVilkar::GetId() const {
    return id;
}

std::string OppfVilkar::GetTidpunkt() const {
    return tidspunkt;
}

Status OppfVilkar::GetStatus() const {
    return status;
}

Vilkar OppfVilkar::GetVilkar() const {
    return vilkar;
}