//
// Created by sigsegv on 2/8/23.
//

#include "POppfVilkar.h"
#include "../Decoded/OppfVilkar.h"

POppfVilkar::POppfVilkar(const OppfVilkar &oppf, std::vector<FestUuid> &idblock, std::string &strblock,
                         std::map<std::string, uint32_t> &cache) :
        POppf(oppf, idblock, strblock, cache),
        PVilkar(oppf.vilkar, strblock, cache)
{
}

bool POppfVilkar::operator==(const POppfVilkar &other) const {
    return POppf::operator==(other) &&
           PVilkar::operator==(other);
}
