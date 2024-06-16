//
// Created by sigsegv on 12/28/22.
//

#ifndef LEGEMFEST_ELEMENT_H
#define LEGEMFEST_ELEMENT_H

#include "Term.h"
#include <string>
#include <vector>

class Element {
private:
    std::string id;
    std::string kode;
    std::vector<Term> term;
public:
    Element() : id(), kode(), term() {}
    Element(const std::string &id, const std::string &kode, const std::vector<Term> &term) : id(id), kode(kode), term(term) {}
    [[nodiscard]] std::string GetId() const;
    [[nodiscard]] std::string GetKode() const;
    [[deprecated]] [[nodiscard]] Term GetTerm() const;
    [[nodiscard]] std::vector<Term> GetTermList() const;
};


#endif //LEGEMFEST_ELEMENT_H
