//
// Created by sigsegv on 1/18/23.
//

#ifndef LEGEMFEST_PPAKNINGSINFO_H
#define LEGEMFEST_PPAKNINGSINFO_H

#include "PFestId.h"
#include "PString.h"
#include "PValueWithCodeset.h"
#include "PValueUnit.h"
#include "GenericListStorage.h"
#include "PakningskomponentList.h"

class FestDeserializer;
class Pakningsinfo;

class PPakningsinfo {
    friend FestDeserializer;
private:
    PFestId merkevareId;
    PString pakningsstr;
    PValueWithCodeset enhetPakning;
    PValueWithCodeset pakningstype;
    PValueUnit ddd;
    PString mengde;
    GenericListItems pakningskomponent;
    double statistikkfaktor;
    uint16_t antall;
    uint16_t multippel;
public:
    PPakningsinfo(const Pakningsinfo &, std::vector<FestUuid> &uuidblock, PakningskomponentList &pakningskomponentList,
                  std::string &strblock);
    bool operator == (const PPakningsinfo &) const;
};


#endif //LEGEMFEST_PPAKNINGSINFO_H
