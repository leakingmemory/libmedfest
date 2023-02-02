//
// Created by sigsegv on 1/31/23.
//

#ifndef LEGEMFEST_PLEGEMIDDELDOSE_H
#define LEGEMFEST_PLEGEMIDDELDOSE_H

#include "PLegemiddelCore.h"
#include "PValueUnit.h"
#include "PFestId.h"
#include "GenericListStorage.h"

class FestDeserializer;
class Legemiddeldose;
class PakningskomponentInfoList;

class PLegemiddeldose : public PLegemiddelCore {
    friend FestDeserializer;
private:
    PValueWithDistinguishedName preparattype;
    PValueUnit mengde;
    PFestId id;
    PString lmrLopenr;
    GenericListItems refLegemiddelMerkevare;
    GenericListItems refPakning;
    PValueWithCodeset pakningstype;
    GenericListItems pakningskomponent;
public:
    PLegemiddeldose(const Legemiddeldose &, PakningskomponentInfoList &, FestUuidList &, std::vector<FestUuid> &, std::string &strblock);
};


#endif //LEGEMFEST_PLEGEMIDDELDOSE_H
