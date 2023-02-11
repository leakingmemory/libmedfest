//
// Created by sigsegv on 2/10/23.
//

#ifndef LEGEMFEST_PBYTTEGRUPPE_H
#define LEGEMFEST_PBYTTEGRUPPE_H

#include "PValueWithDistinguishedName.h"
#include "PFestId.h"

class FestDeserializer;
class Byttegruppe;

class PByttegruppe {
    friend FestDeserializer;
private:
    PValueWithDistinguishedName kode;
    PString gyldigFraDato;
    PString beskrivelseByttbarhet;
    PFestId id;
    bool merknadTilByttbarhet;
public:
    PByttegruppe(const Byttegruppe &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
};


#endif //LEGEMFEST_PBYTTEGRUPPE_H
