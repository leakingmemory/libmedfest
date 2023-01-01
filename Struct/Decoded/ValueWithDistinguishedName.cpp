//
// Created by jeo on 12/9/22.
//

#include "ValueWithDistinguishedName.h"

std::string ValueWithDistinguishedName::GetValue() const {
    return value;
}

std::string ValueWithDistinguishedName::GetDistinguishedName() const {
    return distinguishedName;
}