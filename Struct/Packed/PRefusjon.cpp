//
// Created by sigsegv on 1/19/23.
//

#include "PRefusjon.h"
#include "../Decoded/Refusjon.h"
#include "FestUuidList.h"

PRefusjon::PRefusjon(const Refusjon &refusjon, FestUuidList &uuidlist, std::string &strblock) :
        refRefusjonsgruppe(uuidlist.StoreList(refusjon.GetRefRefusjonsgruppe())),
        gyldigFraDato(refusjon.GetGyldigFraDato(), strblock),
        forskrivesTilDato(refusjon.GetForskrivesTilDato(), strblock),
        utleveresTilDato(refusjon.GetUtleveresTilDato(), strblock) {
}