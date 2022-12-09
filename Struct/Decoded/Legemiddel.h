//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_LEGEMIDDEL_H
#define LEGEMFEST_LEGEMIDDEL_H


#include "Atc.h"
#include "Reseptgruppe.h"
#include "LegemiddelformKort.h"
#include "TypeSoknadSlv.h"
#include <vector>

class Legemiddel {
private:
    Atc atc;
    std::string navnFormStyrke;
    Reseptgruppe reseptgruppe;
    LegemiddelformKort legemiddelformKort;
    std::vector<std::string> refVilkar;
    TypeSoknadSlv typeSoknadSlv;
public:
    Legemiddel() : atc(), navnFormStyrke(), reseptgruppe(), legemiddelformKort(), refVilkar() {}
    Legemiddel(const Atc &atc, const std::string &navnFormStyrke, const Reseptgruppe &reseptgruppe,
               const LegemiddelformKort legemiddelformKort, const std::vector<std::string> &refVilkar,
               const TypeSoknadSlv &typeSoknadSlv) :
            atc(atc), navnFormStyrke(navnFormStyrke), reseptgruppe(reseptgruppe),
            legemiddelformKort(legemiddelformKort), refVilkar(refVilkar), typeSoknadSlv(typeSoknadSlv) {}
    [[nodiscard]] Atc GetAtc() const;
    [[nodiscard]] std::string GetNavnFormStyrke() const;
    [[nodiscard]] Reseptgruppe GetReseptgruppe() const;
    [[nodiscard]] LegemiddelformKort GetLegemiddelformKort() const;
    [[nodiscard]] std::vector<std::string> GetRefVilkar() const;
    [[nodiscard]] TypeSoknadSlv GetTypeSoknadSlv() const;
};


#endif //LEGEMFEST_LEGEMIDDEL_H
