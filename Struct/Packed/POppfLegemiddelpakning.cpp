//
// Created by sigsegv on 1/18/23.
//

#include <Struct/Packed/POppfLegemiddelpakning.h>
#include <Struct/Decoded/OppfLegemiddelpakning.h>

POppfLegemiddelpakning_0_0_0::POppfLegemiddelpakning_0_0_0(const OppfLegemiddelpakning &oppf,
                                               PakningskomponentList &pakningskomponentList,
                                               PakningsinfoList &pakningsinfoList,
                                               PrisVareList &prisVareList, StringList &stringList, FestUuidList_0_0_0 &festUuidList,
                                               std::vector<FestUuid> &uuidblock, std::string &strblock,
                                               std::map<std::string,uint32_t> &cache) :
        POppf(oppf, uuidblock, strblock, cache),
        PLegemiddelpakning_0_0_0(oppf.GetLegemiddelpakning(), pakningskomponentList, pakningsinfoList, prisVareList, stringList, festUuidList, uuidblock, strblock, cache)
{
}

bool POppfLegemiddelpakning_0_0_0::operator==(const POppfLegemiddelpakning_0_0_0 &other) const {
    return static_cast<const POppf>(*this) == static_cast<const POppf>(other) &&
           static_cast<const PLegemiddelpakning_0_0_0>(*this) == static_cast<const PLegemiddelpakning_0_0_0>(other);
}

POppfLegemiddelpakning_0_4_0::POppfLegemiddelpakning_0_4_0(const OppfLegemiddelpakning &oppf,
                                               PakningskomponentList &pakningskomponentList,
                                               PakningsinfoList &pakningsinfoList,
                                               PrisVareList &prisVareList, StringList &stringList, FestUuidList_0_4_0 &festUuidList,
                                               std::vector<FestUuid> &uuidblock, std::string &strblock,
                                               std::map<std::string,uint32_t> &cache) :
        POppf(oppf, uuidblock, strblock, cache),
        PLegemiddelpakning_0_4_0(oppf.GetLegemiddelpakning(), pakningskomponentList, pakningsinfoList, prisVareList, stringList, festUuidList, uuidblock, strblock, cache)
{
}

POppfLegemiddelpakning_0_4_0::POppfLegemiddelpakning_0_4_0(const POppfLegemiddelpakning_0_0_0 &poppf) :
        POppf(poppf),
        PLegemiddelpakning_0_4_0(poppf) {}

bool POppfLegemiddelpakning_0_4_0::operator==(const POppfLegemiddelpakning_0_4_0 &other) const {
    return static_cast<const POppf>(*this) == static_cast<const POppf>(other) &&
           static_cast<const PLegemiddelpakning_0_4_0>(*this) == static_cast<const PLegemiddelpakning_0_4_0>(other);
}

POppfLegemiddelpakning::POppfLegemiddelpakning(const POppfLegemiddelpakning_0_0_0 &p) : POppf(p),
                                                                                                PLegemiddelpakning(p) {
}

POppfLegemiddelpakning::POppfLegemiddelpakning(const POppfLegemiddelpakning_0_4_0 &p) : POppf(p),
                                                                                                PLegemiddelpakning(p) {
}
