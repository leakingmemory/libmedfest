//
// Created by sigsegv on 2/2/23.
//

#include <Struct/Packed/PVirkestoffMedStyrke.h>
#include <Struct/Decoded/VirkestoffMedStyrke.h>

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

bool PVirkestoffMedStyrke::operator==(const PVirkestoffMedStyrke &other) const {
    return id == other.id &&
           styrke == other.styrke &&
           styrkenevner == other.styrkenevner &&
           alternativStyrke == other.alternativStyrke &&
           alternativStyrkenevner == other.alternativStyrkenevner &&
           styrkeoperator == other.styrkeoperator &&
           atcKombipreparat == other.atcKombipreparat &&
           styrkeOvreVerdi == other.styrkeOvreVerdi &&
           refVirkestoff == other.refVirkestoff;
}

PValueUnit PVirkestoffMedStyrke::GetStyrke() const {
    return styrke;
}
PValueUnit PVirkestoffMedStyrke::GetStyrkenevner() const {
    return styrkenevner;
}
PValueUnit PVirkestoffMedStyrke::GetAlternativStyrke() const {
    return alternativStyrke;
}
PValueUnit PVirkestoffMedStyrke::GetAlternativStyrkenevner() const {
    return alternativStyrkenevner;
}
PValueWithCodeset PVirkestoffMedStyrke::GetStyrkeoperator() const {
    return styrkeoperator;
}
PValueWithCodeset PVirkestoffMedStyrke::GetAtcKombipreparat() const {
    return atcKombipreparat;
}
double PVirkestoffMedStyrke::GetStyrkeOvreVerdi() const {
    return styrkeOvreVerdi;
}
PFestId PVirkestoffMedStyrke::GetId() const {
    return id;
}
PFestId PVirkestoffMedStyrke::GetRefVirkestoff() const {
    return refVirkestoff;
}
