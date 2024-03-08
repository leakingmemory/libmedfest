//
// Created by sigsegv on 2/10/23.
//

#include <Struct/Packed/POppfByttegruppe.h>
#include <Struct/Decoded/OppfByttegruppe.h>

POppfByttegruppe::POppfByttegruppe(const OppfByttegruppe &oppf, std::vector<FestUuid> &idblock, std::string &strblock,
                                   std::map<std::string, uint32_t> &cache) :
        POppf(oppf, idblock, strblock, cache),
        PByttegruppe(oppf.byttegruppe, idblock, strblock, cache)
{
}

bool POppfByttegruppe::operator==(const POppfByttegruppe &other) const {
    return POppf::operator==(other) &&
           PByttegruppe::operator==(other);
}