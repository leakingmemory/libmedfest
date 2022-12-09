//
// Created by jeo on 12/9/22.
//

#include "OppfLegemiddelMerkevare.h"

std::string OppfLegemiddelMerkevare::GetId() {
    return id;
}

std::string OppfLegemiddelMerkevare::GetTidspunkt() {
    return tidspunkt;
}

Status OppfLegemiddelMerkevare::GetStatus() {
    return status;
}