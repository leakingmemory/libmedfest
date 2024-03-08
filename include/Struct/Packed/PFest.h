//
// Created by sigsegv on 2/18/23.
//

#ifndef LEGEMFEST_PFEST_H
#define LEGEMFEST_PFEST_H

#include "GenericListStorage.h"
#include "PString.h"

class FestDeserializer;
class FestVectors;
class FestData;
class Uint16List;

class PFest {
    friend FestDeserializer;
    friend FestVectors;
private:
    PString dato;
    GenericListItems legemiddelMerkevare;
    GenericListItems legemiddelpakning;
    GenericListItems legemiddelVirkestoff;
    GenericListItems medForbrMatr;
    GenericListItems naringsmiddel;
    GenericListItems brystprotese;
    GenericListItems legemiddeldose;
    GenericListItems virkestoffMedStyrke;
    GenericListItems virkestoff;
    GenericListItems kodeverk;
    GenericListItems refusjon;
    GenericListItems vilkar;
    GenericListItems varselSlv;
    GenericListItems byttegruppe;
    GenericListItems interaksjon;
    GenericListItems interaksjonIkkeVurdert;
    GenericListItems strDosering;
public:
    PFest(const FestData &, Uint16List &uint16List, std::string &strblock, std::map<std::string,uint32_t> &cache);
};

#endif //LEGEMFEST_PFEST_H
