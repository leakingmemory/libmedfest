//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_STATUS_H
#define LEGEMFEST_STATUS_H

#include <string>

class Status {
private:
    std::string value;
    std::string distinguishedName;
public:
    Status() : value(), distinguishedName() {}
    Status(const std::string &value, const std::string &distinguishedName) : value(value), distinguishedName(distinguishedName) {}
    std::string GetValue();
    std::string GetDistinguishedName();
};


#endif //LEGEMFEST_STATUS_H
