//
// Created by sigsegv on 1/11/23.
//

#ifndef LEGEMFEST_PLEGEMIDDELCORE_H
#define LEGEMFEST_PLEGEMIDDELCORE_H

#include "PValueWithCodeset.h"
#include "GenericListStorage.h"

class LegemiddelCore;
class FestUuidList;

class PLegemiddelCore {
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
    PLegemiddelCore(const LegemiddelCore &legemiddelCore, std::string &strblock, FestUuidList &festUuidList);
};


#endif //LEGEMFEST_PLEGEMIDDELCORE_H
