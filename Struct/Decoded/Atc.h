//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_ATC_H
#define LEGEMFEST_ATC_H

#include <string>
#include "ValueWithCodeSet.h"

class Atc : public ValueWithCodeSet {
public:
    Atc() : ValueWithCodeSet() {}
    Atc(const ValueWithCodeSet &valueWithCodeSet) : ValueWithCodeSet(valueWithCodeSet) {}
    Atc(const std::string &code, const std::string &codeset, const std::string &distinguishedName) : ValueWithCodeSet(ValueWithDistinguishedName(code, distinguishedName), codeset) {}
};


#endif //LEGEMFEST_ATC_H
