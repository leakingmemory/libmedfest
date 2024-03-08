//
// Created by sigsegv on 12/28/22.
//

#ifndef LEGEMFEST_ELEMENT_H
#define LEGEMFEST_ELEMENT_H

#include "Term.h"
#include <string>

class Element {
private:
    std::string id;
    std::string kode;
    Term term;
public:
    Element() : id(), kode(), term() {}
    Element(const std::string &id, const std::string &kode, const Term &term) : id(id), kode(kode), term(term) {}
    [[nodiscard]] std::string GetId() const;
    [[nodiscard]] std::string GetKode() const;
    [[nodiscard]] Term GetTerm() const;
};


#endif //LEGEMFEST_ELEMENT_H
