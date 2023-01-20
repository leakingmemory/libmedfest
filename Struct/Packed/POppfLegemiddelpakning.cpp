//
// Created by sigsegv on 1/18/23.
//

#include "POppfLegemiddelpakning.h"
#include "../Decoded/OppfLegemiddelpakning.h"

POppfLegemiddelpakning::POppfLegemiddelpakning(const OppfLegemiddelpakning &oppf,
                                               PakningskomponentList &pakningskomponentList,
                                               PakningsinfoList &pakningsinfoList,
                                               PrisVareList &prisVareList, FestUuidList &festUuidList,
                                               std::vector<FestUuid> &uuidblock, std::string &strblock) :
        POppf(oppf, uuidblock, strblock),
        PLegemiddelpakning(oppf.GetLegemiddelpakning(), pakningskomponentList, pakningsinfoList, prisVareList, festUuidList, uuidblock, strblock)
{
}
