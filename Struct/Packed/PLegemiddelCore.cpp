//
// Created by sigsegv on 1/11/23.
//

#include "PLegemiddelCore.h"
#include "FestUuidList.h"
#include "../Decoded/LegemiddelCore.h"

PLegemiddelCore::PLegemiddelCore(const LegemiddelCore &legemiddelCore, std::string &strblock,
                                 FestUuidList &festUuidList) :
        atc(legemiddelCore.GetAtc(), strblock),
        navnFormStyrke(legemiddelCore.GetNavnFormStyrke(), strblock),
        reseptgruppe(legemiddelCore.GetReseptgruppe(), strblock),
        legemiddelformKort(legemiddelCore.GetLegemiddelformKort(), strblock),
        refVilkar(festUuidList.StoreList(legemiddelCore.GetRefVilkar())),
        typeSoknadSlv(legemiddelCore.GetTypeSoknadSlv(), strblock),
        svartTrekant(legemiddelCore.GetSvartTrekant(), strblock),
        opioidsoknad(ToRaw(legemiddelCore.GetOpioidsoknad())) {
}