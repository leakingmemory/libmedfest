//
// Created by sigsegv on 2/11/23.
//

#ifndef LEGEMFEST_PINTERAKSJON_H
#define LEGEMFEST_PINTERAKSJON_H

#include "PValueWithDistinguishedName.h"
#include "PFestId.h"
#include "GenericListStorage.h"

class FestDeserializer_0;
class FestDeserializer_1;
class Interaksjon;
class ReferanseList;
class SubstansgruppeList;
class SubstansList;
class ValueWithCodesetList;
class FestUuid;

class PInteraksjon {
    friend FestDeserializer_0;
    friend FestDeserializer_1;
private:
    PValueWithDistinguishedName relevans;
    PValueWithDistinguishedName kildegrunnlag;
    GenericListItems32 visningsregel;
    GenericListItems32 referanse;
    GenericListItems32 substansgruppe;
    PFestId id;
    PString kliniskKonsekvens;
    PString interaksjonsmekanisme;
    PString handtering;
    PString situasjonskriterium;
public:
    PInteraksjon(const Interaksjon &interaksjon, ReferanseList &, SubstansgruppeList &, SubstansList &, ValueWithCodesetList &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PInteraksjon &) const;
};


#endif //LEGEMFEST_PINTERAKSJON_H
