//
// Created by sigsegv on 1/10/23.
//

#include "PLegemiddelMerkevare.h"
#include "FestUuidList.h"
#include "ValueWithCodesetList.h"
#include "ReseptgyldighetList.h"
#include "../Decoded/LegemiddelMerkevare.h"

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