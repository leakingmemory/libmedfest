//
// Created by sigsegv on 1/19/23.
//

#ifndef LEGEMFEST_PPRISVARE_H
#define LEGEMFEST_PPRISVARE_H

#include "PValueWithCodeset.h"
#include "PValueUnit.h"

class FestDeserializer_0;
class FestDeserializer_1;
class PrisVare;

class PPrisVare {
    friend FestDeserializer_0;
    friend FestDeserializer_1;
private:
    PValueWithCodeset type;
    PString gyldigFraDato;
    PString gyldigTilDato;
    PValueUnit pris;
public:
    PPrisVare(const PrisVare &, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PPrisVare &) const;
};


#endif //LEGEMFEST_PPRISVARE_H
