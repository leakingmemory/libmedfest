//
// Created by sigsegv on 1/11/23.
//

#ifndef LEGEMFEST_PLEGEMIDDELCORE_H
#define LEGEMFEST_PLEGEMIDDELCORE_H

#include "PValueWithCodeset.h"
#include "GenericListStorage.h"

class FestDeserializer;
class LegemiddelCore;
class FestUuidList;

class PLegemiddelCore {
    friend FestDeserializer;
private:
    PValueWithCodeset atc;
    PString navnFormStyrke;
    PValueWithDistinguishedName reseptgruppe;
    PValueWithCodeset legemiddelformKort;
    GenericListItems refVilkar;
    PValueWithDistinguishedName typeSoknadSlv;
    PValueWithCodeset svartTrekant;
    uint8_t opioidsoknad : 2;
public:
    PLegemiddelCore(const LegemiddelCore &legemiddelCore, std::string &strblock, std::map<std::string,uint32_t> &cache, FestUuidList &festUuidList);
    bool operator == (const PLegemiddelCore &) const;
};


#endif //LEGEMFEST_PLEGEMIDDELCORE_H
