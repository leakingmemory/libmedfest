//
// Created by sigsegv on 1/10/23.
//

#include "PValueWithCodeset.h"
#include "../Decoded/ValueWithCodeSet.h"

PValueWithCodeset::PValueWithCodeset(const ValueWithCodeSet &valueWithCodeSet, std::string &strblock, std::map<std::string,uint32_t> &cache) :
        PValueWithDistinguishedName(valueWithCodeSet, strblock, cache),
        codeSet(valueWithCodeSet.GetCodeSet(), strblock, cache) {
}