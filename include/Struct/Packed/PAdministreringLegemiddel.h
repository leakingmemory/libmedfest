//
// Created by sigsegv on 1/10/23.
//

#ifndef LEGEMFEST_PADMINISTRERINGLEGEMIDDEL_H
#define LEGEMFEST_PADMINISTRERINGLEGEMIDDEL_H

#include "PValueWithCodeset.h"
#include "GenericListStorage.h"
#include "../Decoded/MaybeBoolean.h"

class FestDeserializer;
class AdministreringLegemiddel;
class ValueWithCodesetList;
class ValueWithDistinguishedNameList;

class PAdministreringLegemiddel {
    friend FestDeserializer;
private:
    PValueWithCodeset administrasjonsvei;
    PValueWithCodeset enhetDosering;
    GenericListItems32 bruksomradeEtikett;
    GenericListItems32 forhandsregelInntak;
    GenericListItems32 kortdose;
    PValueWithDistinguishedName kanKnuses;
    PValueWithDistinguishedName deling;
    PValueWithDistinguishedName kanApnes;
    PValueWithDistinguishedName bolus;
    PValueWithDistinguishedName injeksjonshastighetBolus;
    uint8_t blandingsveske : 2;
public:
    PAdministreringLegemiddel(const AdministreringLegemiddel &administreringLegemiddel, std::string &strblock,
                              std::map<std::string,uint32_t> &cache, ValueWithCodesetList &valueWithCodesetList);
    bool operator == (const PAdministreringLegemiddel &) const;
    MaybeBoolean IsBlandingsveske() const;
};


#endif //LEGEMFEST_PADMINISTRERINGLEGEMIDDEL_H
