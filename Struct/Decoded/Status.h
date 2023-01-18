//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_STATUS_H
#define LEGEMFEST_STATUS_H

#include "ValueWithDistinguishedName.h"
#include <string>

class Status : public ValueWithDistinguishedName {
public:
    Status() : ValueWithDistinguishedName() {}
    Status(const ValueWithDistinguishedName &v) : ValueWithDistinguishedName(v) {}
    Status(const std::string &value, const std::string &distinguishedName) : ValueWithDistinguishedName(value, distinguishedName) {}
};


#endif //LEGEMFEST_STATUS_H
