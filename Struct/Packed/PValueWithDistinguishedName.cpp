//
// Created by sigsegv on 1/10/23.
//

#include "PValueWithDistinguishedName.h"
#include "../Decoded/ValueWithDistinguishedName.h"

PValueWithDistinguishedName::PValueWithDistinguishedName(const ValueWithDistinguishedName &valueWithDistinguishedName,
                                                         std::string &strblock, std::map<std::string,uint32_t> &cache) :
        value(valueWithDistinguishedName.GetValue(), strblock, cache),
        distinguishedName(valueWithDistinguishedName.GetDistinguishedName(), strblock, cache) {
}