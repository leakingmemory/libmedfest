//
// Created by sigsegv on 1/10/23.
//

#ifndef LEGEMFEST_PLENKE_H
#define LEGEMFEST_PLENKE_H

#include "PString.h"

class Lenke;

class PLenke {
private:
    PString beskrivelse;
    PString www;
public:
    PLenke(const Lenke &lenke, std::string &strblock);
};


#endif //LEGEMFEST_PLENKE_H
