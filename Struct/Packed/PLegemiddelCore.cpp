//
// Created by sigsegv on 1/11/23.
//

#include "PLegemiddelCore.h"
#include "FestUuidList.h"
#include "../Decoded/LegemiddelCore.h"

PLegemiddelCore::PLegemiddelCore(const LegemiddelCore &legemiddelCore, std::string &strblock,
                                 std::map<std::string,uint32_t> &cache, FestUuidList &festUuidList) :
        atc(legemiddelCore.GetAtc(), strblock, cache),
        navnFormStyrke(legemiddelCore.GetNavnFormStyrke(), strblock, cache),
        reseptgruppe(legemiddelCore.GetReseptgruppe(), strblock, cache),
        legemiddelformKort(legemiddelCore.GetLegemiddelformKort(), strblock, cache),
        refVilkar(festUuidList.StoreList(legemiddelCore.GetRefVilkar())),
        typeSoknadSlv(legemiddelCore.GetTypeSoknadSlv(), strblock, cache),
        svartTrekant(legemiddelCore.GetSvartTrekant(), strblock, cache),
        opioidsoknad(ToRaw(legemiddelCore.GetOpioidsoknad())) {
}