//
// Created by sigsegv on 2/8/23.
//

#ifndef LEGEMFEST_PSTRUKTURERTVILKAR_H
#define LEGEMFEST_PSTRUKTURERTVILKAR_H

#include "PValueWithCodeset.h"

class FestDeserializer;
class StrukturertVilkar;

class PStrukturertVilkar {
    friend FestDeserializer;
private:
    PValueWithCodeset type;
    PValueWithCodeset verdiKodet;
    PString verdiTekst;
public:
    PStrukturertVilkar(const StrukturertVilkar &, std::string &strblock, std::map<std::string,uint32_t> &cache);
};


#endif //LEGEMFEST_PSTRUKTURERTVILKAR_H
