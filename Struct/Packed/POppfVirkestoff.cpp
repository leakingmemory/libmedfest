//
// Created by sigsegv on 2/4/23.
//

#include <Struct/Packed/POppfVirkestoff.h>
#include <Struct/Decoded/OppfVirkestoff.h>

POppfVirkestoff::POppfVirkestoff(const OppfVirkestoff &oppf, FestUuidList &festUuidList, std::vector<FestUuid> &idblock,
                                 std::string &strblock, std::map<std::string, uint32_t> &cache) :
        POppf(oppf, idblock, strblock, cache),
        PVirkestoff(oppf.virkestoff, festUuidList, idblock, strblock, cache)
{
}

bool POppfVirkestoff::operator==(const POppfVirkestoff &other) const {
    return POppf::operator==(other) &&
           PVirkestoff::operator==(other);
}