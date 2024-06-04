//
// Created by sigsegv on 1/10/23.
//

#include <Struct/Packed/PLegemiddelMerkevare.h>
#include <Struct/Packed/FestUuidList.h>
#include <Struct/Packed/ValueWithCodesetList.h>
#include <Struct/Packed/ReseptgyldighetList.h>
#include <Struct/Decoded/LegemiddelMerkevare.h>

PLegemiddelMerkevare::PLegemiddelMerkevare(const LegemiddelMerkevare &legemiddelMerkevare, std::string &strblock,
                                           std::map<std::string,uint32_t> &cache, std::vector<FestUuid> &festidblock,
                                           FestUuidList &festUuidList, ValueWithCodesetList &valueWithCodesetList,
                                           ReseptgyldighetList &reseptgyldighetList) :
        PLegemiddel(legemiddelMerkevare, strblock, cache, festUuidList, valueWithCodesetList),
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

bool PLegemiddelMerkevare::operator==(const PLegemiddelMerkevare &other) const {
    return id == other.id &&
           static_cast<const PLegemiddel>(*this) == static_cast<const PLegemiddel>(other) &&
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

PValueWithCodeset PLegemiddelMerkevare::GetVaksinestandard() const {
    return vaksinestandard;
}
PValueWithDistinguishedName PLegemiddelMerkevare::GetPreparattype() const {
    return preparattype;
}
PValueWithDistinguishedName PLegemiddelMerkevare::GetSmak() const {
    return smak;
}
PString PLegemiddelMerkevare::GetVarenavn() const {
    return varenavn;
}
PString PLegemiddelMerkevare::GetLegemiddelformLang() const {
    return legemiddelformLang;
}
PString PLegemiddelMerkevare::GetProdusent() const {
    return produsent;
}
PString PLegemiddelMerkevare::GetReferanseprodukt() const {
    return referanseprodukt;
}
PFestId PLegemiddelMerkevare::GetId() const {
    return id;
}
PPreparatomtaleavsnitt PLegemiddelMerkevare::GetPreparatomtaleavsnitt() const {
    return preparatomtaleavsnitt;
}
GenericListItems32 PLegemiddelMerkevare::GetSortertVirkestoffUtenStyrke() const {
    return sortertVirkestoffUtenStyrke;
}
GenericListItems32 PLegemiddelMerkevare::GetReseptgyldighet() const {
    return reseptgyldighet;
}
uint8_t PLegemiddelMerkevare::GetVarseltrekant() const {
    return varseltrekant;
}
