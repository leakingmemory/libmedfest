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
class RefusjonskodeList;
class RefRefusjonsvilkarList;
class FestUuid;
class StringList;

class PRefusjonsgruppe {
    friend FestDeserializer;
private:
    PValueWithCodeset gruppeNr;
    PString id;
    PString refusjonsberettigetBruk;
    GenericListItems refusjonskode;
    GenericListItems refVilkar;
    PValueWithCodeset atc;
    bool kreverRefusjonskode : 1;
public:
    PRefusjonsgruppe(const Refusjonsgruppe &, RefusjonskodeList &, RefRefusjonsvilkarList &, StringList &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PRefusjonsgruppe &) const;
};


#endif //LEGEMFEST_PREFUSJONSGRUPPE_H
