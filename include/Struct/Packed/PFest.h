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
    GenericListItems32 legemiddelMerkevare;
    GenericListItems32 legemiddelpakning;
    GenericListItems32 legemiddelVirkestoff;
    GenericListItems32 medForbrMatr;
    GenericListItems32 naringsmiddel;
    GenericListItems32 brystprotese;
    GenericListItems32 legemiddeldose;
    GenericListItems32 virkestoffMedStyrke;
    GenericListItems32 virkestoff;
    GenericListItems32 kodeverk;
    GenericListItems32 refusjon;
    GenericListItems32 vilkar;
    GenericListItems32 varselSlv;
    GenericListItems32 byttegruppe;
    GenericListItems32 interaksjon;
    GenericListItems32 interaksjonIkkeVurdert;
    GenericListItems32 strDosering;
public:
    PFest(const FestData &, Uint16List &uint16List, std::string &strblock, std::map<std::string,uint32_t> &cache);
};

#endif //LEGEMFEST_PFEST_H
