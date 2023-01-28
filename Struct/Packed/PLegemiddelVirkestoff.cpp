//
// Created by sigsegv on 1/24/23.
//

#include "PLegemiddelVirkestoff.h"
#include "../Decoded/LegemiddelVirkestoff.h"
#include "RefusjonList.h"
#include "FestUuidList.h"

PLegemiddelVirkestoff::PLegemiddelVirkestoff(const LegemiddelVirkestoff &legemiddelVirkestoff, std::string &strblock,
                                             std::vector<FestUuid> uuidlist, FestUuidList &festUuidList,
                                             ValueWithCodesetList &valueWithCodesetList, RefusjonList &refusjonList) :
        PLegemiddel(legemiddelVirkestoff, strblock, festUuidList, valueWithCodesetList),
        forskrivningsenhetResept(legemiddelVirkestoff.GetForskrivningsenhetResept(), strblock),
        id(legemiddelVirkestoff.GetId(), uuidlist),
        refusjon(),
        refLegemiddelMerkevare(festUuidList.StoreList(legemiddelVirkestoff.GetRefLegemiddelMerkevare())),
        refPakning(festUuidList.StoreList(legemiddelVirkestoff.GetRefPakning())) {
    std::vector<PRefusjon> refusjon{};
    for (const auto &r : legemiddelVirkestoff.GetRefusjon()) {
        refusjon.emplace_back(r, festUuidList, strblock);
    }
    this->refusjon = refusjonList.StoreList(refusjon);
}
