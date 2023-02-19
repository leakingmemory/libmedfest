//
// Created by sigsegv on 2/8/23.
//

#include "PStrukturertVilkar.h"
#include "../Decoded/StrukturertVilkar.h"

PStrukturertVilkar::PStrukturertVilkar(const StrukturertVilkar &strukturertVilkar, std::string &strblock,
                                       std::map<std::string, uint32_t> &cache) :
        type(strukturertVilkar.GetType(), strblock, cache),
        verdiKodet(strukturertVilkar.GetVerdiKodet(), strblock, cache),
        verdiTekst(strukturertVilkar.GetVerdiTekst(), strblock, cache)
{}

bool PStrukturertVilkar::operator==(const PStrukturertVilkar &other) const {
    return type == other.type &&
           verdiKodet == other.verdiKodet &&
           verdiTekst == other.verdiTekst;
}