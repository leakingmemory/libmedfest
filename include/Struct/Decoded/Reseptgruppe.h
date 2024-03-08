//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_RESEPTGRUPPE_H
#define LEGEMFEST_RESEPTGRUPPE_H

#include "ValueWithDistinguishedName.h"

class Reseptgruppe : public ValueWithDistinguishedName {
public:
    Reseptgruppe() : ValueWithDistinguishedName() {}
    Reseptgruppe(const ValueWithDistinguishedName &valueWithDistinguishedName) : ValueWithDistinguishedName(valueWithDistinguishedName) {}
};


#endif //LEGEMFEST_RESEPTGRUPPE_H
