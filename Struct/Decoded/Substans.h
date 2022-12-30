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
public:
    Substans() : substans(), atc() {}
    Substans(const std::string &substans, const Atc &atc) : substans(substans), atc(atc) {}
    [[nodiscard]] std::string GetSubstans() const;
    [[nodiscard]] Atc GetAtc() const;
};


#endif //LEGEMFEST_SUBSTANS_H
