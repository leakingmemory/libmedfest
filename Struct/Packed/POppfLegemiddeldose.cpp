//
// Created by sigsegv on 2/1/23.
//

#include "POppfLegemiddeldose.h"
#include "../Decoded/OppfLegemiddeldose.h"

POppfLegemiddeldose::POppfLegemiddeldose(const OppfLegemiddeldose &oppf,
                                         PakningskomponentInfoList &pakningskomponentInfoList,
                                         FestUuidList &festUuidList, std::vector<FestUuid> &uuidblock,
                                         std::string &strblock) :
        POppf(oppf, uuidblock, strblock),
        PLegemiddeldose(oppf.legemiddeldose, pakningskomponentInfoList, festUuidList, uuidblock, strblock)
{
}