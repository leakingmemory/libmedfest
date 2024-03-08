//
// Created by sigsegv on 2/2/23.
//

#include <Struct/Packed/POppfVirkestoffMedStyrke.h>
#include <Struct/Decoded/OppfVirkestoffMedStyrke.h>

POppfVirkestoffMedStyrke::POppfVirkestoffMedStyrke(const OppfVirkestoffMedStyrke &oppfVirkestoffMedStyrke, std::vector<FestUuid> &uuidblock,
                                                   std::string &strblock, std::map<std::string,uint32_t> &cache) :
        POppf(oppfVirkestoffMedStyrke, uuidblock, strblock, cache),
        PVirkestoffMedStyrke(oppfVirkestoffMedStyrke.virkestoffMedStyrke, uuidblock, strblock, cache)
{
}

bool POppfVirkestoffMedStyrke::operator==(const POppfVirkestoffMedStyrke &other) const {
    return POppf::operator==(other) &&
           PVirkestoffMedStyrke::operator==(other);
}