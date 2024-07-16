//
// Created by sigsegv on 2/1/23.
//

#include <Struct/Packed/POppfLegemiddeldose.h>
#include <Struct/Decoded/OppfLegemiddeldose.h>

POppfLegemiddeldose_0_0_0::POppfLegemiddeldose_0_0_0(const OppfLegemiddeldose &oppf,
                                         PakningskomponentInfoList &pakningskomponentInfoList,
                                         FestUuidList_0_0_0 &festUuidList, std::vector<FestUuid> &uuidblock,
                                         std::string &strblock, std::map<std::string,uint32_t> &cache) :
        POppf(oppf, uuidblock, strblock, cache),
        PLegemiddeldose_0_0_0(oppf.legemiddeldose, pakningskomponentInfoList, festUuidList, uuidblock, strblock, cache)
{
}

bool POppfLegemiddeldose_0_0_0::operator==(const POppfLegemiddeldose_0_0_0 &other) const {
    return POppf::operator==(other) &&
           PLegemiddeldose_0_0_0::operator==(other);
}

POppfLegemiddeldose_0_4_0::POppfLegemiddeldose_0_4_0(const OppfLegemiddeldose &oppf,
                                         PakningskomponentInfoList &pakningskomponentInfoList,
                                         FestUuidList_0_4_0 &festUuidList, std::vector<FestUuid> &uuidblock,
                                         std::string &strblock, std::map<std::string,uint32_t> &cache) :
        POppf(oppf, uuidblock, strblock, cache),
        PLegemiddeldose_0_4_0(oppf.legemiddeldose, pakningskomponentInfoList, festUuidList, uuidblock, strblock, cache)
{
}

POppfLegemiddeldose_0_4_0::POppfLegemiddeldose_0_4_0(const POppfLegemiddeldose_0_0_0 &poppf) :
        POppf(poppf),
        PLegemiddeldose_0_4_0(poppf) {

}

bool POppfLegemiddeldose_0_4_0::operator==(const POppfLegemiddeldose_0_4_0 &other) const {
    return POppf::operator==(other) &&
           PLegemiddeldose_0_4_0::operator==(other);
}

POppfLegemiddeldose::POppfLegemiddeldose(const POppfLegemiddeldose_0_0_0 &p) : POppf(p), PLegemiddeldose(p) {}
POppfLegemiddeldose::POppfLegemiddeldose(const POppfLegemiddeldose_0_4_0 &p) : POppf(p), PLegemiddeldose(p) {}
