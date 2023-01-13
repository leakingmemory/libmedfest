//
// Created by sigsegv on 1/10/23.
//

#include "PValueWithDistinguishedName.h"
#include "../Decoded/ValueWithDistinguishedName.h"

PValueWithDistinguishedName::PValueWithDistinguishedName(const ValueWithDistinguishedName &valueWithDistinguishedName,
                                                         std::string &strblock) :
        value(valueWithDistinguishedName.GetValue(), strblock),
        distinguishedName(valueWithDistinguishedName.GetDistinguishedName(), strblock) {
}