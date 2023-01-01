//
// Created by sigsegv on 12/30/22.
//

#ifndef LEGEMFEST_LEGEMIDDELFORBRUK_H
#define LEGEMFEST_LEGEMIDDELFORBRUK_H

#include "Dosering.h"

class Legemiddelforbruk {
private:
    int lopenr;
    int iterasjoner;
    double mengde;
    std::string periode;
    std::vector<Dosering> dosering;
public:
    Legemiddelforbruk() : lopenr(0), iterasjoner(0), mengde(0.0), periode(), dosering() {}
    Legemiddelforbruk(int lopenr, int iterasjoner, double mengde, const std::string &periode, const std::vector<Dosering> &dosering) :
            lopenr(lopenr), iterasjoner(iterasjoner), mengde(mengde), periode(periode), dosering(dosering) {}
    int GetLopenr() const;
    int GetIterasjoner() const;
    double GetMengde() const;
    std::string GetPeriode() const;
    std::vector<Dosering> GetDosering() const;
};


#endif //LEGEMFEST_LEGEMIDDELFORBRUK_H
