//
// Created by sigsegv on 1/31/23.
//

#include <Struct/Packed/PLegemiddeldose.h>
#include <Struct/Packed/FestUuidList.h>
#include <Struct/Packed/PPakningskomponentInfo.h>
#include <Struct/Packed/PakningskomponentInfoList.h>
#include <Struct/Decoded/Legemiddeldose.h>

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

bool PLegemiddeldose::operator==(const PLegemiddeldose &other) const {
    return id == other.id &&
           PLegemiddelCore::operator==(other) &&
           preparattype == other.preparattype &&
           mengde == other.mengde &&
           lmrLopenr == other.lmrLopenr &&
           refLegemiddelMerkevare == other.refLegemiddelMerkevare &&
           refPakning == other.refPakning &&
           pakningstype == other.pakningstype &&
           pakningskomponent == other.pakningskomponent;
}
