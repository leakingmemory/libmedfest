//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_LEGEMIDDELMERKEVARE_H
#define LEGEMFEST_LEGEMIDDELMERKEVARE_H


#include "Legemiddel.h"
#include "Preparattype.h"

class LegemiddelMerkevare : public Legemiddel {
private:
    Preparattype preparattype;
public:
    LegemiddelMerkevare() : Legemiddel(), preparattype() {}
    LegemiddelMerkevare(const Legemiddel &legemiddel, const Preparattype &preparattype) : Legemiddel(legemiddel), preparattype(preparattype) {}
    [[nodiscard]] Preparattype GetPreparattype() const;
};


#endif //LEGEMFEST_LEGEMIDDELMERKEVARE_H
