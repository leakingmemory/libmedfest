//
// Created by sigsegv on 12/9/22.
//

#ifndef LEGEMFEST_ADMINISTRERINGLEGEMIDDEL_H
#define LEGEMFEST_ADMINISTRERINGLEGEMIDDEL_H


#include "Administrasjonsvei.h"
#include "EnhetDosering.h"

class AdministreringLegemiddel {
private:
    Administrasjonsvei administrasjonsvei;
    EnhetDosering enhetDosering;
public:
    AdministreringLegemiddel() : administrasjonsvei(), enhetDosering() {}
    AdministreringLegemiddel(const Administrasjonsvei &administrasjonsvei, const EnhetDosering &enhetDosering) :
            administrasjonsvei(administrasjonsvei), enhetDosering(enhetDosering) {}
    [[nodiscard]] Administrasjonsvei GetAdministrasjonsvei() const;
    [[nodiscard]] EnhetDosering GetEnhetDosering() const;
};


#endif //LEGEMFEST_ADMINISTRERINGLEGEMIDDEL_H
