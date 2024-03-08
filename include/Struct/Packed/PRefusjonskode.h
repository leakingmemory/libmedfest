//
// Created by sigsegv on 2/6/23.
//

#ifndef LEGEMFEST_PREFUSJONSKODE_H
#define LEGEMFEST_PREFUSJONSKODE_H

#include "PValueWithCodeset.h"
#include "GenericListStorage.h"

class FestDeserializer;
class Refusjonskode;
class RefRefusjonsvilkarList;
class StringList;
class FestUuid;

class PRefusjonskode {
    friend FestDeserializer;
private:
    PValueWithCodeset refusjonskode;
    PString gyldigFraDato;
    PString forskrivesTilDato;
    GenericListItems underterm;
    GenericListItems refusjonsvilkar;
public:
    PRefusjonskode(const Refusjonskode &, RefRefusjonsvilkarList &, StringList &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator ==(const PRefusjonskode &other) const;
};


#endif //LEGEMFEST_PREFUSJONSKODE_H
