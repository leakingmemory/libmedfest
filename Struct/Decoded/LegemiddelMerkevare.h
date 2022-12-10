//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_LEGEMIDDELMERKEVARE_H
#define LEGEMFEST_LEGEMIDDELMERKEVARE_H


#include "Legemiddel.h"
#include "Preparattype.h"

class LegemiddelMerkevare : public Legemiddel {
private:
    Preparattype preparattype;
    std::string varenavn;
    std::string legemiddelformLang;
    std::string produsent;
public:
    LegemiddelMerkevare() : Legemiddel(), preparattype(), varenavn(), legemiddelformLang(), produsent() {}
    LegemiddelMerkevare(
            const Legemiddel &legemiddel, const Preparattype &preparattype, const std::string &varenavn,
            const std::string &legemiddelformLang, const std::string &produsent
        ) :
            Legemiddel(legemiddel), preparattype(preparattype), varenavn(varenavn),
            legemiddelformLang(legemiddelformLang), produsent(produsent) {}
    [[nodiscard]] Preparattype GetPreparattype() const;
    [[nodiscard]] std::string GetVarenavn() const;
    [[nodiscard]] std::string GetLegemiddelformLang() const;
    [[nodiscard]] std::string GetProdusent() const;
};


#endif //LEGEMFEST_LEGEMIDDELMERKEVARE_H
