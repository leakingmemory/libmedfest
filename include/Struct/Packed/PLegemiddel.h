//
// Created by sigsegv on 1/10/23.
//

#ifndef LEGEMFEST_PLEGEMIDDEL_H
#define LEGEMFEST_PLEGEMIDDEL_H

#include "PAdministreringLegemiddel.h"
#include "PLegemiddelCore.h"

class FestDeserializer;
class Legemiddel;
class FestUuidList_0_0_0;
class FestUuidList_0_4_0;
class PLegemiddel_0_4_0;

class PLegemiddel_0_0_0 : public PLegemiddelCore_0_0_0 {
    friend FestDeserializer;
    friend PLegemiddel_0_4_0;
private:
    PAdministreringLegemiddel administreringLegemiddel;
    GenericListItems32 sortertVirkestoffMedStyrke;
public:
    PLegemiddel_0_0_0(const Legemiddel &legemiddel, std::string &strblock, std::map<std::string,uint32_t> &cache,
                FestUuidList_0_0_0 &festUuidList, ValueWithCodesetList &valueWithCodesetList);
    bool operator == (const PLegemiddel_0_0_0 &) const;
    PAdministreringLegemiddel GetAdministreringLegemiddel() const;
};

class PLegemiddel_0_4_0 : public PLegemiddelCore_0_4_0 {
    friend FestDeserializer;
private:
    PAdministreringLegemiddel administreringLegemiddel;
    GenericListItems64 sortertVirkestoffMedStyrke;
public:
    PLegemiddel_0_4_0(const Legemiddel &legemiddel, std::string &strblock, std::map<std::string,uint32_t> &cache,
                FestUuidList_0_4_0 &festUuidList, ValueWithCodesetList &valueWithCodesetList);
    PLegemiddel_0_4_0(const PLegemiddel_0_0_0 &);
    bool operator == (const PLegemiddel_0_4_0 &) const;
    PAdministreringLegemiddel GetAdministreringLegemiddel() const;
};

class PLegemiddel : public PLegemiddelCore, public std::variant<PLegemiddel_0_0_0,PLegemiddel_0_4_0> {
public:
    PLegemiddel(const PLegemiddel_0_0_0 &);
    PLegemiddel(const PLegemiddel_0_4_0 &);
    PAdministreringLegemiddel GetAdministreringLegemiddel() const;
};

#endif //LEGEMFEST_PLEGEMIDDEL_H
