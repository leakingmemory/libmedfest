//
// Created by sigsegv on 12/18/22.
//

#include "OppfLegemiddelVirkestoff.h"

std::string OppfLegemiddelVirkestoff::GetId() const {
    return id;
}

std::string OppfLegemiddelVirkestoff::GetTidspunkt() const {
    return tidspunkt;
}

Status OppfLegemiddelVirkestoff::GetStatus() const {
    return status;
}

LegemiddelVirkestoff OppfLegemiddelVirkestoff::GetLegemiddelVirkestoff() const {
    return legemiddelVirkestoff;
}