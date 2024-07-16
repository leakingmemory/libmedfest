//
// Created by sigsegv on 1/24/23.
//

#include "Struct/Packed/PLegemiddelVirkestoff.h"
#include "Struct/Decoded/LegemiddelVirkestoff.h"
#include "Struct/Packed/RefusjonList.h"
#include "Struct/Packed/FestUuidList.h"

PLegemiddelVirkestoff_0_0_0::PLegemiddelVirkestoff_0_0_0(const LegemiddelVirkestoff &legemiddelVirkestoff, std::string &strblock,
                                             std::map<std::string,uint32_t> &cache, std::vector<FestUuid> &uuidlist,
                                             StringList &stringList, FestUuidList_0_0_0 &festUuidList,
                                             ValueWithCodesetList &valueWithCodesetList, RefusjonList &refusjonList) :
        PLegemiddel_0_0_0(legemiddelVirkestoff, strblock, cache, festUuidList, valueWithCodesetList),
        forskrivningsenhetResept(legemiddelVirkestoff.GetForskrivningsenhetResept(), strblock, cache),
        id(legemiddelVirkestoff.GetId(), uuidlist),
        refusjon(),
        refLegemiddelMerkevare(festUuidList.StoreList(legemiddelVirkestoff.GetRefLegemiddelMerkevare())),
        refPakning(festUuidList.StoreList(legemiddelVirkestoff.GetRefPakning())) {
    std::vector<PRefusjon> refusjon{};
    for (const auto &r : legemiddelVirkestoff.GetRefusjon()) {
        refusjon.emplace_back(r, stringList, strblock, cache);
    }
    this->refusjon = refusjonList.StoreList(refusjon);
}

bool PLegemiddelVirkestoff_0_0_0::operator==(const PLegemiddelVirkestoff_0_0_0 &other) const {
    return id == other.id &&
           static_cast<const PLegemiddel_0_0_0>(*this) == static_cast<const PLegemiddel_0_0_0>(other) &&
           forskrivningsenhetResept == other.forskrivningsenhetResept &&
           refusjon == other.refusjon &&
           refLegemiddelMerkevare == other.refLegemiddelMerkevare &&
           refPakning == other.refPakning;
}

PValueWithCodeset PLegemiddelVirkestoff_0_0_0::GetForskrivningsenhetResept() const {
    return forskrivningsenhetResept;
}

PFestId PLegemiddelVirkestoff_0_0_0::GetId() const {
    return id;
}

GenericListItems32 PLegemiddelVirkestoff_0_0_0::GetRefusjon() const {
    return refusjon;
}

GenericListItems32 PLegemiddelVirkestoff_0_0_0::GetRefLegemiddelMerkevare() const {
    return refLegemiddelMerkevare;
}

GenericListItems32 PLegemiddelVirkestoff_0_0_0::GetRefPakning() const {
    return refPakning;
}

PLegemiddelVirkestoff_0_4_0::PLegemiddelVirkestoff_0_4_0(const LegemiddelVirkestoff &legemiddelVirkestoff, std::string &strblock,
                                             std::map<std::string,uint32_t> &cache, std::vector<FestUuid> &uuidlist,
                                             StringList &stringList, FestUuidList_0_4_0 &festUuidList,
                                             ValueWithCodesetList &valueWithCodesetList, RefusjonList &refusjonList) :
        PLegemiddel_0_4_0(legemiddelVirkestoff, strblock, cache, festUuidList, valueWithCodesetList),
        forskrivningsenhetResept(legemiddelVirkestoff.GetForskrivningsenhetResept(), strblock, cache),
        id(legemiddelVirkestoff.GetId(), uuidlist),
        refusjon(),
        refLegemiddelMerkevare(festUuidList.StoreList(legemiddelVirkestoff.GetRefLegemiddelMerkevare())),
        refPakning(festUuidList.StoreList(legemiddelVirkestoff.GetRefPakning())) {
    std::vector<PRefusjon> refusjon{};
    for (const auto &r : legemiddelVirkestoff.GetRefusjon()) {
        refusjon.emplace_back(r, stringList, strblock, cache);
    }
    this->refusjon = refusjonList.StoreList(refusjon);
}

PLegemiddelVirkestoff_0_4_0::PLegemiddelVirkestoff_0_4_0(const PLegemiddelVirkestoff_0_0_0 &p) :
        PLegemiddel_0_4_0(p),
        forskrivningsenhetResept(p.forskrivningsenhetResept),
        id(p.id),
        refusjon(p.refusjon),
        refLegemiddelMerkevare(p.refLegemiddelMerkevare.CastToWider<GenericListItems64>()),
        refPakning(p.refPakning.CastToWider<GenericListItems64>()) {}

bool PLegemiddelVirkestoff_0_4_0::operator==(const PLegemiddelVirkestoff_0_4_0 &other) const {
    return id == other.id &&
           static_cast<const PLegemiddel_0_4_0>(*this) == static_cast<const PLegemiddel_0_4_0>(other) &&
           forskrivningsenhetResept == other.forskrivningsenhetResept &&
           refusjon == other.refusjon &&
           refLegemiddelMerkevare == other.refLegemiddelMerkevare &&
           refPakning == other.refPakning;
}

PValueWithCodeset PLegemiddelVirkestoff_0_4_0::GetForskrivningsenhetResept() const {
    return forskrivningsenhetResept;
}

PFestId PLegemiddelVirkestoff_0_4_0::GetId() const {
    return id;
}

GenericListItems32 PLegemiddelVirkestoff_0_4_0::GetRefusjon() const {
    return refusjon;
}

GenericListItems64 PLegemiddelVirkestoff_0_4_0::GetRefLegemiddelMerkevare() const {
    return refLegemiddelMerkevare;
}

GenericListItems64 PLegemiddelVirkestoff_0_4_0::GetRefPakning() const {
    return refPakning;
}

PLegemiddelVirkestoff::PLegemiddelVirkestoff(const PLegemiddelVirkestoff_0_4_0 &p) : PLegemiddel(p), std::variant<PLegemiddelVirkestoff_0_4_0,PLegemiddelVirkestoff_0_0_0>(p) {}
PLegemiddelVirkestoff::PLegemiddelVirkestoff(const PLegemiddelVirkestoff_0_0_0 &p) : PLegemiddel(p), std::variant<PLegemiddelVirkestoff_0_4_0,PLegemiddelVirkestoff_0_0_0>(p) {}

PValueWithCodeset PLegemiddelVirkestoff::GetForskrivningsenhetResept() const {
    const std::variant<PLegemiddelVirkestoff_0_4_0,PLegemiddelVirkestoff_0_0_0> &p = *this;
    if (std::holds_alternative<PLegemiddelVirkestoff_0_4_0>(p)) {
        return std::get<PLegemiddelVirkestoff_0_4_0>(p).GetForskrivningsenhetResept();
    } else {
        return std::get<PLegemiddelVirkestoff_0_0_0>(p).GetForskrivningsenhetResept();
    }
}

PFestId PLegemiddelVirkestoff::GetId() const {
    const std::variant<PLegemiddelVirkestoff_0_4_0,PLegemiddelVirkestoff_0_0_0> &p = *this;
    if (std::holds_alternative<PLegemiddelVirkestoff_0_4_0>(p)) {
        return std::get<PLegemiddelVirkestoff_0_4_0>(p).GetId();
    } else {
        return std::get<PLegemiddelVirkestoff_0_0_0>(p).GetId();
    }
}

GenericListItems32 PLegemiddelVirkestoff::GetRefusjon() const {
    const std::variant<PLegemiddelVirkestoff_0_4_0,PLegemiddelVirkestoff_0_0_0> &p = *this;
    if (std::holds_alternative<PLegemiddelVirkestoff_0_4_0>(p)) {
        return std::get<PLegemiddelVirkestoff_0_4_0>(p).GetRefusjon();
    } else {
        return std::get<PLegemiddelVirkestoff_0_0_0>(p).GetRefusjon();
    }
}

std::variant<GenericListItems32, GenericListItems64> PLegemiddelVirkestoff::GetRefLegemiddelMerkevare() const {
    const std::variant<PLegemiddelVirkestoff_0_4_0,PLegemiddelVirkestoff_0_0_0> &p = *this;
    if (std::holds_alternative<PLegemiddelVirkestoff_0_4_0>(p)) {
        return std::get<PLegemiddelVirkestoff_0_4_0>(p).GetRefLegemiddelMerkevare();
    } else {
        return std::get<PLegemiddelVirkestoff_0_0_0>(p).GetRefLegemiddelMerkevare();
    }
}

std::variant<GenericListItems32, GenericListItems64> PLegemiddelVirkestoff::GetRefPakning() const {
    const std::variant<PLegemiddelVirkestoff_0_4_0,PLegemiddelVirkestoff_0_0_0> &p = *this;
    if (std::holds_alternative<PLegemiddelVirkestoff_0_4_0>(p)) {
        return std::get<PLegemiddelVirkestoff_0_4_0>(p).GetRefPakning();
    } else {
        return std::get<PLegemiddelVirkestoff_0_0_0>(p).GetRefPakning();
    }
}