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

class LegemiddelMerkevare : public Legemiddel {
private:
    Preparattype preparattype;
    std::string varenavn;
    std::string legemiddelformLang;
    std::string produsent;
    std::string reseptgyldighet;
    MaybeBoolean varseltrekant;
    std::string referanseprodukt;
    Preparatomtaleavsnitt preparatomtaleavsnitt;
    Smak smak;
    std::vector<std::string> sortertVirkestoffUtenStyrke;
public:
    LegemiddelMerkevare() :
            Legemiddel(), preparattype(), varenavn(), legemiddelformLang(), produsent(), reseptgyldighet(),
            varseltrekant(MaybeBoolean::UNSPECIFIED), referanseprodukt(), preparatomtaleavsnitt(), smak(),
            sortertVirkestoffUtenStyrke() {}
    LegemiddelMerkevare(
            const Legemiddel &legemiddel, const Preparattype &preparattype, const std::string &varenavn,
            const std::string &legemiddelformLang, const std::string &produsent, const std::string &reseptgyldighet,
            MaybeBoolean varseltrekant, const std::string &referanseprodukt,
            const Preparatomtaleavsnitt &preparatomtaleavsnitt, const Smak &smak,
            const std::vector<std::string> &sortertVirkestoffUtenStyrke
        ) :
            Legemiddel(legemiddel), preparattype(preparattype), varenavn(varenavn),
            legemiddelformLang(legemiddelformLang), produsent(produsent), reseptgyldighet(reseptgyldighet),
            varseltrekant(varseltrekant), referanseprodukt(referanseprodukt),
            preparatomtaleavsnitt(preparatomtaleavsnitt), smak(smak),
            sortertVirkestoffUtenStyrke(sortertVirkestoffUtenStyrke) {}
    [[nodiscard]] Preparattype GetPreparattype() const;
    [[nodiscard]] std::string GetVarenavn() const;
    [[nodiscard]] std::string GetLegemiddelformLang() const;
    [[nodiscard]] std::string GetProdusent() const;
    [[nodiscard]] std::string GetReseptgyldighet() const;
    [[nodiscard]] MaybeBoolean GetVarseltrekant() const;
    [[nodiscard]] std::string GetReferanseprodukt() const;
    [[nodiscard]] Preparatomtaleavsnitt GetPreparatomtaleavsnitt() const;
    [[nodiscard]] Smak GetSmak() const;
    [[nodiscard]] std::vector<std::string> GetSortertVirkestoffUtenStyrke() const;
};


#endif //LEGEMFEST_LEGEMIDDELMERKEVARE_H
