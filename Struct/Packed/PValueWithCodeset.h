//
// Created by sigsegv on 1/10/23.
//

#ifndef LEGEMFEST_PVALUEWITHCODESET_H
#define LEGEMFEST_PVALUEWITHCODESET_H

#include "PValueWithDistinguishedName.h"

class FestDeserializer;
class ValueWithCodeSet;

class PValueWithCodeset : public PValueWithDistinguishedName {
    friend FestDeserializer;
private:
    PString codeSet;
public:
    PValueWithCodeset(const ValueWithCodeSet &valueWithCodeSet, std::string &strblock);
    bool operator == (const PValueWithCodeset &other) const {
        return PValueWithDistinguishedName::operator==(other) && codeSet == other.codeSet;
    }
};


#endif //LEGEMFEST_PVALUEWITHCODESET_H
