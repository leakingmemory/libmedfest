//
// Created by sigsegv on 1/24/23.
//

#include <Struct/Packed/POppfLegemiddelVirkestoff.h>
#include <Struct/Decoded/OppfLegemiddelVirkestoff.h>

POppfLegemiddelVirkestoff::POppfLegemiddelVirkestoff(const OppfLegemiddelVirkestoff &oppf, std::string &strblock,
                                                     std::map<std::string,uint32_t> &cache,
                                                     std::vector<FestUuid> uuidlist, StringList &stringList,
                                                     FestUuidList &festUuidList,
                                                     ValueWithCodesetList &valueWithCodesetList,
                                                     RefusjonList &refusjonList) :
        POppf(oppf, uuidlist, strblock, cache),
        PLegemiddelVirkestoff(oppf.GetLegemiddelVirkestoff(), strblock, cache, uuidlist, stringList, festUuidList, valueWithCodesetList,
                              refusjonList) {
}

bool POppfLegemiddelVirkestoff::operator==(const POppfLegemiddelVirkestoff &other) const {
    return static_cast<const POppf>(*this) == static_cast<const POppf>(other) &&
           static_cast<const PLegemiddelVirkestoff>(*this) == static_cast<const PLegemiddelVirkestoff>(other);
}
