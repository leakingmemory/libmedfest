//
// Created by sigsegv on 12/19/22.
//

#ifndef LEGEMFEST_MEDFORBRMATR_H
#define LEGEMFEST_MEDFORBRMATR_H

#include "ProduktInfoVare.h"
#include "Leverandor.h"
#include "PrisVare.h"
#include "Refusjon.h"
#include <string>
#include <vector>

class MedForbrMatr {
private:
    std::string nr;
    std::string navn;
    ProduktInfoVare produktInfoVare;
    Leverandor leverandor;
    std::vector<PrisVare> prisVare;
    Refusjon refusjon;
public:
    MedForbrMatr() : nr(), navn(), produktInfoVare(), leverandor(), prisVare(), refusjon() {}
    MedForbrMatr(const std::string &nr, const std::string &navn, const ProduktInfoVare &produktInfoVare,
                 const Leverandor &leverandor, const std::vector<PrisVare> &prisVare, const Refusjon &refusjon) :
            nr(nr), navn(navn), produktInfoVare(produktInfoVare), leverandor(leverandor), prisVare(prisVare),
            refusjon(refusjon) {}
    [[nodiscard]] std::string GetNr() const;
    [[nodiscard]] std::string GetNavn() const;
    [[nodiscard]] ProduktInfoVare GetProduktInfoVare() const;
    [[nodiscard]] Leverandor GetLeverandor() const;
    [[nodiscard]] std::vector<PrisVare> GetPrisVare() const;
    [[nodiscard]] Refusjon GetRefusjon() const;
};


#endif //LEGEMFEST_MEDFORBRMATR_H
