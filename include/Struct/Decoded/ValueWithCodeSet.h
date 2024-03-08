//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_VALUEWITHCODESET_H
#define LEGEMFEST_VALUEWITHCODESET_H


#include "ValueWithDistinguishedName.h"

class ValueWithCodeSet : public ValueWithDistinguishedName {
private:
    std::string codeSet;
public:
    ValueWithCodeSet() : ValueWithDistinguishedName(), codeSet() {}
    ValueWithCodeSet(const ValueWithDistinguishedName &valueWithDistinguishedName, const std::string &codeSet) : ValueWithDistinguishedName(valueWithDistinguishedName), codeSet(codeSet) {}
    [[nodiscard]] std::string GetCodeSet() const;
};


#endif //LEGEMFEST_VALUEWITHCODESET_H
