//
// Created by sigsegv on 2/4/23.
//

#include <Struct/Packed/POppfVirkestoff.h>
#include <Struct/Decoded/OppfVirkestoff.h>

POppfVirkestoff_0_0_0::POppfVirkestoff_0_0_0(const OppfVirkestoff &oppf, FestUuidList_0_0_0 &festUuidList, std::vector<FestUuid> &idblock,
                                 std::string &strblock, std::map<std::string, uint32_t> &cache) :
        POppf(oppf, idblock, strblock, cache),
        PVirkestoff_0_0_0(oppf.virkestoff, festUuidList, idblock, strblock, cache)
{
}

bool POppfVirkestoff_0_0_0::operator==(const POppfVirkestoff_0_0_0 &other) const {
    return POppf::operator==(other) &&
           PVirkestoff_0_0_0::operator==(other);
}

POppfVirkestoff_0_4_0::POppfVirkestoff_0_4_0(const OppfVirkestoff &oppf, FestUuidList_0_4_0 &festUuidList, std::vector<FestUuid> &idblock,
                                 std::string &strblock, std::map<std::string, uint32_t> &cache) :
        POppf(oppf, idblock, strblock, cache),
        PVirkestoff_0_4_0(oppf.virkestoff, festUuidList, idblock, strblock, cache)
{
}

POppfVirkestoff_0_4_0::POppfVirkestoff_0_4_0(const POppfVirkestoff_0_0_0 &poppf) :
        POppf(static_cast<const POppf &>(poppf)),
        PVirkestoff_0_4_0(static_cast<const PVirkestoff_0_0_0 &>(poppf))
{
}

bool POppfVirkestoff_0_4_0::operator==(const POppfVirkestoff_0_4_0 &other) const {
    return POppf::operator==(other) &&
           PVirkestoff_0_4_0::operator==(other);
}

POppfVirkestoff::POppfVirkestoff(const POppfVirkestoff_0_0_0 &poppf) : POppf(static_cast<const POppf &>(poppf)), PVirkestoff(poppf) {}
POppfVirkestoff::POppfVirkestoff(const POppfVirkestoff_0_4_0 &poppf) : POppf(static_cast<const POppf &>(poppf)), PVirkestoff(poppf) {}
