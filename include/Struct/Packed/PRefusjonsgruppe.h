//
// Created by sigsegv on 2/5/23.
//

#ifndef LEGEMFEST_PREFUSJONSGRUPPE_H
#define LEGEMFEST_PREFUSJONSGRUPPE_H

#include "PValueWithCodeset.h"
#include "PFestId.h"
#include "GenericListStorage.h"
#include <map>

class FestDeserializer;
class Refusjonsgruppe;
class RefusjonskodeList_0_0_0;
class RefusjonskodeList_0_1_0;
class RefusjonskodeList_1_2_0;
class RefRefusjonsvilkarList_0_0_0;
class RefRefusjonsvilkarList_1_2_0;
class FestUuid;
class StringList;

class PRefusjonsgruppe {
    friend FestDeserializer;
private:
    PValueWithCodeset gruppeNr;
    PString id;
    PString refusjonsberettigetBruk;
    GenericListItems32 refusjonskode;
    GenericListItems32 refVilkar;
    PValueWithCodeset atc;
    bool kreverRefusjonskode : 1;
public:
    PRefusjonsgruppe(const Refusjonsgruppe &, RefusjonskodeList_0_0_0 &, RefusjonskodeList_0_1_0 &, RefusjonskodeList_1_2_0 &, RefRefusjonsvilkarList_0_0_0 &, RefRefusjonsvilkarList_1_2_0 &, StringList &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    PRefusjonsgruppe(const Refusjonsgruppe &, RefusjonskodeList_0_1_0 &, RefusjonskodeList_1_2_0 &, RefRefusjonsvilkarList_0_0_0 &, RefRefusjonsvilkarList_1_2_0 &, StringList &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PRefusjonsgruppe &) const;
};


#endif //LEGEMFEST_PREFUSJONSGRUPPE_H
