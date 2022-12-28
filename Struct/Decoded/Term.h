//
// Created by sigsegv on 12/28/22.
//

#ifndef LEGEMFEST_TERM_H
#define LEGEMFEST_TERM_H

#include "Sprak.h"

class Term {
private:
    std::string term;
    std::string beskrivelseTerm;
    Sprak sprak;
public:
    Term() : term(), beskrivelseTerm(), sprak() {}
    Term(const std::string &term, const std::string &beskrivelseTerm, const Sprak &sprak) :
            term(term), beskrivelseTerm(beskrivelseTerm), sprak(sprak) {}
    [[nodiscard]] std::string GetTerm() const;
    [[nodiscard]] std::string GetBeskrivelseTerm() const;
    [[nodiscard]] Sprak GetSprak() const;
};


#endif //LEGEMFEST_TERM_H
