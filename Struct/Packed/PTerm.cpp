//
// Created by sigsegv on 2/5/23.
//

#include "PTerm.h"
#include "../Decoded/Term.h"

PTerm::PTerm(const Term &term, std::string &strblock, std::map<std::string, uint32_t> &cache) :
    sprak(term.sprak, strblock, cache),
    term(term.term, strblock, cache),
    beskrivelseTerm(term.beskrivelseTerm, strblock, cache)
{
}

bool PTerm::operator==(const PTerm &other) const {
    return sprak == other.sprak &&
            term == other.term &&
            beskrivelseTerm == other.beskrivelseTerm;
}