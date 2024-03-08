//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_VALUEWITHDISTINGUISHEDNAME_H
#define LEGEMFEST_VALUEWITHDISTINGUISHEDNAME_H

#include <string>

class ValueWithDistinguishedName {
private:
    std::string value;
    std::string distinguishedName;
public:
    ValueWithDistinguishedName() : value(), distinguishedName() {}
    ValueWithDistinguishedName(const std::string &value, const std::string &distinguishedName) : value(value), distinguishedName(distinguishedName) {}
    [[nodiscard]] std::string GetValue() const;
    [[nodiscard]] std::string GetDistinguishedName() const;
};


#endif //LEGEMFEST_VALUEWITHDISTINGUISHEDNAME_H
