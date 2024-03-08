//
// Created by sigsegv on 12/30/22.
//

#ifndef LEGEMFEST_SUBSTANSGRUPPE_H
#define LEGEMFEST_SUBSTANSGRUPPE_H

#include "Substans.h"
#include <vector>

class PSubstansgruppe;

class Substansgruppe {
    friend PSubstansgruppe;
private:
    std::vector<Substans> substans;
    std::string navn{};
public:
    Substansgruppe() : substans() {}
    Substansgruppe(const std::vector<Substans> &substans, const std::string &navn) : substans(substans), navn(navn) {}
    [[nodiscard]] std::vector<Substans> GetSubstans() const;
    [[nodiscard]] std::string GetNavn() const;
};

#endif //LEGEMFEST_SUBSTANSGRUPPE_H
