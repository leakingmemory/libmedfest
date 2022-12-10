//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_LEGEMIDDELMERKEVARE_H
#define LEGEMFEST_LEGEMIDDELMERKEVARE_H


#include "Legemiddel.h"
#include "Preparattype.h"
#include "MaybeBoolean.h"

class LegemiddelMerkevare : public Legemiddel {
private:
    Preparattype preparattype;
    std::string varenavn;
    std::string legemiddelformLang;
    std::string produsent;
    std::string reseptgyldighet;
    MaybeBoolean varseltrekant;
    std::string referanseprodukt;
public:
    LegemiddelMerkevare() :
            Legemiddel(), preparattype(), varenavn(), legemiddelformLang(), produsent(), reseptgyldighet(),
            varseltrekant(MaybeBoolean::UNSPECIFIED), referanseprodukt() {}
    LegemiddelMerkevare(
            const Legemiddel &legemiddel, const Preparattype &preparattype, const std::string &varenavn,
            const std::string &legemiddelformLang, const std::string &produsent, const std::string &reseptgyldighet,
            MaybeBoolean varseltrekant, const std::string &referanseprodukt
        ) :
            Legemiddel(legemiddel), preparattype(preparattype), varenavn(varenavn),
            legemiddelformLang(legemiddelformLang), produsent(produsent), reseptgyldighet(reseptgyldighet),
            varseltrekant(varseltrekant), referanseprodukt(referanseprodukt) {}
    [[nodiscard]] Preparattype GetPreparattype() const;
    [[nodiscard]] std::string GetVarenavn() const;
    [[nodiscard]] std::string GetLegemiddelformLang() const;
    [[nodiscard]] std::string GetProdusent() const;
    [[nodiscard]] std::string GetReseptgyldighet() const;
    [[nodiscard]] MaybeBoolean GetVarseltrekant() const;
    [[nodiscard]] std::string GetReferanseprodukt() const;
};


#endif //LEGEMFEST_LEGEMIDDELMERKEVARE_H
