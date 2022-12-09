//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_ATC_H
#define LEGEMFEST_ATC_H

#include <string>

class Atc {
private:
    std::string code;
    std::string codeset;
    std::string distinguishedName;
public:
    Atc() : code(), codeset(), distinguishedName() {}
    Atc(const std::string &code, const std::string &codeset, const std::string &distinguishedName) : code(code), codeset(codeset), distinguishedName(distinguishedName) {}
    [[nodiscard]] std::string GetCode() const;
    [[nodiscard]] std::string GetCodeSet() const;
    [[nodiscard]] std::string GetDistinguishedName() const;
};


#endif //LEGEMFEST_ATC_H
