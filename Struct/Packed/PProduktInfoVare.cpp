//
// Created by sigsegv on 1/29/23.
//

#include "PProduktInfoVare.h"
#include "../Decoded/ProduktInfoVare.h"

PProduktInfoVare::PProduktInfoVare(const ProduktInfoVare &produktInfoVare, std::string &strblock,
                                   std::map<std::string,uint32_t> &cache) :
        enhetStorrelse(produktInfoVare.GetEnhetStorrelse(), strblock, cache),
        produktNr(produktInfoVare.GetProduktNr(), strblock, cache),
        volum(produktInfoVare.GetVolum(), strblock, cache),
        antPerPakning(produktInfoVare.GetAntPerPakning()),
        tillattMerMakspris(ToRaw(produktInfoVare.GetTillattMerMakspris())) {}
