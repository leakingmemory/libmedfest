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

class PRefusjonskode;

class PRefusjonskode_0_0_0 {
    friend FestDeserializer;
    friend PRefusjonskode;
private:
    PValueWithCodeset refusjonskode;
    PString gyldigFraDato;
    PString forskrivesTilDato;
    GenericListItems32 underterm;
    GenericListItems32 refusjonsvilkar;
public:
    explicit PRefusjonskode_0_0_0(const PRefusjonskode &);
    PRefusjonskode_0_0_0(const Refusjonskode &, RefRefusjonsvilkarList &, StringList &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator ==(const PRefusjonskode_0_0_0 &other) const;
};

class PRefusjonskode {
    friend FestDeserializer;
    friend PRefusjonskode_0_0_0;
private:
    PValueWithCodeset refusjonskode;
    PString gyldigFraDato;
    PString forskrivesTilDato;
    PString utleveresTilDato;
    GenericListItems32 underterm;
    GenericListItems32 refusjonsvilkar;
public:
    explicit PRefusjonskode(const PRefusjonskode_0_0_0 &);
    PRefusjonskode(const Refusjonskode &, RefRefusjonsvilkarList &, StringList &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator ==(const PRefusjonskode &other) const;
};


#endif //LEGEMFEST_PREFUSJONSKODE_H
