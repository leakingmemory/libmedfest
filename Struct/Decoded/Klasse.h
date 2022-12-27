//
// Created by sigsegv on 12/27/22.
//

#ifndef LEGEMFEST_KLASSE_H
#define LEGEMFEST_KLASSE_H

#include "ValueWithDistinguishedName.h"

class Klasse : public ValueWithDistinguishedName {
public:
    Klasse() : ValueWithDistinguishedName() {}
    Klasse(const ValueWithDistinguishedName &valueWithDistinguishedName) : ValueWithDistinguishedName(valueWithDistinguishedName) {}
};

#endif //LEGEMFEST_KLASSE_H
