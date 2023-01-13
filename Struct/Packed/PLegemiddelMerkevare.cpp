//
// Created by sigsegv on 1/10/23.
//

#include "PLegemiddelMerkevare.h"
#include "FestUuidList.h"
#include "ValueWithCodesetList.h"
#include "ReseptgyldighetList.h"
#include "../Decoded/LegemiddelMerkevare.h"

PLegemiddelMerkevare::PLegemiddelMerkevare(const LegemiddelMerkevare &legemiddelMerkevare, std::string &strblock,
                                           std::vector<FestUuid> &festidblock, FestUuidList &festUuidList,
                                           ValueWithCodesetList &valueWithCodesetList, ReseptgyldighetList &reseptgyldighetList) :
        PLegemiddel(legemiddelMerkevare, strblock, festUuidList, valueWithCodesetList),
        vaksinestandard(legemiddelMerkevare.GetVaksinestandard(), strblock),
        preparattype(legemiddelMerkevare.GetPreparattype(), strblock),
        smak(legemiddelMerkevare.GetSmak(), strblock),
        varenavn(legemiddelMerkevare.GetVarenavn(), strblock),
        legemiddelformLang(legemiddelMerkevare.GetLegemiddelformLang(), strblock),
        produsent(legemiddelMerkevare.GetProdusent(), strblock),
        referanseprodukt(legemiddelMerkevare.GetReferanseprodukt(), strblock),
        id(legemiddelMerkevare.GetId(), festidblock),
        preparatomtaleavsnitt(legemiddelMerkevare.GetPreparatomtaleavsnitt(), strblock),
        sortertVirkestoffUtenStyrke(festUuidList.StoreList(legemiddelMerkevare.GetSortertVirkestoffUtenStyrke())),
        reseptgyldighet(),
        varseltrekant(ToRaw(legemiddelMerkevare.GetVarseltrekant()))
{
    {
        std::vector<PReseptgyldighet> list{};
        auto reseptgyldighet = legemiddelMerkevare.GetReseptgyldighet();
        for (const auto &r : reseptgyldighet) {
            list.emplace_back(r, strblock);
        }
        this->reseptgyldighet = reseptgyldighetList.StoreList(list);
    }
}