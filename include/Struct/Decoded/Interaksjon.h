//
// Created by sigsegv on 12/29/22.
//

#ifndef LEGEMFEST_INTERAKSJON_H
#define LEGEMFEST_INTERAKSJON_H

#include "Relevans.h"
#include "Kildegrunnlag.h"
#include "Visningsregel.h"
#include "Referanse.h"
#include "Substansgruppe.h"
#include <vector>

class PInteraksjon;

class Interaksjon {
    friend PInteraksjon;
private:
    std::string id;
    Relevans relevans;
    std::string kliniskKonsekvens;
    std::string interaksjonsmekanisme;
    Kildegrunnlag kildegrunnlag;
    std::string handtering;
    std::vector<Visningsregel> visningsregel;
    std::vector<Referanse> referanse;
    std::vector<Substansgruppe> substansgruppe;
    std::string situasjonskriterium;
public:
    Interaksjon() : id(), relevans(), kliniskKonsekvens(), kildegrunnlag(), handtering(), visningsregel(),
                    substansgruppe() {}
    Interaksjon(const std::string &id, const Relevans &relevans, const std::string &kliniskKonsekvens,
                const std::string &interaksjonsmekanisme, const Kildegrunnlag &kildegrunnlag,
                const std::string &handtering, const std::vector<Visningsregel> &visningsregel,
                const std::vector<Referanse> &referanse, const std::vector<Substansgruppe> &substansgruppe,
                const std::string &situasjonskriterium) :
            id(id), relevans(relevans), kliniskKonsekvens(kliniskKonsekvens),
            interaksjonsmekanisme(interaksjonsmekanisme), kildegrunnlag(kildegrunnlag), handtering(handtering),
            visningsregel(visningsregel), referanse(referanse), substansgruppe(substansgruppe),
            situasjonskriterium(situasjonskriterium) {}
    [[nodiscard]] std::string GetId() const;
    [[nodiscard]] Relevans GetRelevans() const;
    [[nodiscard]] std::string GetKliniskKonsekvens() const;
    [[nodiscard]] std::string GetInteraksjonsmekanisme() const;
    [[nodiscard]] Kildegrunnlag GetKildegrunnlag() const;
    [[nodiscard]] std::string GetHandtering() const;
    [[nodiscard]] std::vector<Visningsregel> GetVisningsregel() const;
    [[nodiscard]] std::vector<Referanse> GetReferanse() const;
    [[nodiscard]] std::vector<Substansgruppe> GetSubstansgruppe() const;
    [[nodiscard]] std::string GetSituasjonskriterium() const;
};


#endif //LEGEMFEST_INTERAKSJON_H
