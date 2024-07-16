//
// Created by sigsegv on 2/4/23.
//

#include <Struct/Packed/PVirkestoff.h>
#include <Struct/Packed/FestUuidList.h>
#include <Struct/Decoded/Virkestoff.h>

PVirkestoff_0_0_0::PVirkestoff_0_0_0(const Virkestoff &virkestoff, FestUuidList_0_0_0 &festUuidList, std::vector<FestUuid> &idblock,
                         std::string &strblock, std::map<std::string,uint32_t> &cache) :
        refVirkestoff(festUuidList.StoreList(virkestoff.GetRefVirkestoff())),
        id(virkestoff.GetId(), idblock),
        navn(virkestoff.GetNavn(), strblock, cache),
        navnEngelsk(virkestoff.GetNavnEngelsk(), strblock, cache)
{
}

bool PVirkestoff_0_0_0::operator==(const PVirkestoff_0_0_0 &other) const {
    return id == other.id &&
           refVirkestoff == other.refVirkestoff &&
           navn == other.navn &&
           navnEngelsk == other.navnEngelsk;
}

PVirkestoff_0_4_0::PVirkestoff_0_4_0(const Virkestoff &virkestoff, FestUuidList_0_4_0 &festUuidList, std::vector<FestUuid> &idblock,
                         std::string &strblock, std::map<std::string,uint32_t> &cache) :
        refVirkestoff(festUuidList.StoreList(virkestoff.GetRefVirkestoff())),
        id(virkestoff.GetId(), idblock),
        navn(virkestoff.GetNavn(), strblock, cache),
        navnEngelsk(virkestoff.GetNavnEngelsk(), strblock, cache)
{
}

PVirkestoff_0_4_0::PVirkestoff_0_4_0(const PVirkestoff_0_0_0 &pv) :
        refVirkestoff(pv.refVirkestoff.CastToWider<GenericListItems64>()),
        id(pv.id),
        navn(pv.navn),
        navnEngelsk(pv.navnEngelsk)
{
}

bool PVirkestoff_0_4_0::operator==(const PVirkestoff_0_4_0 &other) const {
    return id == other.id &&
           refVirkestoff == other.refVirkestoff &&
           navn == other.navn &&
           navnEngelsk == other.navnEngelsk;
}

PVirkestoff::PVirkestoff(const PVirkestoff_0_0_0 &v) : std::variant<PVirkestoff_0_0_0,PVirkestoff_0_4_0>(v) {}
PVirkestoff::PVirkestoff(const PVirkestoff_0_4_0 &v) : std::variant<PVirkestoff_0_0_0,PVirkestoff_0_4_0>(v) {}
