//
// Created by sigsegv on 2/8/23.
//

#ifndef LEGEMFEST_PSTRUKTURERTVILKAR_H
#define LEGEMFEST_PSTRUKTURERTVILKAR_H

#include "PValueWithCodeset.h"

class FestDeserializer_0;
class FestDeserializer_1;
class StrukturertVilkar;

class PStrukturertVilkar {
    friend FestDeserializer_0;
    friend FestDeserializer_1;
private:
    PValueWithCodeset type;
    PValueWithCodeset verdiKodet;
    PString verdiTekst;
public:
    PStrukturertVilkar(const StrukturertVilkar &, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PStrukturertVilkar &) const;
};


#endif //LEGEMFEST_PSTRUKTURERTVILKAR_H
