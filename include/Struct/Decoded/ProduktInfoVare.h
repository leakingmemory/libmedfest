//
// Created by sigsegv on 12/19/22.
//

#ifndef LEGEMFEST_PRODUKTINFOVARE_H
#define LEGEMFEST_PRODUKTINFOVARE_H

#include "EnhetStorrelse.h"
#include "MaybeBoolean.h"
#include <string>

class ProduktInfoVare {
private:
    std::string produktNr;
    std::string volum;
    EnhetStorrelse enhetStorrelse;
    int antPerPakning;
    MaybeBoolean tillattMerMakspris;
public:
    ProduktInfoVare() : produktNr(), volum(), enhetStorrelse(), antPerPakning(0),
                        tillattMerMakspris(MaybeBoolean::UNSPECIFIED) {}
    ProduktInfoVare(const std::string &produktNr, const std::string &volum, const EnhetStorrelse &enhetStorrelse,
                    int antPerPakning, MaybeBoolean tillattMerMakspris) :
            produktNr(produktNr), volum(volum), enhetStorrelse(enhetStorrelse), antPerPakning(antPerPakning),
            tillattMerMakspris(tillattMerMakspris) {}
    [[nodiscard]] std::string GetProduktNr() const;
    [[nodiscard]] std::string GetVolum() const;
    [[nodiscard]] EnhetStorrelse GetEnhetStorrelse() const;
    [[nodiscard]] int GetAntPerPakning() const;
    [[nodiscard]] MaybeBoolean GetTillattMerMakspris() const;
};


#endif //LEGEMFEST_PRODUKTINFOVARE_H
