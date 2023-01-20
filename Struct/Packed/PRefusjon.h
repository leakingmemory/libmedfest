//
// Created by sigsegv on 1/19/23.
//

#ifndef LEGEMFEST_PREFUSJON_H
#define LEGEMFEST_PREFUSJON_H

#include "PFestId.h"
#include "PString.h"

class FestDeserializer;
class Refusjon;

class PRefusjon {
    friend FestDeserializer;
private:
    PFestId refRefusjonsgruppe;
    PString gyldigFraDato;
    PString forskrivesTilDato;
    PString utleveresTilDato;
public:
    PRefusjon(const Refusjon &, std::vector<FestUuid> &uuidblock, std::string &strblock);
};


#endif //LEGEMFEST_PREFUSJON_H
