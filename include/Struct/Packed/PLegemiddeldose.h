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
class PLegemiddeldose_0_4_0;

class PLegemiddeldose_0_0_0 : public PLegemiddelCore_0_0_0 {
    friend FestDeserializer;
    friend PLegemiddeldose_0_4_0;
private:
    PValueWithDistinguishedName preparattype;
    PValueUnit mengde;
    PFestId id;
    PString lmrLopenr;
    GenericListItems32 refLegemiddelMerkevare;
    GenericListItems32 refPakning;
    PValueWithCodeset pakningstype;
    GenericListItems32 pakningskomponent;
public:
    PLegemiddeldose_0_0_0(const Legemiddeldose &, PakningskomponentInfoList &, FestUuidList_0_0_0 &, std::vector<FestUuid> &,
                    std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PLegemiddeldose_0_0_0 &) const;
};

class PLegemiddeldose_0_4_0 : public PLegemiddelCore_0_4_0 {
    friend FestDeserializer;
private:
    PValueWithDistinguishedName preparattype;
    PValueUnit mengde;
    PFestId id;
    PString lmrLopenr;
    GenericListItems64 refLegemiddelMerkevare;
    GenericListItems64 refPakning;
    PValueWithCodeset pakningstype;
    GenericListItems32 pakningskomponent;
public:
    PLegemiddeldose_0_4_0(const Legemiddeldose &, PakningskomponentInfoList &, FestUuidList_0_4_0 &, std::vector<FestUuid> &,
                    std::string &strblock, std::map<std::string,uint32_t> &cache);
    PLegemiddeldose_0_4_0(const PLegemiddeldose_0_0_0 &);
    bool operator == (const PLegemiddeldose_0_4_0 &) const;
};

class PLegemiddeldose : public PLegemiddelCore, public std::variant<PLegemiddeldose_0_0_0,PLegemiddeldose_0_4_0> {
public:
    PLegemiddeldose(const PLegemiddeldose_0_0_0 &);
    PLegemiddeldose(const PLegemiddeldose_0_4_0 &);
};

#endif //LEGEMFEST_PLEGEMIDDELDOSE_H
