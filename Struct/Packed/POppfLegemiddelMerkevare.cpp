//
// Created by sigsegv on 1/13/23.
//

#include "POppfLegemiddelMerkevare.h"
#include "../Decoded/OppfLegemiddelMerkevare.h"

POppfLegemiddelMerkevare::POppfLegemiddelMerkevare(const OppfLegemiddelMerkevare &oppf, std::string &strblock,
                                                   std::vector<FestUuid> &festidblock, FestUuidList &festUuidList,
                                                   ValueWithCodesetList &valueWithCodesetList,
                                                   ReseptgyldighetList &reseptgyldighetList) :
        POppf(oppf, festidblock, strblock),
        PLegemiddelMerkevare(oppf.GetLegemiddelMerkevare(), strblock, festidblock, festUuidList, valueWithCodesetList,
                             reseptgyldighetList) {}
