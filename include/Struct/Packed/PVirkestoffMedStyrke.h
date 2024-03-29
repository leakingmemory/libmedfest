//
// Created by sigsegv on 2/2/23.
//

#ifndef LEGEMFEST_PVIRKESTOFFMEDSTYRKE_H
#define LEGEMFEST_PVIRKESTOFFMEDSTYRKE_H

#include "PValueWithCodeset.h"
#include "PValueUnit.h"
#include "PFestId.h"
#include "FestUuid.h"
#include <vector>

class FestDeserializer;
class VirkestoffMedStyrke;

class PVirkestoffMedStyrke {
    friend FestDeserializer;
private:
    PValueUnit styrke;
    PValueUnit styrkenevner;
    PValueUnit alternativStyrke;
    PValueUnit alternativStyrkenevner;
    PValueWithCodeset styrkeoperator;
    PValueWithCodeset atcKombipreparat;
    double styrkeOvreVerdi;
    PFestId id;
    PFestId refVirkestoff;
public:
    PVirkestoffMedStyrke(const VirkestoffMedStyrke &, std::vector<FestUuid> &uuidblock, std::string &strblock,
                         std::map<std::string,uint32_t> &cache);
    bool operator == (const PVirkestoffMedStyrke &) const;
    PValueUnit GetStyrke() const;
    PValueUnit GetStyrkenevner() const;
    PValueUnit GetAlternativStyrke() const;
    PValueUnit GetAlternativStyrkenevner() const;
    PValueWithCodeset GetStyrkeoperator() const;
    PValueWithCodeset GetAtcKombipreparat() const;
    double GetStyrkeOvreVerdi() const;
    PFestId GetId() const;
    PFestId GetRefVirkestoff() const;
};


#endif //LEGEMFEST_PVIRKESTOFFMEDSTYRKE_H
