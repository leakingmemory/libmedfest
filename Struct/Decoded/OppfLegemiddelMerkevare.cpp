//
// Created by jeo on 12/9/22.
//

#include "OppfLegemiddelMerkevare.h"

std::string OppfLegemiddelMerkevare::GetId() const {
    return id;
}

std::string OppfLegemiddelMerkevare::GetTidspunkt() const {
    return tidspunkt;
}

Status OppfLegemiddelMerkevare::GetStatus() const {
    return status;
}

LegemiddelMerkevare OppfLegemiddelMerkevare::GetLegemiddelMerkevare() const {
    return legemiddelMerkevare;
}