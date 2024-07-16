//
// Created by sigsegv on 1/24/23.
//

#include <Struct/Packed/POppfLegemiddelVirkestoff.h>
#include <Struct/Decoded/OppfLegemiddelVirkestoff.h>

POppfLegemiddelVirkestoff_0_0_0::POppfLegemiddelVirkestoff_0_0_0(const OppfLegemiddelVirkestoff &oppf, std::string &strblock,
                                                     std::map<std::string,uint32_t> &cache,
                                                     std::vector<FestUuid> &uuidlist, StringList &stringList,
                                                     FestUuidList_0_0_0 &festUuidList,
                                                     ValueWithCodesetList &valueWithCodesetList,
                                                     RefusjonList &refusjonList) :
        POppf(oppf, uuidlist, strblock, cache),
        PLegemiddelVirkestoff_0_0_0(oppf.GetLegemiddelVirkestoff(), strblock, cache, uuidlist, stringList, festUuidList, valueWithCodesetList,
                              refusjonList) {
}

bool POppfLegemiddelVirkestoff_0_0_0::operator==(const POppfLegemiddelVirkestoff_0_0_0 &other) const {
    return static_cast<const POppf>(*this) == static_cast<const POppf>(other) &&
           static_cast<const PLegemiddelVirkestoff_0_0_0>(*this) == static_cast<const PLegemiddelVirkestoff_0_0_0>(other);
}

POppfLegemiddelVirkestoff_0_4_0::POppfLegemiddelVirkestoff_0_4_0(const OppfLegemiddelVirkestoff &oppf, std::string &strblock,
                                                                 std::map<std::string,uint32_t> &cache,
                                                                 std::vector<FestUuid> &uuidlist, StringList &stringList,
                                                                 FestUuidList_0_4_0 &festUuidList,
                                                                 ValueWithCodesetList &valueWithCodesetList,
                                                                 RefusjonList &refusjonList) :
        POppf(oppf, uuidlist, strblock, cache),
        PLegemiddelVirkestoff_0_4_0(oppf.GetLegemiddelVirkestoff(), strblock, cache, uuidlist, stringList, festUuidList, valueWithCodesetList,
                                    refusjonList) {
}

POppfLegemiddelVirkestoff_0_4_0::POppfLegemiddelVirkestoff_0_4_0(const POppfLegemiddelVirkestoff_0_0_0 &poppf) :
        POppf(poppf),
        PLegemiddelVirkestoff_0_4_0(poppf) {
}

bool POppfLegemiddelVirkestoff_0_4_0::operator==(const POppfLegemiddelVirkestoff_0_4_0 &other) const {
    return static_cast<const POppf>(*this) == static_cast<const POppf>(other) &&
           static_cast<const PLegemiddelVirkestoff_0_4_0>(*this) == static_cast<const PLegemiddelVirkestoff_0_4_0>(other);
}

POppfLegemiddelVirkestoff::POppfLegemiddelVirkestoff(const POppfLegemiddelVirkestoff_0_0_0 &p) : POppf(static_cast<const POppf &>(p)),
                                                                                                 PLegemiddelVirkestoff(p) {}
POppfLegemiddelVirkestoff::POppfLegemiddelVirkestoff(const POppfLegemiddelVirkestoff_0_4_0 &p) : POppf(static_cast<const POppf &>(p)),
                                                                                                 PLegemiddelVirkestoff(p) {}
