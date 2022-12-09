//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_LEGEMIDDEL_H
#define LEGEMFEST_LEGEMIDDEL_H


#include "Atc.h"

class Legemiddel {
private:
    Atc atc;
    std::string navnFormStyrke;
public:
    Legemiddel() : atc() {}
    Legemiddel(const Atc &atc, const std::string &navnFormStyrke) : atc(atc), navnFormStyrke(navnFormStyrke) {}
    [[nodiscard]] Atc GetAtc() const;
    [[nodiscard]] std::string GetNavnFormStyrke() const;
};


#endif //LEGEMFEST_LEGEMIDDEL_H
