//
// Created by sigsegv on 1/10/23.
//

#ifndef LEGEMFEST_PLEGEMIDDEL_H
#define LEGEMFEST_PLEGEMIDDEL_H

#include "PAdministreringLegemiddel.h"
#include "PLegemiddelCore.h"

class FestDeserializer;
class Legemiddel;
class FestUuidList;

class PLegemiddel : public PLegemiddelCore {
    friend FestDeserializer;
private:
    PAdministreringLegemiddel administreringLegemiddel;
    GenericListItems32 sortertVirkestoffMedStyrke;
public:
    PLegemiddel(const Legemiddel &legemiddel, std::string &strblock, std::map<std::string,uint32_t> &cache,
                FestUuidList &festUuidList, ValueWithCodesetList &valueWithCodesetList);
    bool operator == (const PLegemiddel &) const;
};


#endif //LEGEMFEST_PLEGEMIDDEL_H
