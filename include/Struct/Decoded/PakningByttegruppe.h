//
// Created by sigsegv on 12/14/22.
//

#ifndef LEGEMFEST_PAKNINGBYTTEGRUPPE_H
#define LEGEMFEST_PAKNINGBYTTEGRUPPE_H

#include <string>

class PakningByttegruppe {
private:
    std::string refByttegruppe;
    std::string gyldigFraDato;
public:
    PakningByttegruppe() : refByttegruppe(), gyldigFraDato() {}
    PakningByttegruppe(const std::string &refByttegruppe, const std::string &gyldigFraDato) : refByttegruppe(refByttegruppe), gyldigFraDato(gyldigFraDato) {}
    [[nodiscard]] std::string GetRefByttegruppe() const;
    [[nodiscard]] std::string GetGyldigFraDato() const;
};


#endif //LEGEMFEST_PAKNINGBYTTEGRUPPE_H
