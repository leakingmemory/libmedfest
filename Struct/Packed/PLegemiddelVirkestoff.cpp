//
// Created by sigsegv on 1/24/23.
//

#include "PLegemiddelVirkestoff.h"
#include "../Decoded/LegemiddelVirkestoff.h"
#include "RefusjonList.h"
#include "FestUuidList.h"

PLegemiddelVirkestoff::PLegemiddelVirkestoff(const LegemiddelVirkestoff &legemiddelVirkestoff, std::string &strblock,
                                             std::map<std::string,uint32_t> &cache, std::vector<FestUuid> uuidlist,
                                             StringList &stringList, FestUuidList &festUuidList,
                                             ValueWithCodesetList &valueWithCodesetList, RefusjonList &refusjonList) :
        PLegemiddel(legemiddelVirkestoff, strblock, cache, festUuidList, valueWithCodesetList),
        forskrivningsenhetResept(legemiddelVirkestoff.GetForskrivningsenhetResept(), strblock, cache),
        id(legemiddelVirkestoff.GetId(), uuidlist),
        refusjon(),
        refLegemiddelMerkevare(festUuidList.StoreList(legemiddelVirkestoff.GetRefLegemiddelMerkevare())),
        refPakning(festUuidList.StoreList(legemiddelVirkestoff.GetRefPakning())) {
    std::vector<PRefusjon> refusjon{};
    for (const auto &r : legemiddelVirkestoff.GetRefusjon()) {
        refusjon.emplace_back(r, stringList, strblock, cache);
    }
    this->refusjon = refusjonList.StoreList(refusjon);
}
