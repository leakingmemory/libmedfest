//
// Created by sigsegv on 1/31/23.
//

#include <Struct/Packed/PLegemiddeldose.h>
#include <Struct/Packed/FestUuidList.h>
#include <Struct/Packed/PPakningskomponentInfo.h>
#include <Struct/Packed/PakningskomponentInfoList.h>
#include <Struct/Decoded/Legemiddeldose.h>

PLegemiddeldose_0_0_0::PLegemiddeldose_0_0_0(const Legemiddeldose &legemiddeldose,
                                 PakningskomponentInfoList &pakningskomponentInfoList, FestUuidList_0_0_0 &festUuidList,
                                 std::vector<FestUuid> &festidblock, std::string &strblock,
                                 std::map<std::string,uint32_t> &cache) :
        PLegemiddelCore_0_0_0(legemiddeldose, strblock, cache, festUuidList),
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

bool PLegemiddeldose_0_0_0::operator==(const PLegemiddeldose_0_0_0 &other) const {
    return id == other.id &&
           PLegemiddelCore_0_0_0::operator==(other) &&
           preparattype == other.preparattype &&
           mengde == other.mengde &&
           lmrLopenr == other.lmrLopenr &&
           refLegemiddelMerkevare == other.refLegemiddelMerkevare &&
           refPakning == other.refPakning &&
           pakningstype == other.pakningstype &&
           pakningskomponent == other.pakningskomponent;
}

PLegemiddeldose_0_4_0::PLegemiddeldose_0_4_0(const Legemiddeldose &legemiddeldose,
                                 PakningskomponentInfoList &pakningskomponentInfoList, FestUuidList_0_4_0 &festUuidList,
                                 std::vector<FestUuid> &festidblock, std::string &strblock,
                                 std::map<std::string,uint32_t> &cache) :
        PLegemiddelCore_0_4_0(legemiddeldose, strblock, cache, festUuidList),
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

PLegemiddeldose_0_4_0::PLegemiddeldose_0_4_0(const PLegemiddeldose_0_0_0 &p) :
        PLegemiddelCore_0_4_0(p),
        preparattype(p.preparattype),
        mengde(p.mengde),
        id(p.id),
        lmrLopenr(p.lmrLopenr),
        refLegemiddelMerkevare(p.refLegemiddelMerkevare.CastToWider<GenericListItems64>()),
        refPakning(p.refPakning.CastToWider<GenericListItems64>()),
        pakningstype(p.pakningstype),
        pakningskomponent(p.pakningskomponent) {
}

bool PLegemiddeldose_0_4_0::operator==(const PLegemiddeldose_0_4_0 &other) const {
    return id == other.id &&
           PLegemiddelCore_0_4_0::operator==(other) &&
           preparattype == other.preparattype &&
           mengde == other.mengde &&
           lmrLopenr == other.lmrLopenr &&
           refLegemiddelMerkevare == other.refLegemiddelMerkevare &&
           refPakning == other.refPakning &&
           pakningstype == other.pakningstype &&
           pakningskomponent == other.pakningskomponent;
}

PLegemiddeldose::PLegemiddeldose(const PLegemiddeldose_0_0_0 &p) : PLegemiddelCore(p), std::variant<PLegemiddeldose_0_0_0, PLegemiddeldose_0_4_0>(p) {}
PLegemiddeldose::PLegemiddeldose(const PLegemiddeldose_0_4_0 &p) : PLegemiddelCore(p), std::variant<PLegemiddeldose_0_0_0, PLegemiddeldose_0_4_0>(p) {}
