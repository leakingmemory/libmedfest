//
// Created by sigsegv on 2/2/23.
//

#include "POppfVirkestoffMedStyrke.h"
#include "../Decoded/OppfVirkestoffMedStyrke.h"

POppfVirkestoffMedStyrke::POppfVirkestoffMedStyrke(const OppfVirkestoffMedStyrke &oppfVirkestoffMedStyrke, std::vector<FestUuid> &uuidblock,
                                                   std::string &strblock, std::map<std::string,uint32_t> &cache) :
        POppf(oppfVirkestoffMedStyrke, uuidblock, strblock, cache),
        PVirkestoffMedStyrke(oppfVirkestoffMedStyrke.virkestoffMedStyrke, uuidblock, strblock, cache)
{
}