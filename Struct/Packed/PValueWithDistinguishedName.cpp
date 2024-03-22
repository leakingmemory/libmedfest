//
// Created by sigsegv on 1/10/23.
//

#include <Struct/Packed/PValueWithDistinguishedName.h>
#include <Struct//Decoded/ValueWithDistinguishedName.h>

PValueWithDistinguishedName::PValueWithDistinguishedName(const ValueWithDistinguishedName &valueWithDistinguishedName,
                                                         std::string &strblock, std::map<std::string,uint32_t> &cache) :
        value(valueWithDistinguishedName.GetValue(), strblock, cache),
        distinguishedName(valueWithDistinguishedName.GetDistinguishedName(), strblock, cache) {
}

PString PValueWithDistinguishedName::GetValue() const {
    return value;
}
PString PValueWithDistinguishedName::GetDistinguishedName() const {
    return distinguishedName;
}
