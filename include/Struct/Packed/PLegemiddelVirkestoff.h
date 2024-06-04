//
// Created by sigsegv on 1/24/23.
//

#ifndef LEGEMFEST_PLEGEMIDDELVIRKESTOFF_H
#define LEGEMFEST_PLEGEMIDDELVIRKESTOFF_H

#include "PLegemiddel.h"
#include "PFestId.h"

class FestDeserializer;
class LegemiddelVirkestoff;
class RefusjonList;
class StringList;

class PLegemiddelVirkestoff : public PLegemiddel {
    friend FestDeserializer;
private:
    PValueWithCodeset forskrivningsenhetResept;
    PFestId id;
    GenericListItems32 refusjon;
    GenericListItems32 refLegemiddelMerkevare;
    GenericListItems32 refPakning;
public:
    PLegemiddelVirkestoff(const LegemiddelVirkestoff &legemiddelVirkestoff, std::string &strblock,
                          std::map<std::string,uint32_t> &cache, std::vector<FestUuid> &uuidlist, StringList &,
                          FestUuidList &, ValueWithCodesetList &valueWithCodesetList, RefusjonList &refusjonList);
    bool operator == (const PLegemiddelVirkestoff &) const;
    PValueWithCodeset GetForskrivningsenhetResept() const;
    PFestId GetId() const;
    GenericListItems32 GetRefusjon() const;
    GenericListItems32 GetRefLegemiddelMerkevare() const;
    GenericListItems32 GetRefPakning() const;
};


#endif //LEGEMFEST_PLEGEMIDDELVIRKESTOFF_H
