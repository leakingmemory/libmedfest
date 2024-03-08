//
// Created by sigsegv on 12/11/22.
//

#ifndef LEGEMFEST_INJEKSJONSHASTIGHETBOLUS_H
#define LEGEMFEST_INJEKSJONSHASTIGHETBOLUS_H

#include "ValueWithDistinguishedName.h"

class InjeksjonshastighetBolus : public ValueWithDistinguishedName {
public:
    InjeksjonshastighetBolus() : ValueWithDistinguishedName() {}
    InjeksjonshastighetBolus(const ValueWithDistinguishedName &valueWithDistinguishedName) : ValueWithDistinguishedName(valueWithDistinguishedName) {}
};

#endif //LEGEMFEST_INJEKSJONSHASTIGHETBOLUS_H
