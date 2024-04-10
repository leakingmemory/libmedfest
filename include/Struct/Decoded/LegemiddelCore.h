//
// Created by sigsegv on 12/11/22.
//

#ifndef LEGEMFEST_LEGEMIDDELCORE_H
#define LEGEMFEST_LEGEMIDDELCORE_H

#include "Atc.h"
#include "Reseptgruppe.h"
#include "LegemiddelformKort.h"
#include "TypeSoknadSlv.h"
#include "MaybeBoolean.h"
#include "SvartTrekant.h"
#include <vector>

class LegemiddelCore {
private:
    Atc atc;
    std::string navnFormStyrke;
    Reseptgruppe reseptgruppe;
    LegemiddelformKort legemiddelformKort;
    std::vector<std::string> refVilkar;
    TypeSoknadSlv typeSoknadSlv;
    MaybeBoolean opioidsoknad;
    SvartTrekant svartTrekant;
public:
    LegemiddelCore() : atc(), navnFormStyrke(), reseptgruppe(), legemiddelformKort(), refVilkar(), typeSoknadSlv(),
            opioidsoknad(), svartTrekant() {}
    LegemiddelCore(const Atc &atc, const std::string &navnFormStyrke, const Reseptgruppe &reseptgruppe,
               const LegemiddelformKort legemiddelformKort, const std::vector<std::string> &refVilkar,
               const TypeSoknadSlv &typeSoknadSlv, MaybeBoolean opioidsoknad, const SvartTrekant &svartTrekant) :
            atc(atc), navnFormStyrke(navnFormStyrke), reseptgruppe(reseptgruppe),
            legemiddelformKort(legemiddelformKort), refVilkar(refVilkar), typeSoknadSlv(typeSoknadSlv),
            opioidsoknad(opioidsoknad), svartTrekant(svartTrekant) {}
    virtual ~LegemiddelCore() = default;
    [[nodiscard]] Atc GetAtc() const;
    [[nodiscard]] std::string GetNavnFormStyrke() const;
    [[nodiscard]] Reseptgruppe GetReseptgruppe() const;
    [[nodiscard]] LegemiddelformKort GetLegemiddelformKort() const;
    [[nodiscard]] std::vector<std::string> GetRefVilkar() const;
    [[nodiscard]] TypeSoknadSlv GetTypeSoknadSlv() const;
    [[nodiscard]] MaybeBoolean GetOpioidsoknad() const;
    [[nodiscard]] SvartTrekant GetSvartTrekant() const;
};


#endif //LEGEMFEST_LEGEMIDDELCORE_H
