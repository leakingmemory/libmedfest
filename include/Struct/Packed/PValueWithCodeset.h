//
// Created by sigsegv on 1/10/23.
//

#ifndef LEGEMFEST_PVALUEWITHCODESET_H
#define LEGEMFEST_PVALUEWITHCODESET_H

#include "PValueWithDistinguishedName.h"

class FestDeserializer_0;
class FestDeserializer_1;
class ValueWithCodeSet;

class PValueWithCodeset : public PValueWithDistinguishedName {
    friend FestDeserializer_0;
    friend FestDeserializer_1;
private:
    PString codeSet;
public:
    PValueWithCodeset(const ValueWithCodeSet &valueWithCodeSet, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PValueWithCodeset &other) const {
        return PValueWithDistinguishedName::operator==(other) && codeSet == other.codeSet;
    }
    [[nodiscard]] PString GetCodeSet() const;
};


#endif //LEGEMFEST_PVALUEWITHCODESET_H
