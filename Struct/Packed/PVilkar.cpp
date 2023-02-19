//
// Created by sigsegv on 2/8/23.
//

#include "PVilkar.h"
#include "../Decoded/Vilkar.h"

PVilkar::PVilkar(const Vilkar &vilkar, std::string &strblock, std::map<std::string,uint32_t> &cache) :
        PStrukturertVilkar(vilkar.strukturertVilkar, strblock, cache),
        gjelderFor(vilkar.gjelderFor, strblock, cache),
        gruppe(vilkar.gruppe, strblock, cache),
        id(vilkar.id, strblock, cache),
        vilkarNr(vilkar.vilkarNr, strblock, cache),
        tekst(vilkar.tekst, strblock, cache),
        gyldigFraDato(vilkar.gyldigFraDato, strblock, cache)
{}

bool PVilkar::operator==(const PVilkar &other) const {
    return id == other.id &&
           PStrukturertVilkar::operator==(other) &&
           gjelderFor == other.gjelderFor &&
           gruppe == other.gruppe &&
           vilkarNr == other.vilkarNr &&
           tekst == other.tekst &&
           gyldigFraDato == other.gyldigFraDato;
}