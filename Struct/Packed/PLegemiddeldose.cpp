//
// Created by sigsegv on 1/31/23.
//

#include "PLegemiddeldose.h"
#include "FestUuidList.h"
#include "PPakningskomponentInfo.h"
#include "PakningskomponentInfoList.h"
#include "../Decoded/Legemiddeldose.h"

PLegemiddeldose::PLegemiddeldose(const Legemiddeldose &legemiddeldose, PakningskomponentInfoList &pakningskomponentInfoList, FestUuidList &festUuidList, std::vector<FestUuid> &festidblock, std::string &strblock) :
        PLegemiddelCore(legemiddeldose, strblock, festUuidList),
        preparattype(legemiddeldose.GetPreparattype(), strblock),
        mengde(legemiddeldose.GetMengde(), strblock),
        id(legemiddeldose.GetId(), festidblock),
        lmrLopenr(legemiddeldose.GetLmrLopenr(), strblock),
        refLegemiddelMerkevare(festUuidList.StoreList(legemiddeldose.GetRefLegemiddelMerkevare())),
        refPakning(festUuidList.StoreList(legemiddeldose.GetRefPakning())),
        pakningstype(legemiddeldose.GetPakningstype(), strblock),
        pakningskomponent()
{
    std::vector<PPakningskomponentInfo> pakningskomponent{};
    for (const auto &pk : legemiddeldose.GetPakningskomponent()) {
        pakningskomponent.emplace_back(pk, strblock);
    }
    this->pakningskomponent = pakningskomponentInfoList.StoreList(pakningskomponent);
}
