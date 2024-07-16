//
// Created by sigsegv on 1/10/23.
//

#include <Struct/Packed/PLegemiddelMerkevare.h>
#include <Struct/Packed/FestUuidList.h>
#include <Struct/Packed/ValueWithCodesetList.h>
#include <Struct/Packed/ReseptgyldighetList.h>
#include <Struct/Decoded/LegemiddelMerkevare.h>

PLegemiddelMerkevare_0_0_0::PLegemiddelMerkevare_0_0_0(const LegemiddelMerkevare &legemiddelMerkevare, std::string &strblock,
                                           std::map<std::string,uint32_t> &cache, std::vector<FestUuid> &festidblock,
                                           FestUuidList_0_0_0 &festUuidList, ValueWithCodesetList &valueWithCodesetList,
                                           ReseptgyldighetList &reseptgyldighetList) :
        PLegemiddel_0_0_0(legemiddelMerkevare, strblock, cache, festUuidList, valueWithCodesetList),
        vaksinestandard(legemiddelMerkevare.GetVaksinestandard(), strblock, cache),
        preparattype(legemiddelMerkevare.GetPreparattype(), strblock, cache),
        smak(legemiddelMerkevare.GetSmak(), strblock, cache),
        varenavn(legemiddelMerkevare.GetVarenavn(), strblock, cache),
        legemiddelformLang(legemiddelMerkevare.GetLegemiddelformLang(), strblock, cache),
        produsent(legemiddelMerkevare.GetProdusent(), strblock, cache),
        referanseprodukt(legemiddelMerkevare.GetReferanseprodukt(), strblock, cache),
        id(legemiddelMerkevare.GetId(), festidblock),
        preparatomtaleavsnitt(legemiddelMerkevare.GetPreparatomtaleavsnitt(), strblock, cache),
        sortertVirkestoffUtenStyrke(festUuidList.StoreList(legemiddelMerkevare.GetSortertVirkestoffUtenStyrke())),
        reseptgyldighet(),
        varseltrekant(ToRaw(legemiddelMerkevare.GetVarseltrekant()))
{
    {
        std::vector<PReseptgyldighet> list{};
        auto reseptgyldighet = legemiddelMerkevare.GetReseptgyldighet();
        for (const auto &r : reseptgyldighet) {
            list.emplace_back(r, strblock, cache);
        }
        this->reseptgyldighet = reseptgyldighetList.StoreList(list);
    }
}

bool PLegemiddelMerkevare_0_0_0::operator==(const PLegemiddelMerkevare_0_0_0 &other) const {
    return id == other.id &&
           static_cast<const PLegemiddel_0_0_0 &>(*this) == static_cast<const PLegemiddel_0_0_0 &>(other) &&
           vaksinestandard == other.vaksinestandard &&
           preparattype == other.preparattype &&
           smak == other.smak &&
           varenavn == other.varenavn &&
           legemiddelformLang == other.legemiddelformLang &&
           produsent == other.produsent &&
           referanseprodukt == other.referanseprodukt &&
           preparatomtaleavsnitt == other.preparatomtaleavsnitt &&
           sortertVirkestoffUtenStyrke == other.sortertVirkestoffUtenStyrke &&
           reseptgyldighet == other.reseptgyldighet &&
           varseltrekant == other.varseltrekant;
}

PValueWithCodeset PLegemiddelMerkevare_0_0_0::GetVaksinestandard() const {
    return vaksinestandard;
}
PValueWithDistinguishedName PLegemiddelMerkevare_0_0_0::GetPreparattype() const {
    return preparattype;
}
PValueWithDistinguishedName PLegemiddelMerkevare_0_0_0::GetSmak() const {
    return smak;
}
PString PLegemiddelMerkevare_0_0_0::GetVarenavn() const {
    return varenavn;
}
PString PLegemiddelMerkevare_0_0_0::GetLegemiddelformLang() const {
    return legemiddelformLang;
}
PString PLegemiddelMerkevare_0_0_0::GetProdusent() const {
    return produsent;
}
PString PLegemiddelMerkevare_0_0_0::GetReferanseprodukt() const {
    return referanseprodukt;
}
PFestId PLegemiddelMerkevare_0_0_0::GetId() const {
    return id;
}
PPreparatomtaleavsnitt PLegemiddelMerkevare_0_0_0::GetPreparatomtaleavsnitt() const {
    return preparatomtaleavsnitt;
}
GenericListItems32 PLegemiddelMerkevare_0_0_0::GetSortertVirkestoffUtenStyrke() const {
    return sortertVirkestoffUtenStyrke;
}
GenericListItems32 PLegemiddelMerkevare_0_0_0::GetReseptgyldighet() const {
    return reseptgyldighet;
}
uint8_t PLegemiddelMerkevare_0_0_0::GetVarseltrekant() const {
    return varseltrekant;
}

PLegemiddelMerkevare_0_4_0::PLegemiddelMerkevare_0_4_0(const LegemiddelMerkevare &legemiddelMerkevare, std::string &strblock,
                                                       std::map<std::string,uint32_t> &cache, std::vector<FestUuid> &festidblock,
                                                       FestUuidList_0_4_0 &festUuidList, ValueWithCodesetList &valueWithCodesetList,
                                                       ReseptgyldighetList &reseptgyldighetList) :
        PLegemiddel_0_4_0(legemiddelMerkevare, strblock, cache, festUuidList, valueWithCodesetList),
        vaksinestandard(legemiddelMerkevare.GetVaksinestandard(), strblock, cache),
        preparattype(legemiddelMerkevare.GetPreparattype(), strblock, cache),
        smak(legemiddelMerkevare.GetSmak(), strblock, cache),
        varenavn(legemiddelMerkevare.GetVarenavn(), strblock, cache),
        legemiddelformLang(legemiddelMerkevare.GetLegemiddelformLang(), strblock, cache),
        produsent(legemiddelMerkevare.GetProdusent(), strblock, cache),
        referanseprodukt(legemiddelMerkevare.GetReferanseprodukt(), strblock, cache),
        id(legemiddelMerkevare.GetId(), festidblock),
        preparatomtaleavsnitt(legemiddelMerkevare.GetPreparatomtaleavsnitt(), strblock, cache),
        sortertVirkestoffUtenStyrke(festUuidList.StoreList(legemiddelMerkevare.GetSortertVirkestoffUtenStyrke())),
        reseptgyldighet(),
        varseltrekant(ToRaw(legemiddelMerkevare.GetVarseltrekant()))
{
    {
        std::vector<PReseptgyldighet> list{};
        auto reseptgyldighet = legemiddelMerkevare.GetReseptgyldighet();
        for (const auto &r : reseptgyldighet) {
            list.emplace_back(r, strblock, cache);
        }
        this->reseptgyldighet = reseptgyldighetList.StoreList(list);
    }
}

PLegemiddelMerkevare_0_4_0::PLegemiddelMerkevare_0_4_0(const PLegemiddelMerkevare_0_0_0 &src) :
    PLegemiddel_0_4_0(static_cast<const PLegemiddel_0_0_0 &>(src)),
    vaksinestandard(src.vaksinestandard),
    preparattype(src.preparattype),
    smak(src.smak),
    varenavn(src.varenavn),
    legemiddelformLang(src.legemiddelformLang),
    produsent(src.produsent),
    referanseprodukt(src.referanseprodukt),
    id(src.id),
    preparatomtaleavsnitt(src.preparatomtaleavsnitt),
    sortertVirkestoffUtenStyrke(src.sortertVirkestoffUtenStyrke.CastToWider<GenericListItems64>()),
    reseptgyldighet(src.reseptgyldighet),
    varseltrekant(src.varseltrekant)
{}

bool PLegemiddelMerkevare_0_4_0::operator==(const PLegemiddelMerkevare_0_4_0 &other) const {
    return id == other.id &&
           static_cast<const PLegemiddel_0_4_0>(*this) == static_cast<const PLegemiddel_0_4_0>(other) &&
           vaksinestandard == other.vaksinestandard &&
           preparattype == other.preparattype &&
           smak == other.smak &&
           varenavn == other.varenavn &&
           legemiddelformLang == other.legemiddelformLang &&
           produsent == other.produsent &&
           referanseprodukt == other.referanseprodukt &&
           preparatomtaleavsnitt == other.preparatomtaleavsnitt &&
           sortertVirkestoffUtenStyrke == other.sortertVirkestoffUtenStyrke &&
           reseptgyldighet == other.reseptgyldighet &&
           varseltrekant == other.varseltrekant;
}

PValueWithCodeset PLegemiddelMerkevare_0_4_0::GetVaksinestandard() const {
    return vaksinestandard;
}
PValueWithDistinguishedName PLegemiddelMerkevare_0_4_0::GetPreparattype() const {
    return preparattype;
}
PValueWithDistinguishedName PLegemiddelMerkevare_0_4_0::GetSmak() const {
    return smak;
}
PString PLegemiddelMerkevare_0_4_0::GetVarenavn() const {
    return varenavn;
}
PString PLegemiddelMerkevare_0_4_0::GetLegemiddelformLang() const {
    return legemiddelformLang;
}
PString PLegemiddelMerkevare_0_4_0::GetProdusent() const {
    return produsent;
}
PString PLegemiddelMerkevare_0_4_0::GetReferanseprodukt() const {
    return referanseprodukt;
}
PFestId PLegemiddelMerkevare_0_4_0::GetId() const {
    return id;
}
PPreparatomtaleavsnitt PLegemiddelMerkevare_0_4_0::GetPreparatomtaleavsnitt() const {
    return preparatomtaleavsnitt;
}
GenericListItems64 PLegemiddelMerkevare_0_4_0::GetSortertVirkestoffUtenStyrke() const {
    return sortertVirkestoffUtenStyrke;
}
GenericListItems32 PLegemiddelMerkevare_0_4_0::GetReseptgyldighet() const {
    return reseptgyldighet;
}
uint8_t PLegemiddelMerkevare_0_4_0::GetVarseltrekant() const {
    return varseltrekant;
}

PLegemiddelMerkevare::PLegemiddelMerkevare(const PLegemiddelMerkevare_0_4_0 &p) : PLegemiddel(p), std::variant<PLegemiddelMerkevare_0_4_0,PLegemiddelMerkevare_0_0_0>(p) {}
PLegemiddelMerkevare::PLegemiddelMerkevare(const PLegemiddelMerkevare_0_0_0 &p) : PLegemiddel(p), std::variant<PLegemiddelMerkevare_0_4_0,PLegemiddelMerkevare_0_0_0>(p) {}

PValueWithCodeset PLegemiddelMerkevare::GetVaksinestandard() const {
    const std::variant<PLegemiddelMerkevare_0_4_0,PLegemiddelMerkevare_0_0_0> &p = *this;
    if (std::holds_alternative<PLegemiddelMerkevare_0_4_0>(p)) {
        return std::get<PLegemiddelMerkevare_0_4_0>(p).GetVaksinestandard();
    } else {
        return std::get<PLegemiddelMerkevare_0_0_0>(p).GetVaksinestandard();
    }
}

PValueWithDistinguishedName PLegemiddelMerkevare::GetPreparattype() const {
    const std::variant<PLegemiddelMerkevare_0_4_0,PLegemiddelMerkevare_0_0_0> &p = *this;
    if (std::holds_alternative<PLegemiddelMerkevare_0_4_0>(p)) {
        return std::get<PLegemiddelMerkevare_0_4_0>(p).GetPreparattype();
    } else {
        return std::get<PLegemiddelMerkevare_0_0_0>(p).GetPreparattype();
    }
}

PValueWithDistinguishedName PLegemiddelMerkevare::GetSmak() const {
    const std::variant<PLegemiddelMerkevare_0_4_0,PLegemiddelMerkevare_0_0_0> &p = *this;
    if (std::holds_alternative<PLegemiddelMerkevare_0_4_0>(p)) {
        return std::get<PLegemiddelMerkevare_0_4_0>(p).GetSmak();
    } else {
        return std::get<PLegemiddelMerkevare_0_0_0>(p).GetSmak();
    }
}

PString PLegemiddelMerkevare::GetVarenavn() const {
    const std::variant<PLegemiddelMerkevare_0_4_0,PLegemiddelMerkevare_0_0_0> &p = *this;
    if (std::holds_alternative<PLegemiddelMerkevare_0_4_0>(p)) {
        return std::get<PLegemiddelMerkevare_0_4_0>(p).GetVarenavn();
    } else {
        return std::get<PLegemiddelMerkevare_0_0_0>(p).GetVarenavn();
    }
}

PString PLegemiddelMerkevare::GetLegemiddelformLang() const {
    const std::variant<PLegemiddelMerkevare_0_4_0,PLegemiddelMerkevare_0_0_0> &p = *this;
    if (std::holds_alternative<PLegemiddelMerkevare_0_4_0>(p)) {
        return std::get<PLegemiddelMerkevare_0_4_0>(p).GetLegemiddelformLang();
    } else {
        return std::get<PLegemiddelMerkevare_0_0_0>(p).GetLegemiddelformLang();
    }
}

PString PLegemiddelMerkevare::GetProdusent() const {
    const std::variant<PLegemiddelMerkevare_0_4_0,PLegemiddelMerkevare_0_0_0> &p = *this;
    if (std::holds_alternative<PLegemiddelMerkevare_0_4_0>(p)) {
        return std::get<PLegemiddelMerkevare_0_4_0>(p).GetProdusent();
    } else {
        return std::get<PLegemiddelMerkevare_0_0_0>(p).GetProdusent();
    }
}

PString PLegemiddelMerkevare::GetReferanseprodukt() const {
    const std::variant<PLegemiddelMerkevare_0_4_0,PLegemiddelMerkevare_0_0_0> &p = *this;
    if (std::holds_alternative<PLegemiddelMerkevare_0_4_0>(p)) {
        return std::get<PLegemiddelMerkevare_0_4_0>(p).GetReferanseprodukt();
    } else {
        return std::get<PLegemiddelMerkevare_0_0_0>(p).GetReferanseprodukt();
    }
}

PFestId PLegemiddelMerkevare::GetId() const {
    const std::variant<PLegemiddelMerkevare_0_4_0,PLegemiddelMerkevare_0_0_0> &p = *this;
    if (std::holds_alternative<PLegemiddelMerkevare_0_4_0>(p)) {
        return std::get<PLegemiddelMerkevare_0_4_0>(p).GetId();
    } else {
        return std::get<PLegemiddelMerkevare_0_0_0>(p).GetId();
    }
}

PPreparatomtaleavsnitt PLegemiddelMerkevare::GetPreparatomtaleavsnitt() const {
    const std::variant<PLegemiddelMerkevare_0_4_0,PLegemiddelMerkevare_0_0_0> &p = *this;
    if (std::holds_alternative<PLegemiddelMerkevare_0_4_0>(p)) {
        return std::get<PLegemiddelMerkevare_0_4_0>(p).GetPreparatomtaleavsnitt();
    } else {
        return std::get<PLegemiddelMerkevare_0_0_0>(p).GetPreparatomtaleavsnitt();
    }
}

std::variant<GenericListItems32, GenericListItems64> PLegemiddelMerkevare::GetSortertVirkestoffUtenStyrke() const {
    const std::variant<PLegemiddelMerkevare_0_4_0,PLegemiddelMerkevare_0_0_0> &p = *this;
    if (std::holds_alternative<PLegemiddelMerkevare_0_4_0>(p)) {
        return std::get<PLegemiddelMerkevare_0_4_0>(p).GetSortertVirkestoffUtenStyrke();
    } else {
        return std::get<PLegemiddelMerkevare_0_0_0>(p).GetSortertVirkestoffUtenStyrke();
    }
}

GenericListItems32 PLegemiddelMerkevare::GetReseptgyldighet() const {
    const std::variant<PLegemiddelMerkevare_0_4_0,PLegemiddelMerkevare_0_0_0> &p = *this;
    if (std::holds_alternative<PLegemiddelMerkevare_0_4_0>(p)) {
        return std::get<PLegemiddelMerkevare_0_4_0>(p).GetReseptgyldighet();
    } else {
        return std::get<PLegemiddelMerkevare_0_0_0>(p).GetReseptgyldighet();
    }
}

uint8_t PLegemiddelMerkevare::GetVarseltrekant() const {
    const std::variant<PLegemiddelMerkevare_0_4_0,PLegemiddelMerkevare_0_0_0> &p = *this;
    if (std::holds_alternative<PLegemiddelMerkevare_0_4_0>(p)) {
        return std::get<PLegemiddelMerkevare_0_4_0>(p).GetVarseltrekant();
    } else {
        return std::get<PLegemiddelMerkevare_0_0_0>(p).GetVarseltrekant();
    }
}
