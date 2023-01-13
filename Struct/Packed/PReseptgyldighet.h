//
// Created by sigsegv on 1/10/23.
//

#ifndef LEGEMFEST_PRESEPTGYLDIGHET_H
#define LEGEMFEST_PRESEPTGYLDIGHET_H

#include "PValueWithDistinguishedName.h"

class Reseptgyldighet;

class PReseptgyldighet {
private:
    PValueWithDistinguishedName kjonn;
    PString varighet;
public:
    PReseptgyldighet(const Reseptgyldighet &reseptgyldighet, std::string &strblock);
    bool operator == (const PReseptgyldighet &other) const {
        return kjonn == other.kjonn && varighet == other.varighet;
    }
};


#endif //LEGEMFEST_PRESEPTGYLDIGHET_H
