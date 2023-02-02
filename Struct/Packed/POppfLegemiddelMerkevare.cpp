//
// Created by sigsegv on 1/13/23.
//

#include "POppfLegemiddelMerkevare.h"
#include "../Decoded/OppfLegemiddelMerkevare.h"

POppfLegemiddelMerkevare::POppfLegemiddelMerkevare(const OppfLegemiddelMerkevare &oppf, std::string &strblock,
                                                   std::map<std::string,uint32_t> &cache,
                                                   std::vector<FestUuid> &festidblock, FestUuidList &festUuidList,
                                                   ValueWithCodesetList &valueWithCodesetList,
                                                   ReseptgyldighetList &reseptgyldighetList) :
        POppf(oppf, festidblock, strblock, cache),
        PLegemiddelMerkevare(oppf.GetLegemiddelMerkevare(), strblock, cache, festidblock, festUuidList, valueWithCodesetList,
                             reseptgyldighetList) {}
