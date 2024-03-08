//
// Created by sigsegv on 2/19/23.
//

#ifndef LEGEMFEST_FESTVECTORS_H
#define LEGEMFEST_FESTVECTORS_H

#include <string>
#include "Struct/Packed/PFest.h"

class FestVectors {
private:
    std::string dato;
    const PFest &fest;
    const uint16_t* legemiddelMerkevare;
    const uint16_t* legemiddelpakning;
    const uint16_t* legemiddelVirkestoff;
    const uint16_t* medForbrMatr;
    const uint16_t* naringsmiddel;
    const uint16_t* brystprotese;
    const uint16_t* legemiddeldose;
    const uint16_t* virkestoffMedStyrke;
    const uint16_t* virkestoff;
    const uint16_t* kodeverk;
    const uint16_t* refusjon;
    const uint16_t* vilkar;
    const uint16_t* varselSlv;
    const uint16_t* byttegruppe;
    const uint16_t* interaksjon;
    const uint16_t* interaksjonIkkeVurdert;
    const uint16_t* strDosering;
public:
    FestVectors(const PFest &, const std::string &dato, const uint16_t *uint16List, size_t sizeUint16List);
    [[nodiscard]] std::string GetDato() const;
};


#endif //LEGEMFEST_FESTVECTORS_H
