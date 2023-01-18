//
// Created by sigsegv on 1/10/23.
//

#ifndef LEGEMFEST_PPREPARATOMTALEAVSNITT_H
#define LEGEMFEST_PPREPARATOMTALEAVSNITT_H


#include "PValueWithDistinguishedName.h"
#include "PLenke.h"

class FestDeserializer;
class Preparatomtaleavsnitt;

class PPreparatomtaleavsnitt {
    friend FestDeserializer;
private:
    PValueWithDistinguishedName avsnittoverskrift;
    PLenke lenke;
public:
    PPreparatomtaleavsnitt(const Preparatomtaleavsnitt &preparatomtaleavsnitt, std::string &strblock);
};


#endif //LEGEMFEST_PPREPARATOMTALEAVSNITT_H
