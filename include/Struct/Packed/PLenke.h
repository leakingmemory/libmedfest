//
// Created by sigsegv on 1/10/23.
//

#ifndef LEGEMFEST_PLENKE_H
#define LEGEMFEST_PLENKE_H

#include "PString.h"

class FestDeserializer_0;
class FestDeserializer_1;
class Lenke;

class PLenke {
    friend FestDeserializer_0;
    friend FestDeserializer_1;
private:
    PString beskrivelse;
    PString www;
public:
    PLenke(const Lenke &lenke, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PLenke &) const;
};


#endif //LEGEMFEST_PLENKE_H
