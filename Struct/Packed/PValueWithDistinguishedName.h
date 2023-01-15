//
// Created by sigsegv on 1/10/23.
//

#ifndef LEGEMFEST_PVALUEWITHDISTINGUISHEDNAME_H
#define LEGEMFEST_PVALUEWITHDISTINGUISHEDNAME_H


#include "PString.h"

class FestDeserializer;
class ValueWithDistinguishedName;

class PValueWithDistinguishedName {
    friend FestDeserializer;
private:
    PString value;
    PString distinguishedName;
public:
    PValueWithDistinguishedName() : value(), distinguishedName() {}
    PValueWithDistinguishedName(const ValueWithDistinguishedName &valueWithDistinguishedName, std::string &strblock);
    bool operator == (const PValueWithDistinguishedName &other) const {
        return value == other.value && distinguishedName == other.distinguishedName;
    }
};


#endif //LEGEMFEST_PVALUEWITHDISTINGUISHEDNAME_H
