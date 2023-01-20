//
// Created by sigsegv on 1/19/23.
//

#include "PPrisVare.h"
#include "../Decoded/PrisVare.h"

PPrisVare::PPrisVare(const PrisVare &prisVare, std::string &strblock) :
        type(prisVare.GetType(), strblock),
        gyldigFraDato(prisVare.GetGyldigFraDato(), strblock),
        gyldigTilDato(prisVare.GetGyldigTilDato(), strblock),
        pris(prisVare.GetPris(), strblock) {
}

bool PPrisVare::operator==(const PPrisVare &other) const {
    return type == other.type && gyldigFraDato == other.gyldigFraDato && gyldigTilDato == other.gyldigTilDato &&
            pris == other.pris;
}
