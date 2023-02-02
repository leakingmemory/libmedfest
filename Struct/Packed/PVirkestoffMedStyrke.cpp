//
// Created by sigsegv on 2/2/23.
//

#include "PVirkestoffMedStyrke.h"
#include "../Decoded/VirkestoffMedStyrke.h"

PVirkestoffMedStyrke::PVirkestoffMedStyrke(const VirkestoffMedStyrke &virkestoffMedStyrke, std::vector<FestUuid> &uuidblock,
                                           std::string &strblock) :
        styrke(virkestoffMedStyrke.GetStyrke(), strblock),
        styrkenevner(virkestoffMedStyrke.GetStyrkenevner(), strblock),
        alternativStyrke(virkestoffMedStyrke.GetAlternativStyrke(), strblock),
        alternativStyrkenevner(virkestoffMedStyrke.GetAlternativStyrkenevner(), strblock),
        styrkeoperator(virkestoffMedStyrke.GetStyrkeoperator(), strblock),
        atcKombipreparat(virkestoffMedStyrke.GetAtcKombipreparat(), strblock),
        styrkeOvreVerdi(virkestoffMedStyrke.GetStyrkeOvreVerdi()),
        id(virkestoffMedStyrke.GetId(), uuidblock),
        refVirkestoff(virkestoffMedStyrke.GetRefVirkestoff(), uuidblock)
{
}