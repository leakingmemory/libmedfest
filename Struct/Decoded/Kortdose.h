//
// Created by sigsegv on 12/11/22.
//

#ifndef LEGEMFEST_KORTDOSE_H
#define LEGEMFEST_KORTDOSE_H

#include "ValueWithCodeSet.h"
#include "Legemiddelforbruk.h"
#include <vector>

class PKortdose;

class Kortdose {
    friend PKortdose;
private:
    ValueWithCodeSet kortdose;
    std::string beskrivelseTerm;
    std::vector<Legemiddelforbruk> legemiddelforbruk;
public:
    Kortdose() : kortdose(), beskrivelseTerm(), legemiddelforbruk() {}
    Kortdose(const ValueWithCodeSet &valueWithCodeSet, const std::string &beskrivelseTerm,
             const std::vector<Legemiddelforbruk> &legemiddelforbruk) :
            kortdose(valueWithCodeSet), beskrivelseTerm(beskrivelseTerm), legemiddelforbruk(legemiddelforbruk) {}
    [[nodiscard]] ValueWithCodeSet GetKortdose() const;
    [[nodiscard]] std::string GetBeskrivelseTerm() const;
    [[nodiscard]] std::vector<Legemiddelforbruk> GetLegemiddelforbruk() const;
};

#endif //LEGEMFEST_KORTDOSE_H
