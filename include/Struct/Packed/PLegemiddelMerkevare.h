//
// Created by sigsegv on 1/10/23.
//

#ifndef LEGEMFEST_PLEGEMIDDELMERKEVARE_H
#define LEGEMFEST_PLEGEMIDDELMERKEVARE_H

#include "PValueWithDistinguishedName.h"
#include "PValueWithCodeset.h"
#include "PFestId.h"
#include "PPreparatomtaleavsnitt.h"
#include "PLegemiddel.h"

class FestDeserializer;
class LegemiddelMerkevare;
class ReseptgyldighetList;
class ValueWithCodesetList;
class FestUuidList;

class PLegemiddelMerkevare : public PLegemiddel {
    friend FestDeserializer;
private:
    PValueWithCodeset vaksinestandard;
    PValueWithDistinguishedName preparattype;
    PValueWithDistinguishedName smak;
    PString varenavn;
    PString legemiddelformLang;
    PString produsent;
    PString referanseprodukt;
    PFestId id;
    PPreparatomtaleavsnitt preparatomtaleavsnitt;
    GenericListItems sortertVirkestoffUtenStyrke;
    GenericListItems reseptgyldighet;
    uint8_t varseltrekant : 2;
public:
    PLegemiddelMerkevare(const LegemiddelMerkevare &, std::string &strblock, std::map<std::string,uint32_t> &cache,
                         std::vector<FestUuid> &festidblock, FestUuidList &festUuidList,
                         ValueWithCodesetList &valueWithCodesetList, ReseptgyldighetList &reseptgyldighetList);
    bool operator == (const PLegemiddelMerkevare &) const;
};


#endif //LEGEMFEST_PLEGEMIDDELMERKEVARE_H
