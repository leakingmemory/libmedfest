//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_ATC_H
#define LEGEMFEST_ATC_H

#include <string>
#include "ValueWithDistinguishedName.h"

class Atc : public ValueWithDistinguishedName {
private:
    std::string codeset;
public:
    Atc() : ValueWithDistinguishedName(), codeset() {}
    Atc(const std::string &code, const std::string &codeset, const std::string &distinguishedName) : ValueWithDistinguishedName(code, distinguishedName), codeset(codeset) {}
    [[nodiscard]] std::string GetCodeSet() const;
};


#endif //LEGEMFEST_ATC_H
