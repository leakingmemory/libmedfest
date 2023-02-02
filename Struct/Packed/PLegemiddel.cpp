//
// Created by sigsegv on 1/10/23.
//

#include "PLegemiddel.h"
#include "FestUuidList.h"
#include "../Decoded/Legemiddel.h"

PLegemiddel::PLegemiddel(const Legemiddel &legemiddel, std::string &strblock, std::map<std::string,uint32_t> &cache,
                         FestUuidList &festUuidList, ValueWithCodesetList &valueWithCodesetList) :
        PLegemiddelCore(legemiddel, strblock, cache, festUuidList),
        administreringLegemiddel(legemiddel.GetAdministreringLegemiddel(), strblock, cache, valueWithCodesetList),
        sortertVirkestoffMedStyrke(festUuidList.StoreList(legemiddel.GetSortertVirkestoffMedStyrke())) {
}