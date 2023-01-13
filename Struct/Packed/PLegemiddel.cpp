//
// Created by sigsegv on 1/10/23.
//

#include "PLegemiddel.h"
#include "FestUuidList.h"
#include "../Decoded/Legemiddel.h"

PLegemiddel::PLegemiddel(const Legemiddel &legemiddel, std::string &strblock, FestUuidList &festUuidList,
                         ValueWithCodesetList &valueWithCodesetList) :
        PLegemiddelCore(legemiddel, strblock, festUuidList),
        administreringLegemiddel(legemiddel.GetAdministreringLegemiddel(), strblock, valueWithCodesetList),
        sortertVirkestoffMedStyrke(festUuidList.StoreList(legemiddel.GetSortertVirkestoffMedStyrke())) {
}