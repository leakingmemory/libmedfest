//
// Created by sigsegv on 2/2/23.
//

#include "PVirkestoffMedStyrke.h"
#include "../Decoded/VirkestoffMedStyrke.h"

PVirkestoffMedStyrke::PVirkestoffMedStyrke(const VirkestoffMedStyrke &virkestoffMedStyrke, std::vector<FestUuid> &uuidblock,
                                           std::string &strblock, std::map<std::string,uint32_t> &cache) :
        styrke(virkestoffMedStyrke.GetStyrke(), strblock, cache),
        styrkenevner(virkestoffMedStyrke.GetStyrkenevner(), strblock, cache),
        alternativStyrke(virkestoffMedStyrke.GetAlternativStyrke(), strblock, cache),
        alternativStyrkenevner(virkestoffMedStyrke.GetAlternativStyrkenevner(), strblock, cache),
        styrkeoperator(virkestoffMedStyrke.GetStyrkeoperator(), strblock, cache),
        atcKombipreparat(virkestoffMedStyrke.GetAtcKombipreparat(), strblock, cache),
        styrkeOvreVerdi(virkestoffMedStyrke.GetStyrkeOvreVerdi()),
        id(virkestoffMedStyrke.GetId(), uuidblock),
        refVirkestoff(virkestoffMedStyrke.GetRefVirkestoff(), uuidblock)
{
}