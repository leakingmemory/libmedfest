//
// Created by sigsegv on 1/18/23.
//

#include "POppfLegemiddelpakning.h"
#include "../Decoded/OppfLegemiddelpakning.h"

POppfLegemiddelpakning::POppfLegemiddelpakning(const OppfLegemiddelpakning &oppf,
                                               PakningskomponentList &pakningskomponentList,
                                               PakningsinfoList &pakningsinfoList,
                                               PrisVareList &prisVareList, StringList &stringList, FestUuidList &festUuidList,
                                               std::vector<FestUuid> &uuidblock, std::string &strblock,
                                               std::map<std::string,uint32_t> &cache) :
        POppf(oppf, uuidblock, strblock, cache),
        PLegemiddelpakning(oppf.GetLegemiddelpakning(), pakningskomponentList, pakningsinfoList, prisVareList, stringList, festUuidList, uuidblock, strblock, cache)
{
}

bool POppfLegemiddelpakning::operator==(const POppfLegemiddelpakning &other) const {
    return static_cast<const POppf>(*this) == static_cast<const POppf>(other) &&
           static_cast<const PLegemiddelpakning>(*this) == static_cast<const PLegemiddelpakning>(other);
}
