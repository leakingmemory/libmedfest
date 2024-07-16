//
// Created by sigsegv on 1/11/23.
//

#include <Struct/Packed/PLegemiddelCore.h>
#include <Struct/Packed/FestUuidList.h>
#include <Struct/Decoded/LegemiddelCore.h>

PLegemiddelCore_0_0_0::PLegemiddelCore_0_0_0(const LegemiddelCore &legemiddelCore, std::string &strblock,
                                 std::map<std::string,uint32_t> &cache, FestUuidList_0_0_0 &festUuidList) :
        atc(legemiddelCore.GetAtc(), strblock, cache),
        navnFormStyrke(legemiddelCore.GetNavnFormStyrke(), strblock, cache),
        reseptgruppe(legemiddelCore.GetReseptgruppe(), strblock, cache),
        legemiddelformKort(legemiddelCore.GetLegemiddelformKort(), strblock, cache),
        refVilkar(festUuidList.StoreList(legemiddelCore.GetRefVilkar())),
        typeSoknadSlv(legemiddelCore.GetTypeSoknadSlv(), strblock, cache),
        svartTrekant(legemiddelCore.GetSvartTrekant(), strblock, cache),
        opioidsoknad(ToRaw(legemiddelCore.GetOpioidsoknad())) {
}

bool PLegemiddelCore_0_0_0::operator==(const PLegemiddelCore_0_0_0 &other) const {
    return atc == other.atc &&
           navnFormStyrke == other.navnFormStyrke &&
           reseptgruppe == other.reseptgruppe &&
           legemiddelformKort == other.legemiddelformKort &&
           refVilkar == other.refVilkar &&
           typeSoknadSlv == other.typeSoknadSlv &&
           svartTrekant == other.svartTrekant &&
           opioidsoknad == other.opioidsoknad;
}

PString PLegemiddelCore_0_0_0::GetNavnFormStyrke() const {
    return navnFormStyrke;
}
PValueWithDistinguishedName PLegemiddelCore_0_0_0::GetReseptgruppe() const {
    return reseptgruppe;
}
PValueWithCodeset PLegemiddelCore_0_0_0::GetLegemiddelformKort() const {
    return legemiddelformKort;
}
GenericListItems32 PLegemiddelCore_0_0_0::GetRefVilkar() const {
    return refVilkar;
}
PValueWithDistinguishedName PLegemiddelCore_0_0_0::GetTypeSoknadSlv() const {
    return typeSoknadSlv;
}
PValueWithCodeset PLegemiddelCore_0_0_0::GetSvartTrekant() const {
    return svartTrekant;
}
uint8_t PLegemiddelCore_0_0_0::GetOpioidsoknad() const {
    return opioidsoknad;
}

PLegemiddelCore_0_4_0::PLegemiddelCore_0_4_0(const LegemiddelCore &legemiddelCore, std::string &strblock,
                                 std::map<std::string,uint32_t> &cache, FestUuidList_0_4_0 &festUuidList) :
        atc(legemiddelCore.GetAtc(), strblock, cache),
        navnFormStyrke(legemiddelCore.GetNavnFormStyrke(), strblock, cache),
        reseptgruppe(legemiddelCore.GetReseptgruppe(), strblock, cache),
        legemiddelformKort(legemiddelCore.GetLegemiddelformKort(), strblock, cache),
        refVilkar(festUuidList.StoreList(legemiddelCore.GetRefVilkar())),
        typeSoknadSlv(legemiddelCore.GetTypeSoknadSlv(), strblock, cache),
        svartTrekant(legemiddelCore.GetSvartTrekant(), strblock, cache),
        opioidsoknad(ToRaw(legemiddelCore.GetOpioidsoknad())) {
}

PLegemiddelCore_0_4_0::PLegemiddelCore_0_4_0(const PLegemiddelCore_0_0_0 &legemiddelCore) :
        atc(legemiddelCore.atc),
        navnFormStyrke(legemiddelCore.navnFormStyrke),
        reseptgruppe(legemiddelCore.reseptgruppe),
        legemiddelformKort(legemiddelCore.legemiddelformKort),
        refVilkar(legemiddelCore.refVilkar.CastToWider<GenericListItems64>()),
        typeSoknadSlv(legemiddelCore.typeSoknadSlv),
        svartTrekant(legemiddelCore.svartTrekant),
        opioidsoknad(legemiddelCore.opioidsoknad){}

bool PLegemiddelCore_0_4_0::operator==(const PLegemiddelCore_0_4_0 &other) const {
    return atc == other.atc &&
           navnFormStyrke == other.navnFormStyrke &&
           reseptgruppe == other.reseptgruppe &&
           legemiddelformKort == other.legemiddelformKort &&
           refVilkar == other.refVilkar &&
           typeSoknadSlv == other.typeSoknadSlv &&
           svartTrekant == other.svartTrekant &&
           opioidsoknad == other.opioidsoknad;
}

PString PLegemiddelCore_0_4_0::GetNavnFormStyrke() const {
    return navnFormStyrke;
}
PValueWithDistinguishedName PLegemiddelCore_0_4_0::GetReseptgruppe() const {
    return reseptgruppe;
}
PValueWithCodeset PLegemiddelCore_0_4_0::GetLegemiddelformKort() const {
    return legemiddelformKort;
}
GenericListItems64 PLegemiddelCore_0_4_0::GetRefVilkar() const {
    return refVilkar;
}
PValueWithDistinguishedName PLegemiddelCore_0_4_0::GetTypeSoknadSlv() const {
    return typeSoknadSlv;
}
PValueWithCodeset PLegemiddelCore_0_4_0::GetSvartTrekant() const {
    return svartTrekant;
}
uint8_t PLegemiddelCore_0_4_0::GetOpioidsoknad() const {
    return opioidsoknad;
}

PLegemiddelCore::PLegemiddelCore(const PLegemiddelCore_0_0_0 &l) : std::variant<PLegemiddelCore_0_0_0,PLegemiddelCore_0_4_0>(l) {}
PLegemiddelCore::PLegemiddelCore(const PLegemiddelCore_0_4_0 &l) : std::variant<PLegemiddelCore_0_0_0,PLegemiddelCore_0_4_0>(l) {}

PString PLegemiddelCore::GetNavnFormStyrke() const {
    if (std::holds_alternative<PLegemiddelCore_0_4_0>(*this)) {
        return std::get<PLegemiddelCore_0_4_0>(*this).GetNavnFormStyrke();
    } else {
        return std::get<PLegemiddelCore_0_0_0>(*this).GetNavnFormStyrke();
    }
}

PValueWithDistinguishedName PLegemiddelCore::GetReseptgruppe() const {
    if (std::holds_alternative<PLegemiddelCore_0_4_0>(*this)) {
        return std::get<PLegemiddelCore_0_4_0>(*this).GetReseptgruppe();
    } else {
        return std::get<PLegemiddelCore_0_0_0>(*this).GetReseptgruppe();
    }
}

PValueWithCodeset PLegemiddelCore::GetLegemiddelformKort() const {
    if (std::holds_alternative<PLegemiddelCore_0_4_0>(*this)) {
        return std::get<PLegemiddelCore_0_4_0>(*this).GetLegemiddelformKort();
    } else {
        return std::get<PLegemiddelCore_0_0_0>(*this).GetLegemiddelformKort();
    }
}

std::variant<GenericListItems32, GenericListItems64> PLegemiddelCore::GetRefVilkar() const {
    if (std::holds_alternative<PLegemiddelCore_0_4_0>(*this)) {
        return std::get<PLegemiddelCore_0_4_0>(*this).GetRefVilkar();
    } else {
        return std::get<PLegemiddelCore_0_0_0>(*this).GetRefVilkar();
    }
}

PValueWithDistinguishedName PLegemiddelCore::GetTypeSoknadSlv() const {
    if (std::holds_alternative<PLegemiddelCore_0_4_0>(*this)) {
        return std::get<PLegemiddelCore_0_4_0>(*this).GetTypeSoknadSlv();
    } else {
        return std::get<PLegemiddelCore_0_0_0>(*this).GetTypeSoknadSlv();
    }
}

PValueWithCodeset PLegemiddelCore::GetSvartTrekant() const {
    if (std::holds_alternative<PLegemiddelCore_0_4_0>(*this)) {
        return std::get<PLegemiddelCore_0_4_0>(*this).GetSvartTrekant();
    } else {
        return std::get<PLegemiddelCore_0_0_0>(*this).GetSvartTrekant();
    }
}

uint8_t PLegemiddelCore::GetOpioidsoknad() const {
    if (std::holds_alternative<PLegemiddelCore_0_4_0>(*this)) {
        return std::get<PLegemiddelCore_0_4_0>(*this).GetOpioidsoknad();
    } else {
        return std::get<PLegemiddelCore_0_0_0>(*this).GetOpioidsoknad();
    }
}
