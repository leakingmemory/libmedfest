//
// Created by sigsegv on 2/11/23.
//

#ifndef LEGEMFEST_PSUBSTANSGRUPPE_H
#define LEGEMFEST_PSUBSTANSGRUPPE_H


#include "GenericListStorage.h"
#include "PString.h"

class FestDeserializer_0;
class FestDeserializer_1;
class Substansgruppe;
class SubstansList;
class FestUuid;

class PSubstansgruppe {
    friend FestDeserializer_0;
    friend FestDeserializer_1;
private:
    GenericListItems32 substans;
    PString navn;
public:
    PSubstansgruppe(const Substansgruppe &, SubstansList &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PSubstansgruppe &other) const;
};


#endif //LEGEMFEST_PSUBSTANSGRUPPE_H
