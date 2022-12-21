//
// Created by sigsegv on 12/19/22.
//

#ifndef LEGEMFEST_MEDFORBRMATR_H
#define LEGEMFEST_MEDFORBRMATR_H

#include "ProduktInfoVare.h"
#include "Leverandor.h"
#include <string>

class MedForbrMatr {
private:
    std::string nr;
    std::string navn;
    ProduktInfoVare produktInfoVare;
    Leverandor leverandor;
public:
    MedForbrMatr() : nr(), navn(), produktInfoVare(), leverandor() {}
    MedForbrMatr(const std::string &nr, const std::string &navn, const ProduktInfoVare &produktInfoVare,
                 const Leverandor &leverandor) :
            nr(nr), navn(navn), produktInfoVare(produktInfoVare), leverandor(leverandor) {}
    [[nodiscard]] std::string GetNr() const;
    [[nodiscard]] std::string GetNavn() const;
    [[nodiscard]] ProduktInfoVare GetProduktInfoVare() const;
    [[nodiscard]] Leverandor GetLeverandor() const;
};


#endif //LEGEMFEST_MEDFORBRMATR_H
