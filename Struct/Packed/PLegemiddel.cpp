//
// Created by sigsegv on 1/10/23.
//

#include <Struct/Packed/PLegemiddel.h>
#include <Struct/Packed/FestUuidList.h>
#include <Struct/Decoded/Legemiddel.h>

PLegemiddel_0_0_0::PLegemiddel_0_0_0(const Legemiddel &legemiddel, std::string &strblock, std::map<std::string,uint32_t> &cache,
                         FestUuidList_0_0_0 &festUuidList, ValueWithCodesetList &valueWithCodesetList) :
        PLegemiddelCore_0_0_0(legemiddel, strblock, cache, festUuidList),
        administreringLegemiddel(legemiddel.GetAdministreringLegemiddel(), strblock, cache, valueWithCodesetList),
        sortertVirkestoffMedStyrke(festUuidList.StoreList(legemiddel.GetSortertVirkestoffMedStyrke())) {
}

bool PLegemiddel_0_0_0::operator==(const PLegemiddel_0_0_0 &other) const {
    return static_cast<const PLegemiddelCore_0_0_0>(*this) == static_cast<const PLegemiddelCore_0_0_0>(other) &&
           administreringLegemiddel == other.administreringLegemiddel &&
           sortertVirkestoffMedStyrke == other.sortertVirkestoffMedStyrke;
}

PLegemiddel_0_4_0::PLegemiddel_0_4_0(const Legemiddel &legemiddel, std::string &strblock, std::map<std::string,uint32_t> &cache,
                         FestUuidList_0_4_0 &festUuidList, ValueWithCodesetList &valueWithCodesetList) :
        PLegemiddelCore_0_4_0(legemiddel, strblock, cache, festUuidList),
        administreringLegemiddel(legemiddel.GetAdministreringLegemiddel(), strblock, cache, valueWithCodesetList),
        sortertVirkestoffMedStyrke(festUuidList.StoreList(legemiddel.GetSortertVirkestoffMedStyrke())) {
}

PLegemiddel_0_4_0::PLegemiddel_0_4_0(const PLegemiddel_0_0_0 &p) :
        PLegemiddelCore_0_4_0(p),
        administreringLegemiddel(p.administreringLegemiddel),
        sortertVirkestoffMedStyrke(p.sortertVirkestoffMedStyrke.CastToWider<GenericListItems64>()) {}

bool PLegemiddel_0_4_0::operator==(const PLegemiddel_0_4_0 &other) const {
    return static_cast<const PLegemiddelCore_0_4_0>(*this) == static_cast<const PLegemiddelCore_0_4_0>(other) &&
           administreringLegemiddel == other.administreringLegemiddel &&
           sortertVirkestoffMedStyrke == other.sortertVirkestoffMedStyrke;
}

PLegemiddel::PLegemiddel(const PLegemiddel_0_0_0 &l) : PLegemiddelCore(l), std::variant<PLegemiddel_0_0_0,PLegemiddel_0_4_0>(l) {}
PLegemiddel::PLegemiddel(const PLegemiddel_0_4_0 &l) : PLegemiddelCore(l), std::variant<PLegemiddel_0_0_0,PLegemiddel_0_4_0>(l) {}
