//
// Created by sigsegv on 12/28/22.
//

#include <Struct/Decoded/Element.h>

std::string Element::GetId() const {
    return id;
}

std::string Element::GetKode() const {
    return kode;
}

Term Element::GetTerm() const {
    if (!term.empty()) {
        return term[term.size() - 1];
    } else {
        return {};
    }
}

std::vector<Term> Element::GetTermList() const {
    return term;
}