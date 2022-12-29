//
// Created by sigsegv on 12/29/22.
//

#ifndef LEGEMFEST_PAKNINGSKOMPONENTINFO_H
#define LEGEMFEST_PAKNINGSKOMPONENTINFO_H

#include "Pakningstype.h"
#include "ValueUnit.h"

class PakningskomponentInfo {
private:
    Pakningstype pakningstype;
    ValueUnit mengde;
public:
    PakningskomponentInfo() : pakningstype(), mengde() {}
    PakningskomponentInfo(const Pakningstype &pakningstype, const ValueUnit &mengde) :
            pakningstype(pakningstype), mengde(mengde) {}
    [[nodiscard]] Pakningstype GetPakningstype() const;
    [[nodiscard]] ValueUnit GetMengde() const;
};


#endif //LEGEMFEST_PAKNINGSKOMPONENTINFO_H
