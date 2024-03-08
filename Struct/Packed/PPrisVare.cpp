//
// Created by sigsegv on 1/19/23.
//

#include <Struct/Packed/PPrisVare.h>
#include <Struct/Decoded/PrisVare.h>

PPrisVare::PPrisVare(const PrisVare &prisVare, std::string &strblock, std::map<std::string,uint32_t> &cache) :
        type(prisVare.GetType(), strblock, cache),
        gyldigFraDato(prisVare.GetGyldigFraDato(), strblock, cache),
        gyldigTilDato(prisVare.GetGyldigTilDato(), strblock, cache),
        pris(prisVare.GetPris(), strblock, cache) {
}

bool PPrisVare::operator==(const PPrisVare &other) const {
    return type == other.type && gyldigFraDato == other.gyldigFraDato && gyldigTilDato == other.gyldigTilDato &&
            pris == other.pris;
}
