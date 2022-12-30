//
// Created by sigsegv on 12/30/22.
//

#ifndef LEGEMFEST_SUBSTANS_H
#define LEGEMFEST_SUBSTANS_H

#include "Atc.h"

class Substans {
private:
    std::string substans;
    Atc atc;
    std::string refVirkestoff;
public:
    Substans() : substans(), atc(), refVirkestoff() {}
    Substans(const std::string &substans, const Atc &atc, const std::string &refVirkestoff) :
            substans(substans), atc(atc), refVirkestoff(refVirkestoff) {}
    [[nodiscard]] std::string GetSubstans() const;
    [[nodiscard]] Atc GetAtc() const;
    [[nodiscard]] std::string GetRefVirkestoff() const;
};


#endif //LEGEMFEST_SUBSTANS_H
