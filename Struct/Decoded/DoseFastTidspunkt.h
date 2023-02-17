//
// Created by sigsegv on 12/31/22.
//

#ifndef LEGEMFEST_DOSEFASTTIDSPUNKT_H
#define LEGEMFEST_DOSEFASTTIDSPUNKT_H

#include "ValueUnit.h"
#include "ValueWithDistinguishedName.h"
#include "FastDose.h"

class PDoseFastTidspunkt;

class DoseFastTidspunkt {
    friend PDoseFastTidspunkt;
private:
    ValueUnit mengde;
    ValueUnit intervall;
    ValueWithDistinguishedName tidsomrade;
    bool gisEksakt;
    FastDose fastDose;
public:
    DoseFastTidspunkt() : mengde(), intervall(), tidsomrade(), gisEksakt(), fastDose() {}
    DoseFastTidspunkt(const ValueUnit &mengde, const ValueUnit &intervall, const ValueWithDistinguishedName &tidsomrade,
                      bool gisEksakt, const FastDose &fastDose) :
            mengde(mengde), intervall(intervall), tidsomrade(tidsomrade), gisEksakt(gisEksakt), fastDose(fastDose) {}
    [[nodiscard]] ValueUnit GetMengde() const;
    [[nodiscard]] ValueUnit GetIntervall() const;
    [[nodiscard]] ValueWithDistinguishedName GetTidsomrade() const;
    [[nodiscard]] bool GetGisEksakt() const;
    [[nodiscard]] FastDose GetFastDose() const;
};


#endif //LEGEMFEST_DOSEFASTTIDSPUNKT_H
