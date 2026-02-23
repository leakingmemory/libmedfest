//
// Created by sigsegv on 2/15/23.
//

#ifndef LEGEMFEST_PKORTDOSE_H
#define LEGEMFEST_PKORTDOSE_H

#include "PValueWithCodeset.h"
#include "GenericListStorage.h"

class FestDeserializer_0;
class FestDeserializer_1;
class Kortdose;
class LegemiddelforbrukList;
class DoseringList;
class DoseFastTidspunktList;

class PKortdose {
    friend FestDeserializer_0;
    friend FestDeserializer_1;
private:
    PValueWithCodeset kortdose;
    PString beskrivelseTerm;
    GenericListItems32 legemiddelforbruk;
public:
    PKortdose(const Kortdose &, LegemiddelforbrukList &, DoseringList &, DoseFastTidspunktList &, std::string &strblock,
              std::map<std::string,uint32_t> &cache);
    bool operator == (const PKortdose &) const;
};


#endif //LEGEMFEST_PKORTDOSE_H
