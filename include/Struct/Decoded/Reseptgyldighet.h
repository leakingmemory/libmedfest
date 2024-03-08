//
// Created by sigsegv on 12/11/22.
//

#ifndef LEGEMFEST_RESEPTGYLDIGHET_H
#define LEGEMFEST_RESEPTGYLDIGHET_H

#include "ValueWithDistinguishedName.h"
#include <string>

class Reseptgyldighet {
private:
    std::string varighet;
    ValueWithDistinguishedName kjonn;
public:
    Reseptgyldighet() : varighet(), kjonn() {}
    Reseptgyldighet(const std::string &varighet, const ValueWithDistinguishedName &kjonn) :
        varighet(varighet), kjonn(kjonn) {}
    [[nodiscard]] std::string GetVarighet() const;
    [[nodiscard]] ValueWithDistinguishedName GetKjonn() const;
};

#endif //LEGEMFEST_RESEPTGYLDIGHET_H
