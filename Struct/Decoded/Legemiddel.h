//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_LEGEMIDDEL_H
#define LEGEMFEST_LEGEMIDDEL_H


#include "Atc.h"
#include "Reseptgruppe.h"
#include "LegemiddelformKort.h"
#include "TypeSoknadSlv.h"
#include "AdministreringLegemiddel.h"
#include "MaybeBoolean.h"
#include <vector>

class Legemiddel {
private:
    Atc atc;
    std::string navnFormStyrke;
    Reseptgruppe reseptgruppe;
    LegemiddelformKort legemiddelformKort;
    std::vector<std::string> refVilkar;
    TypeSoknadSlv typeSoknadSlv;
    AdministreringLegemiddel administreringLegemiddel;
    std::vector<std::string> sortertVirkestoffMedStyrke;
    MaybeBoolean opioidsoknad;
public:
    Legemiddel() : atc(), navnFormStyrke(), reseptgruppe(), legemiddelformKort(), refVilkar(), typeSoknadSlv(),
                   administreringLegemiddel(), sortertVirkestoffMedStyrke(), opioidsoknad(MaybeBoolean::UNSPECIFIED) {}
    Legemiddel(const Atc &atc, const std::string &navnFormStyrke, const Reseptgruppe &reseptgruppe,
               const LegemiddelformKort legemiddelformKort, const std::vector<std::string> &refVilkar,
               const TypeSoknadSlv &typeSoknadSlv, const AdministreringLegemiddel &administreringLegemiddel,
               const std::vector<std::string> &sortertVirkestoffMedStyrke, MaybeBoolean opioidsoknad) :
            atc(atc), navnFormStyrke(navnFormStyrke), reseptgruppe(reseptgruppe),
            legemiddelformKort(legemiddelformKort), refVilkar(refVilkar), typeSoknadSlv(typeSoknadSlv),
            administreringLegemiddel(administreringLegemiddel), sortertVirkestoffMedStyrke(sortertVirkestoffMedStyrke),
            opioidsoknad(opioidsoknad) {}
    Atc GetAtc() const;
    std::string GetNavnFormStyrke() const;
    Reseptgruppe GetReseptgruppe() const;
    LegemiddelformKort GetLegemiddelformKort() const;
    std::vector<std::string> GetRefVilkar() const;
    TypeSoknadSlv GetTypeSoknadSlv() const;
    AdministreringLegemiddel GetAdministreringLegemiddel() const;
    std::vector<std::string> GetSortertVirkestoffMedStyrke() const;
    MaybeBoolean GetOpioidsoknad() const;
};


#endif //LEGEMFEST_LEGEMIDDEL_H
