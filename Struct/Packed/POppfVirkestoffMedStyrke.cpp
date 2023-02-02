//
// Created by sigsegv on 2/2/23.
//

#include "POppfVirkestoffMedStyrke.h"
#include "../Decoded/OppfVirkestoffMedStyrke.h"

POppfVirkestoffMedStyrke::POppfVirkestoffMedStyrke(const OppfVirkestoffMedStyrke &oppfVirkestoffMedStyrke, std::vector<FestUuid> &uuidblock,
                                                   std::string &strblock) :
        POppf(oppfVirkestoffMedStyrke, uuidblock, strblock),
        PVirkestoffMedStyrke(oppfVirkestoffMedStyrke.virkestoffMedStyrke, uuidblock, strblock)
{
}