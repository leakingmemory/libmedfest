//
// Created by sigsegv on 1/19/23.
//

#ifndef LEGEMFEST_PREFUSJON_H
#define LEGEMFEST_PREFUSJON_H

#include "PString.h"
#include "GenericListStorage.h"

class FestDeserializer;
class Refusjon;
class FestUuidList;

class PRefusjon {
    friend FestDeserializer;
private:
    GenericListItems refRefusjonsgruppe;
    PString gyldigFraDato;
    PString forskrivesTilDato;
    PString utleveresTilDato;
public:
    PRefusjon(const Refusjon &, FestUuidList &uuidlist, std::string &strblock);
    bool operator ==(const PRefusjon &) const;
};


#endif //LEGEMFEST_PREFUSJON_H
