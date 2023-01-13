//
// Created by sigsegv on 1/10/23.
//

#ifndef LEGEMFEST_PADMINISTRERINGLEGEMIDDEL_H
#define LEGEMFEST_PADMINISTRERINGLEGEMIDDEL_H

#include "PValueWithCodeset.h"
#include "GenericListStorage.h"

class AdministreringLegemiddel;
class ValueWithCodesetList;
class ValueWithDistinguishedNameList;

class PAdministreringLegemiddel {
private:
    PValueWithCodeset administrasjonsvei;
    PValueWithCodeset enhetDosering;
    GenericListItems bruksomradeEtikett;
    GenericListItems forhandsregelInntak;
    GenericListItems kortdose;
    PValueWithDistinguishedName kanKnuses;
    PValueWithDistinguishedName deling;
    PValueWithDistinguishedName kanApnes;
    PValueWithDistinguishedName bolus;
    PValueWithDistinguishedName injeksjonshastighetBolus;
    uint8_t blandingsveske : 2;
public:
    PAdministreringLegemiddel(const AdministreringLegemiddel &administreringLegemiddel, std::string &strblock,
                              ValueWithCodesetList &valueWithCodesetList);
};


#endif //LEGEMFEST_PADMINISTRERINGLEGEMIDDEL_H
