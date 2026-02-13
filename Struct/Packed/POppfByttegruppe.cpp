//
// Created by sigsegv on 2/10/23.
//

#include <Struct/Packed/POppfByttegruppe.h>
#include <Struct/Decoded/OppfByttegruppe.h>

POppfByttegruppe_0_0_0::POppfByttegruppe_0_0_0(const OppfByttegruppe &oppf, std::vector<FestUuid> &idblock, std::string &strblock,
                                   std::map<std::string, uint32_t> &cache) :
        POppf(oppf, idblock, strblock, cache),
        PByttegruppe_0_0_0(oppf.byttegruppe, idblock, strblock, cache)
{
}

POppfByttegruppe_0_0_0::~POppfByttegruppe_0_0_0() = default;

bool POppfByttegruppe_0_0_0::operator==(const POppfByttegruppe_0_0_0 &other) const {
    return POppf::operator==(other) &&
           PByttegruppe_0_0_0::operator==(other);
}

POppfByttegruppe_1_5_0::POppfByttegruppe_1_5_0(const OppfByttegruppe &oppf, std::vector<FestUuid> &idblock, std::string &strblock,
                                   std::map<std::string, uint32_t> &cache) :
        POppf(oppf, idblock, strblock, cache),
        PByttegruppe_1_5_0(oppf.byttegruppe, idblock, strblock, cache)
{
}

POppfByttegruppe_1_5_0::POppfByttegruppe_1_5_0(const POppfByttegruppe_0_0_0 &poppf) :
        POppf(poppf),
        PByttegruppe_1_5_0(static_cast<const PByttegruppe_0_0_0 &>(poppf))
{

}

POppfByttegruppe_1_5_0::~POppfByttegruppe_1_5_0() = default;

bool POppfByttegruppe_1_5_0::operator==(const POppfByttegruppe_1_5_0 &other) const {
    return POppf::operator==(other) &&
           PByttegruppe_1_5_0::operator==(other);
}

POppfByttegruppe::~POppfByttegruppe() = default;

bool POppfByttegruppe::operator==(const POppfByttegruppe &other) const {
    return POppf::operator==(other) &&
        PByttegruppe::operator==(other);
}
