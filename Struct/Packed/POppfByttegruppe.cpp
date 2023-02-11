//
// Created by sigsegv on 2/10/23.
//

#include "POppfByttegruppe.h"
#include "../Decoded/OppfByttegruppe.h"

POppfByttegruppe::POppfByttegruppe(const OppfByttegruppe &oppf, std::vector<FestUuid> &idblock, std::string &strblock,
                                   std::map<std::string, uint32_t> &cache) :
        POppf(oppf, idblock, strblock, cache),
        PByttegruppe(oppf.byttegruppe, idblock, strblock, cache)
{
}