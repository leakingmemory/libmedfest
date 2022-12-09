//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_LEGEMIDDELMERKEVARE_H
#define LEGEMFEST_LEGEMIDDELMERKEVARE_H


#include "Legemiddel.h"

class LegemiddelMerkevare : public Legemiddel {
public:
    LegemiddelMerkevare() : Legemiddel() {}
    LegemiddelMerkevare(const Legemiddel &legemiddel) : Legemiddel(legemiddel) {}
};


#endif //LEGEMFEST_LEGEMIDDELMERKEVARE_H
