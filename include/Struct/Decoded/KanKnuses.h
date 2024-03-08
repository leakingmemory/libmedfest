//
// Created by sigsegv on 12/10/22.
//

#ifndef LEGEMFEST_KANKNUSES_H
#define LEGEMFEST_KANKNUSES_H

#include "ValueWithDistinguishedName.h"

class KanKnuses : public ValueWithDistinguishedName {
public:
    KanKnuses() : ValueWithDistinguishedName() {}
    KanKnuses(const ValueWithDistinguishedName &valueWithDistinguishedName) : ValueWithDistinguishedName(valueWithDistinguishedName) {}
};

#endif //LEGEMFEST_KANKNUSES_H
