//
// Created by sigsegv on 2/11/23.
//

#include "PSubstans.h"
#include "../Decoded/Substans.h"

PSubstans::PSubstans(const Substans &substans, std::vector<FestUuid> &idblock, std::string &strblock,
                     std::map<std::string, uint32_t> &cache) :
        atc(substans.atc, strblock, cache),
        refVirkestoff(substans.refVirkestoff, idblock),
        substans(substans.substans, strblock, cache)
{
}

bool PSubstans::operator==(const PSubstans &other) const {
    return atc == other.atc && refVirkestoff == other.refVirkestoff && substans == other.substans;
}
