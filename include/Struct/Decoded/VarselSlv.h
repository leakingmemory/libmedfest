//
// Created by sigsegv on 12/27/22.
//

#ifndef LEGEMFEST_VARSELSLV_H
#define LEGEMFEST_VARSELSLV_H

#include "ValueWithCodeSet.h"
#include "Visningsregel.h"
#include "Lenke.h"
#include "Referanseelement.h"
#include <vector>

class PVarselSlv_0_0_0;
class PVarselSlv_0_4_0;

class VarselSlv {
    friend PVarselSlv_0_0_0;
    friend PVarselSlv_0_4_0;
private:
    ValueWithCodeSet type;
    std::string overskrift;
    std::string varseltekst;
    std::vector<Visningsregel> visningsregel{};
    std::string fraDato;
    Lenke lenke;
    Referanseelement referanseelement;
public:
    VarselSlv() : type(), overskrift(), varseltekst(), fraDato(), lenke(), referanseelement() {}
    VarselSlv(const ValueWithCodeSet &type, const std::string &overskrift, const std::string &varseltekst,
              const std::vector<Visningsregel> &visningsregel, const std::string &fraDato, const Lenke &lenke,
              const Referanseelement &referanseelement) :
            type(type), overskrift(overskrift), varseltekst(varseltekst), visningsregel(visningsregel),
            fraDato(fraDato), lenke(lenke), referanseelement(referanseelement) {}
    [[nodiscard]] ValueWithCodeSet GetType() const;
    [[nodiscard]] std::string GetOverskrift() const;
    [[nodiscard]] std::string GetVarseltekst() const;
    [[nodiscard]] std::vector<Visningsregel> GetVisningsregel() const;
    [[nodiscard]] std::string GetFraDato() const;
    [[nodiscard]] Lenke GetLenke() const;
    [[nodiscard]] Referanseelement GetReferanseelement() const;
};


#endif //LEGEMFEST_VARSELSLV_H
