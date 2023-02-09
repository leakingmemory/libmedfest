//
// Created by sigsegv on 2/8/23.
//

#ifndef LEGEMFEST_PVILKAR_H
#define LEGEMFEST_PVILKAR_H

#include "PStrukturertVilkar.h"
#include "PFestId.h"
#include <vector>
#include <map>

class FestDeserializer;
class Vilkar;
class FestUuid;

class PVilkar : public PStrukturertVilkar {
    friend FestDeserializer;
private:
    PValueWithDistinguishedName gjelderFor;
    PValueWithCodeset gruppe;
    PString id;
    PString vilkarNr;
    PString tekst;
    PString gyldigFraDato;
public:
    PVilkar(const Vilkar &, std::string &strblock, std::map<std::string,uint32_t> &cache);
};


#endif //LEGEMFEST_PVILKAR_H
