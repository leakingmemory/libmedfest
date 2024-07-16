//
// Created by sigsegv on 1/13/23.
//

#include <Struct/Packed/POppfLegemiddelMerkevare.h>
#include <Struct/Decoded/OppfLegemiddelMerkevare.h>

POppfLegemiddelMerkevare_0_0_0::POppfLegemiddelMerkevare_0_0_0(const OppfLegemiddelMerkevare &oppf, std::string &strblock,
                                                   std::map<std::string,uint32_t> &cache,
                                                   std::vector<FestUuid> &festidblock, FestUuidList_0_0_0 &festUuidList,
                                                   ValueWithCodesetList &valueWithCodesetList,
                                                   ReseptgyldighetList &reseptgyldighetList) :
        POppf(oppf, festidblock, strblock, cache),
        PLegemiddelMerkevare_0_0_0(oppf.GetLegemiddelMerkevare(), strblock, cache, festidblock, festUuidList, valueWithCodesetList,
                             reseptgyldighetList) {}

bool POppfLegemiddelMerkevare_0_0_0::operator==(const POppfLegemiddelMerkevare_0_0_0 &poppf) const {
    return static_cast<const POppf>(*this) == static_cast<const POppf>(poppf) &&
           static_cast<const PLegemiddelMerkevare_0_0_0>(*this) == static_cast<const PLegemiddelMerkevare_0_0_0>(poppf);
}

POppfLegemiddelMerkevare_0_4_0::POppfLegemiddelMerkevare_0_4_0(const OppfLegemiddelMerkevare &oppf, std::string &strblock,
                                                   std::map<std::string,uint32_t> &cache,
                                                   std::vector<FestUuid> &festidblock, FestUuidList_0_4_0 &festUuidList,
                                                   ValueWithCodesetList &valueWithCodesetList,
                                                   ReseptgyldighetList &reseptgyldighetList) :
        POppf(oppf, festidblock, strblock, cache),
        PLegemiddelMerkevare_0_4_0(oppf.GetLegemiddelMerkevare(), strblock, cache, festidblock, festUuidList, valueWithCodesetList,
                             reseptgyldighetList) {}

POppfLegemiddelMerkevare_0_4_0::POppfLegemiddelMerkevare_0_4_0(const POppfLegemiddelMerkevare_0_0_0 &poppf) :
        POppf(poppf),
        PLegemiddelMerkevare_0_4_0(poppf) {}

bool POppfLegemiddelMerkevare_0_4_0::operator==(const POppfLegemiddelMerkevare_0_4_0 &poppf) const {
    return static_cast<const POppf>(*this) == static_cast<const POppf>(poppf) &&
           static_cast<const PLegemiddelMerkevare_0_4_0>(*this) == static_cast<const PLegemiddelMerkevare_0_4_0>(poppf);
}

POppfLegemiddelMerkevare::POppfLegemiddelMerkevare(const POppfLegemiddelMerkevare_0_0_0 &poppf) : POppf(static_cast<const POppf &>(poppf)),
                                                                                                  PLegemiddelMerkevare(poppf) {}
POppfLegemiddelMerkevare::POppfLegemiddelMerkevare(const POppfLegemiddelMerkevare_0_4_0 &poppf) : POppf(static_cast<const POppf &>(poppf)),
                                                                                                  PLegemiddelMerkevare(poppf) {}
