//
// Created by sigsegv on 1/11/23.
//

#include <Struct/Packed/PLegemiddelCore.h>
#include <Struct/Packed/FestUuidList.h>
#include <Struct/Decoded/LegemiddelCore.h>

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

bool PLegemiddelCore::operator==(const PLegemiddelCore &other) const {
    return atc == other.atc &&
           navnFormStyrke == other.navnFormStyrke &&
           reseptgruppe == other.reseptgruppe &&
           legemiddelformKort == other.legemiddelformKort &&
           refVilkar == other.refVilkar &&
           typeSoknadSlv == other.typeSoknadSlv &&
           svartTrekant == other.svartTrekant &&
           opioidsoknad == other.opioidsoknad;
}
