//
// Created by sigsegv on 1/24/23.
//

#include "POppfLegemiddelVirkestoff.h"
#include "../Decoded/OppfLegemiddelVirkestoff.h"

POppfLegemiddelVirkestoff::POppfLegemiddelVirkestoff(const OppfLegemiddelVirkestoff &oppf, std::string &strblock,
                                                     std::vector<FestUuid> uuidlist, StringList &stringList,
                                                     FestUuidList &festUuidList, ValueWithCodesetList &valueWithCodesetList,
                                                     RefusjonList &refusjonList) :
        POppf(oppf, uuidlist, strblock),
        PLegemiddelVirkestoff(oppf.GetLegemiddelVirkestoff(), strblock, uuidlist, stringList, festUuidList, valueWithCodesetList,
                              refusjonList) {
}
