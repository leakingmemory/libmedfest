//
// Created by sigsegv on 1/18/23.
//

#ifndef LEGEMFEST_PLEGEMIDDELPAKNING_H
#define LEGEMFEST_PLEGEMIDDELPAKNING_H

#include "PLegemiddelCore.h"
#include "PFestId.h"
#include "PPreparatomtaleavsnitt.h"
#include "PMarkedsforingsinfo.h"
#include "PRefusjon.h"
#include "PPakningByttegruppe.h"

class FestDeserializer;
class Legemiddelpakning;
class PakningskomponentList;
class PakningsinfoList;
class PrisVareList;
class FestUuidList;

class PLegemiddelpakning : public PLegemiddelCore {
    friend FestDeserializer;
private:
    PValueWithDistinguishedName preparattype;
    PFestId id;
    PString varenr;
    PString ean;
    PValueWithDistinguishedName oppbevaring;
    GenericListItems pakningsinfo;
    GenericListItems prisVare;
    PMarkedsforingsinfo markedsforingsinfo;
    PRefusjon refusjon;
    PPakningByttegruppe pakningByttegruppe;
    PPreparatomtaleavsnitt preparatomtaleavsnitt;
    bool ikkeKonservering : 1;
public:
    PLegemiddelpakning(const Legemiddelpakning &, PakningskomponentList &pakningskomponentList,
                       PakningsinfoList &pakningsinfoList, PrisVareList &prisVareList, FestUuidList &festUuidList,
                       std::vector<FestUuid> &uuidblock, std::string &strblock);
};


#endif //LEGEMFEST_PLEGEMIDDELPAKNING_H
