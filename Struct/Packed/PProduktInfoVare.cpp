//
// Created by sigsegv on 1/29/23.
//

#include "PProduktInfoVare.h"
#include "../Decoded/ProduktInfoVare.h"

PProduktInfoVare::PProduktInfoVare(const ProduktInfoVare &produktInfoVare, std::string &strblock) :
        enhetStorrelse(produktInfoVare.GetEnhetStorrelse(), strblock),
        produktNr(produktInfoVare.GetProduktNr(), strblock),
        volum(produktInfoVare.GetVolum(), strblock),
        antPerPakning(produktInfoVare.GetAntPerPakning()),
        tillattMerMakspris(ToRaw(produktInfoVare.GetTillattMerMakspris())) {}
