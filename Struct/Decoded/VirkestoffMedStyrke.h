//
// Created by sigsegv on 12/17/22.
//

#ifndef LEGEMFEST_VIRKESTOFFMEDSTYRKE_H
#define LEGEMFEST_VIRKESTOFFMEDSTYRKE_H

#include "Styrke.h"
#include "Styrkenevner.h"
#include "Styrkeoperator.h"
#include "Atc.h"

class VirkestoffMedStyrke {
private:
    std::string id;
    std::string refVirkestoff;
    Styrke styrke;
    Styrkenevner styrkenevner;
    Styrkeoperator styrkeoperator;
    Styrke alternativStyrke;
    Styrkenevner alternativStyrkenevner;
    Atc atcKombipreparat;
    double styrkeOvreVerdi;
public:
    VirkestoffMedStyrke() : id(), refVirkestoff(), styrke(), styrkenevner(), styrkeoperator(), alternativStyrke(),
                            alternativStyrkenevner(), atcKombipreparat(), styrkeOvreVerdi(0.0) {}
    VirkestoffMedStyrke(const std::string &id, const std::string &refVirkestoff, const Styrke &styrke,
                        const Styrkenevner &styrkenevner, const Styrkeoperator &styrkeoperator,
                        const Styrke &alternativStyrke, const Styrkenevner &alternativStyrkenevner,
                        const Atc &atcKombipreparat, double styrkeOvreVerdi) :
            id(id), refVirkestoff(refVirkestoff), styrke(styrke), styrkenevner(styrkenevner),
            styrkeoperator(styrkeoperator), alternativStyrke(alternativStyrke),
            alternativStyrkenevner(alternativStyrkenevner), atcKombipreparat(atcKombipreparat),
            styrkeOvreVerdi(styrkeOvreVerdi) {}
    [[nodiscard]] std::string GetId() const;
    [[nodiscard]] std::string GetRefVirkestoff() const;
    [[nodiscard]] Styrke GetStyrke() const;
    [[nodiscard]] Styrkenevner GetStyrkenevner() const;
    [[nodiscard]] Styrkeoperator GetStyrkeoperator() const;
    [[nodiscard]] Styrke GetAlternativStyrke() const;
    [[nodiscard]] Styrkenevner GetAlternativStyrkenevner() const;
    [[nodiscard]] Atc GetAtcKombipreparat() const;
    [[nodiscard]] double GetStyrkeOvreVerdi() const;
};


#endif //LEGEMFEST_VIRKESTOFFMEDSTYRKE_H
