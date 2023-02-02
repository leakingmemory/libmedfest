//
// Created by sigsegv on 1/31/23.
//

#include "PLegemiddeldose.h"
#include "FestUuidList.h"
#include "PPakningskomponentInfo.h"
#include "PakningskomponentInfoList.h"
#include "../Decoded/Legemiddeldose.h"

PLegemiddeldose::PLegemiddeldose(const Legemiddeldose &legemiddeldose,
                                 PakningskomponentInfoList &pakningskomponentInfoList, FestUuidList &festUuidList,
                                 std::vector<FestUuid> &festidblock, std::string &strblock,
                                 std::map<std::string,uint32_t> &cache) :
        PLegemiddelCore(legemiddeldose, strblock, cache, festUuidList),
        preparattype(legemiddeldose.GetPreparattype(), strblock, cache),
        mengde(legemiddeldose.GetMengde(), strblock, cache),
        id(legemiddeldose.GetId(), festidblock),
        lmrLopenr(legemiddeldose.GetLmrLopenr(), strblock, cache),
        refLegemiddelMerkevare(festUuidList.StoreList(legemiddeldose.GetRefLegemiddelMerkevare())),
        refPakning(festUuidList.StoreList(legemiddeldose.GetRefPakning())),
        pakningstype(legemiddeldose.GetPakningstype(), strblock, cache),
        pakningskomponent()
{
    std::vector<PPakningskomponentInfo> pakningskomponent{};
    for (const auto &pk : legemiddeldose.GetPakningskomponent()) {
        pakningskomponent.emplace_back(pk, strblock, cache);
    }
    this->pakningskomponent = pakningskomponentInfoList.StoreList(pakningskomponent);
}
