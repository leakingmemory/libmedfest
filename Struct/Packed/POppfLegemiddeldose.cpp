//
// Created by sigsegv on 2/1/23.
//

#include "POppfLegemiddeldose.h"
#include "../Decoded/OppfLegemiddeldose.h"

POppfLegemiddeldose::POppfLegemiddeldose(const OppfLegemiddeldose &oppf,
                                         PakningskomponentInfoList &pakningskomponentInfoList,
                                         FestUuidList &festUuidList, std::vector<FestUuid> &uuidblock,
                                         std::string &strblock, std::map<std::string,uint32_t> &cache) :
        POppf(oppf, uuidblock, strblock, cache),
        PLegemiddeldose(oppf.legemiddeldose, pakningskomponentInfoList, festUuidList, uuidblock, strblock, cache)
{
}

bool POppfLegemiddeldose::operator==(const POppfLegemiddeldose &other) const {
    return POppf::operator==(other) &&
           PLegemiddeldose::operator==(other);
}