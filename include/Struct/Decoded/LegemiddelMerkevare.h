//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_LEGEMIDDELMERKEVARE_H
#define LEGEMFEST_LEGEMIDDELMERKEVARE_H


#include "Legemiddel.h"
#include "Preparattype.h"
#include "MaybeBoolean.h"
#include "Preparatomtaleavsnitt.h"
#include "Smak.h"
#include "Reseptgyldighet.h"
#include "Vaksinestandard.h"

class LegemiddelMerkevare : public Legemiddel {
private:
    Preparattype preparattype;
    std::string id;
    std::string varenavn;
    std::string legemiddelformLang;
    std::string produsent;
    std::vector<Reseptgyldighet> reseptgyldighet;
    MaybeBoolean varseltrekant;
    std::string referanseprodukt;
    Preparatomtaleavsnitt preparatomtaleavsnitt;
    Smak smak;
    std::vector<std::string> sortertVirkestoffUtenStyrke;
    Vaksinestandard vaksinestandard;
public:
    LegemiddelMerkevare() :
            Legemiddel(), preparattype(), id(), varenavn(), legemiddelformLang(), produsent(), reseptgyldighet(),
            varseltrekant(MaybeBoolean::UNSPECIFIED), referanseprodukt(), preparatomtaleavsnitt(), smak(),
            sortertVirkestoffUtenStyrke(), vaksinestandard() {}
    LegemiddelMerkevare(
            const Legemiddel &legemiddel, const Preparattype &preparattype, const std::string &id, const std::string &varenavn,
            const std::string &legemiddelformLang, const std::string &produsent,
            const std::vector<Reseptgyldighet> &reseptgyldighet, MaybeBoolean varseltrekant,
            const std::string &referanseprodukt, const Preparatomtaleavsnitt &preparatomtaleavsnitt, const Smak &smak,
            const std::vector<std::string> &sortertVirkestoffUtenStyrke, const Vaksinestandard &vaksinestandard
        ) :
            Legemiddel(legemiddel), preparattype(preparattype), id(id), varenavn(varenavn),
            legemiddelformLang(legemiddelformLang), produsent(produsent), reseptgyldighet(reseptgyldighet),
            varseltrekant(varseltrekant), referanseprodukt(referanseprodukt),
            preparatomtaleavsnitt(preparatomtaleavsnitt), smak(smak),
            sortertVirkestoffUtenStyrke(sortertVirkestoffUtenStyrke), vaksinestandard(vaksinestandard) {}
    [[nodiscard]] Preparattype GetPreparattype() const;
    [[nodiscard]] std::string GetId() const;
    [[nodiscard]] std::string GetVarenavn() const;
    [[nodiscard]] std::string GetLegemiddelformLang() const;
    [[nodiscard]] std::string GetProdusent() const;
    [[nodiscard]] std::vector<Reseptgyldighet> GetReseptgyldighet() const;
    [[nodiscard]] MaybeBoolean GetVarseltrekant() const;
    [[nodiscard]] std::string GetReferanseprodukt() const;
    [[nodiscard]] Preparatomtaleavsnitt GetPreparatomtaleavsnitt() const;
    [[nodiscard]] Smak GetSmak() const;
    [[nodiscard]] std::vector<std::string> GetSortertVirkestoffUtenStyrke() const;
    [[nodiscard]] Vaksinestandard GetVaksinestandard() const;
};


#endif //LEGEMFEST_LEGEMIDDELMERKEVARE_H
