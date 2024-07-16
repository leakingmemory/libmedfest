//
// Created by sigsegv on 12/27/22.
//

#ifndef LEGEMFEST_REFERANSEELEMENT_H
#define LEGEMFEST_REFERANSEELEMENT_H

#include "Klasse.h"
#include <vector>

class PReferanseelement_0_0_0;
class PReferanseelement_0_4_0;

class Referanseelement {
    friend PReferanseelement_0_0_0;
    friend PReferanseelement_0_4_0;
private:
    Klasse klasse;
    std::vector<std::string> refs;
public:
    Referanseelement() : klasse() {}
    Referanseelement(const Klasse &klasse, const std::vector<std::string> &refs) : klasse(klasse), refs(refs) {}
    [[nodiscard]] Klasse GetKlasse() const;
    [[nodiscard]] std::vector<std::string> GetRefs() const;
};


#endif //LEGEMFEST_REFERANSEELEMENT_H
