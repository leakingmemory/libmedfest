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
public:
    Pakningskomponent() : pakningstype(), mengde() {}
    Pakningskomponent(const Pakningstype &pakningstype, const ValueUnit &mengde) : pakningstype(pakningstype), mengde(mengde) {}
    [[nodiscard]] Pakningstype GetPakningstype() const;
    [[nodiscard]] ValueUnit GetMengde() const;
};


#endif //LEGEMFEST_PAKNINGSKOMPONENT_H
