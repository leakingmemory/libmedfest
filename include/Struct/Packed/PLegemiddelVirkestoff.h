//
// Created by sigsegv on 1/24/23.
//

#ifndef LEGEMFEST_PLEGEMIDDELVIRKESTOFF_H
#define LEGEMFEST_PLEGEMIDDELVIRKESTOFF_H

#include "PLegemiddel.h"
#include "PFestId.h"
#include <variant>

class FestDeserializer;
class LegemiddelVirkestoff;
class RefusjonList;
class StringList;
class PLegemiddelVirkestoff_0_4_0;

class PLegemiddelVirkestoff_0_0_0 : public PLegemiddel_0_0_0 {
    friend FestDeserializer;
    friend PLegemiddelVirkestoff_0_4_0;
private:
    PValueWithCodeset forskrivningsenhetResept;
    PFestId id;
    GenericListItems32 refusjon;
    GenericListItems32 refLegemiddelMerkevare;
    GenericListItems32 refPakning;
public:
    PLegemiddelVirkestoff_0_0_0(const LegemiddelVirkestoff &legemiddelVirkestoff, std::string &strblock,
                          std::map<std::string,uint32_t> &cache, std::vector<FestUuid> &uuidlist, StringList &,
                          FestUuidList_0_0_0 &, ValueWithCodesetList &valueWithCodesetList, RefusjonList &refusjonList);
    bool operator == (const PLegemiddelVirkestoff_0_0_0 &) const;
    PValueWithCodeset GetForskrivningsenhetResept() const;
    PFestId GetId() const;
    GenericListItems32 GetRefusjon() const;
    GenericListItems32 GetRefLegemiddelMerkevare() const;
    GenericListItems32 GetRefPakning() const;
};

class PLegemiddelVirkestoff_0_4_0 : public PLegemiddel_0_4_0 {
    friend FestDeserializer;
private:
    PValueWithCodeset forskrivningsenhetResept;
    PFestId id;
    GenericListItems32 refusjon;
    GenericListItems64 refLegemiddelMerkevare;
    GenericListItems64 refPakning;
public:
    PLegemiddelVirkestoff_0_4_0(const LegemiddelVirkestoff &legemiddelVirkestoff, std::string &strblock,
                          std::map<std::string,uint32_t> &cache, std::vector<FestUuid> &uuidlist, StringList &,
                          FestUuidList_0_4_0 &, ValueWithCodesetList &valueWithCodesetList, RefusjonList &refusjonList);
    PLegemiddelVirkestoff_0_4_0(const PLegemiddelVirkestoff_0_0_0 &);
    bool operator == (const PLegemiddelVirkestoff_0_4_0 &) const;
    PValueWithCodeset GetForskrivningsenhetResept() const;
    PFestId GetId() const;
    GenericListItems32 GetRefusjon() const;
    GenericListItems64 GetRefLegemiddelMerkevare() const;
    GenericListItems64 GetRefPakning() const;
};

class PLegemiddelVirkestoff : public PLegemiddel, public std::variant<PLegemiddelVirkestoff_0_4_0,PLegemiddelVirkestoff_0_0_0> {
public:
    PLegemiddelVirkestoff(const PLegemiddelVirkestoff_0_4_0 &);
    PLegemiddelVirkestoff(const PLegemiddelVirkestoff_0_0_0 &);
    PValueWithCodeset GetForskrivningsenhetResept() const;
    PFestId GetId() const;
    GenericListItems32 GetRefusjon() const;
    std::variant<GenericListItems32,GenericListItems64> GetRefLegemiddelMerkevare() const;
    std::variant<GenericListItems32,GenericListItems64> GetRefPakning() const;
};

#endif //LEGEMFEST_PLEGEMIDDELVIRKESTOFF_H
