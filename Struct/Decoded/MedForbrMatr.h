//
// Created by sigsegv on 12/19/22.
//

#ifndef LEGEMFEST_MEDFORBRMATR_H
#define LEGEMFEST_MEDFORBRMATR_H

#include "ProduktInfoVare.h"
#include <string>

class MedForbrMatr {
private:
    std::string nr;
    std::string navn;
    ProduktInfoVare produktInfoVare;
public:
    MedForbrMatr() : nr(), navn(), produktInfoVare() {}
    MedForbrMatr(const std::string &nr, const std::string &navn, const ProduktInfoVare &produktInfoVare) :
            nr(nr), navn(navn), produktInfoVare(produktInfoVare) {}
    [[nodiscard]] std::string GetNr() const;
    [[nodiscard]] std::string GetNavn() const;
    [[nodiscard]] ProduktInfoVare GetProduktInfoVare() const;
};


#endif //LEGEMFEST_MEDFORBRMATR_H
