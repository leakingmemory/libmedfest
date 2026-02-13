//
// Created by sigsegv on 2/10/23.
//

#ifndef LEGEMFEST_PBYTTEGRUPPE_H
#define LEGEMFEST_PBYTTEGRUPPE_H

#include "PValueWithDistinguishedName.h"
#include "PFestId.h"
#include <variant>

class FestDeserializer;
class Byttegruppe;
class PByttegruppe_1_5_0;

class PByttegruppe_0_0_0 {
    friend FestDeserializer;
    friend PByttegruppe_1_5_0;
private:
    PValueWithDistinguishedName kode;
    PString gyldigFraDato;
    PString beskrivelseByttbarhet;
    PFestId id;
    bool merknadTilByttbarhet;
public:
    PByttegruppe_0_0_0(const Byttegruppe &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    ~PByttegruppe_0_0_0();
    bool operator == (const PByttegruppe_0_0_0 &) const;
};

class PByttegruppe_1_5_0 {
    friend FestDeserializer;
private:
    PValueWithDistinguishedName kode;
    PString gyldigFraDato;
    PString gyldigTilDato;
    PString beskrivelseByttbarhet;
    PFestId id;
    bool merknadTilByttbarhet;
public:
    PByttegruppe_1_5_0(const Byttegruppe &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    PByttegruppe_1_5_0(const PByttegruppe_0_0_0 &pbyttegruppe);
    ~PByttegruppe_1_5_0();
    bool operator == (const PByttegruppe_1_5_0 &) const;
};

class PByttegruppe : public std::variant<PByttegruppe_0_0_0,PByttegruppe_1_5_0> {
public:
    PByttegruppe(const PByttegruppe_0_0_0 &pbyttegruppe) : std::variant<PByttegruppe_0_0_0,PByttegruppe_1_5_0>(pbyttegruppe) {
    }
    PByttegruppe(const PByttegruppe_1_5_0 &pbyttegruppe) : std::variant<PByttegruppe_0_0_0,PByttegruppe_1_5_0>(pbyttegruppe) {
    }
    ~PByttegruppe();
    bool operator == (const PByttegruppe &) const;
};


#endif //LEGEMFEST_PBYTTEGRUPPE_H
