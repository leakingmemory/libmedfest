//
// Created by sigsegv on 2/8/23.
//

#ifndef LEGEMFEST_PVILKAR_H
#define LEGEMFEST_PVILKAR_H

#include "PStrukturertVilkar.h"
#include "PFestId.h"
#include <vector>
#include <map>

class FestDeserializer_0;
class FestDeserializer_1;
class Vilkar;
class FestUuid;

class PVilkar : public PStrukturertVilkar {
    friend FestDeserializer_0;
    friend FestDeserializer_1;
private:
    PValueWithDistinguishedName gjelderFor;
    PValueWithCodeset gruppe;
    PString id;
    PString vilkarNr;
    PString tekst;
    PString gyldigFraDato;
public:
    PVilkar(const Vilkar &, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PVilkar &) const;
};


#endif //LEGEMFEST_PVILKAR_H
