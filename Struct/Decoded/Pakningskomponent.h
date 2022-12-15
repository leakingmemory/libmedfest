//
// Created by sigsegv on 12/12/22.
//

#ifndef LEGEMFEST_PAKNINGSKOMPONENT_H
#define LEGEMFEST_PAKNINGSKOMPONENT_H

#include "Pakningstype.h"
#include "ValueUnit.h"

class Pakningskomponent {
private:
    Pakningstype pakningstype;
    ValueUnit mengde;
    int antall;
public:
    Pakningskomponent() : pakningstype(), mengde(), antall(0) {}
    Pakningskomponent(const Pakningstype &pakningstype, const ValueUnit &mengde, int antall) :
            pakningstype(pakningstype), mengde(mengde), antall(antall) {}
    [[nodiscard]] Pakningstype GetPakningstype() const;
    [[nodiscard]] ValueUnit GetMengde() const;
    [[nodiscard]] int GetAntall() const;
};


#endif //LEGEMFEST_PAKNINGSKOMPONENT_H
