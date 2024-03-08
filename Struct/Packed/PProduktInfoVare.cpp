//
// Created by sigsegv on 1/29/23.
//

#include <Struct/Packed/PProduktInfoVare.h>
#include <Struct/Decoded/ProduktInfoVare.h>

PProduktInfoVare::PProduktInfoVare(const ProduktInfoVare &produktInfoVare, std::string &strblock,
                                   std::map<std::string,uint32_t> &cache) :
        enhetStorrelse(produktInfoVare.GetEnhetStorrelse(), strblock, cache),
        produktNr(produktInfoVare.GetProduktNr(), strblock, cache),
        volum(produktInfoVare.GetVolum(), strblock, cache),
        antPerPakning(produktInfoVare.GetAntPerPakning()),
        tillattMerMakspris(ToRaw(produktInfoVare.GetTillattMerMakspris())) {}

bool PProduktInfoVare::operator==(const PProduktInfoVare &other) const {
    return enhetStorrelse == other.enhetStorrelse &&
           produktNr == other.produktNr &&
           volum == other.volum &&
           antPerPakning == other.antPerPakning &&
           tillattMerMakspris == other.tillattMerMakspris;
}