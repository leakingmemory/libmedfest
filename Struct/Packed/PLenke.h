//
// Created by sigsegv on 1/10/23.
//

#ifndef LEGEMFEST_PLENKE_H
#define LEGEMFEST_PLENKE_H

#include "PString.h"

class FestDeserializer;
class Lenke;

class PLenke {
    friend FestDeserializer;
private:
    PString beskrivelse;
    PString www;
public:
    PLenke(const Lenke &lenke, std::string &strblock, std::map<std::string,uint32_t> &cache);
};


#endif //LEGEMFEST_PLENKE_H
