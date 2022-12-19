//
// Created by sigsegv on 12/19/22.
//

#ifndef LEGEMFEST_MEDFORBRMATR_H
#define LEGEMFEST_MEDFORBRMATR_H

#include <string>

class MedForbrMatr {
private:
    std::string nr;
    std::string navn;
public:
    MedForbrMatr() : nr(), navn() {}
    MedForbrMatr(const std::string &nr, const std::string &navn) : nr(nr), navn(navn) {}
    [[nodiscard]] std::string GetNr() const;
    [[nodiscard]] std::string GetNavn() const;
};


#endif //LEGEMFEST_MEDFORBRMATR_H
