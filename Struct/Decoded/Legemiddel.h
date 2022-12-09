//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_LEGEMIDDEL_H
#define LEGEMFEST_LEGEMIDDEL_H


#include "Atc.h"
#include "Reseptgruppe.h"
#include "LegemiddelformKort.h"

class Legemiddel {
private:
    Atc atc;
    std::string navnFormStyrke;
    Reseptgruppe reseptgruppe;
    LegemiddelformKort legemiddelformKort;
public:
    Legemiddel() : atc(), navnFormStyrke(), reseptgruppe(), legemiddelformKort() {}
    Legemiddel(const Atc &atc, const std::string &navnFormStyrke, const Reseptgruppe &reseptgruppe, const LegemiddelformKort legemiddelformKort) :
            atc(atc), navnFormStyrke(navnFormStyrke), reseptgruppe(reseptgruppe), legemiddelformKort(legemiddelformKort) {}
    [[nodiscard]] Atc GetAtc() const;
    [[nodiscard]] std::string GetNavnFormStyrke() const;
    [[nodiscard]] Reseptgruppe GetReseptgruppe() const;
    [[nodiscard]] LegemiddelformKort GetLegemiddelformKort() const;
};


#endif //LEGEMFEST_LEGEMIDDEL_H
