//
// Created by sigsegv on 1/19/23.
//

#ifndef LEGEMFEST_PPRISVARE_H
#define LEGEMFEST_PPRISVARE_H

#include "PValueWithCodeset.h"
#include "PValueUnit.h"

class FestDeserializer;
class PrisVare;

class PPrisVare {
    friend FestDeserializer;
private:
    PValueWithCodeset type;
    PString gyldigFraDato;
    PString gyldigTilDato;
    PValueUnit pris;
public:
    PPrisVare(const PrisVare &, std::string &strblock);
    bool operator == (const PPrisVare &) const;
};


#endif //LEGEMFEST_PPRISVARE_H
