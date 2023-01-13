//
// Created by sigsegv on 1/10/23.
//

#include "PValueWithCodeset.h"
#include "../Decoded/ValueWithCodeSet.h"

PValueWithCodeset::PValueWithCodeset(const ValueWithCodeSet &valueWithCodeSet, std::string &strblock) :
        PValueWithDistinguishedName(valueWithCodeSet, strblock),
        codeSet(valueWithCodeSet.GetCodeSet(), strblock) {
}