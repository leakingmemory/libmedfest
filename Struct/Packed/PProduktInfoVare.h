//
// Created by sigsegv on 1/29/23.
//

#ifndef LEGEMFEST_PPRODUKTINFOVARE_H
#define LEGEMFEST_PPRODUKTINFOVARE_H

#include "PValueWithCodeset.h"

class ProduktInfoVare;

class PProduktInfoVare {
private:
    PValueWithCodeset enhetStorrelse;
    PString produktNr;
    PString volum;
    uint16_t antPerPakning;
    uint8_t tillattMerMakspris;
public:
    PProduktInfoVare(const ProduktInfoVare &produktInfoVare, std::string &strblock);
};


#endif //LEGEMFEST_PPRODUKTINFOVARE_H
