//
// Created by sigsegv on 1/19/23.
//

#include "PRefusjon.h"
#include "../Decoded/Refusjon.h"

PRefusjon::PRefusjon(const Refusjon &refusjon, std::vector<FestUuid> &uuidblock, std::string &strblock) :
        refRefusjonsgruppe(refusjon.GetRefRefusjonsgruppe(), uuidblock),
        gyldigFraDato(refusjon.GetGyldigFraDato(), strblock),
        forskrivesTilDato(refusjon.GetForskrivesTilDato(), strblock),
        utleveresTilDato(refusjon.GetUtleveresTilDato(), strblock) {}