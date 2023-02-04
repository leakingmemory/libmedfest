//
// Created by sigsegv on 2/4/23.
//

#include "PVirkestoff.h"
#include "FestUuidList.h"
#include "../Decoded/Virkestoff.h"

PVirkestoff::PVirkestoff(const Virkestoff &virkestoff, FestUuidList &festUuidList, std::vector<FestUuid> &idblock,
                         std::string &strblock, std::map<std::string,uint32_t> &cache) :
        refVirkestoff(festUuidList.StoreList(virkestoff.GetRefVirkestoff())),
        id(virkestoff.GetId(), idblock),
        navn(virkestoff.GetNavn(), strblock, cache),
        navnEngelsk(virkestoff.GetNavnEngelsk(), strblock, cache)
{
}