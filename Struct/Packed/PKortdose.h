//
// Created by sigsegv on 2/15/23.
//

#ifndef LEGEMFEST_PKORTDOSE_H
#define LEGEMFEST_PKORTDOSE_H

#include "PValueWithCodeset.h"
#include "GenericListStorage.h"

class FestDeserializer;
class Kortdose;
class LegemiddelforbrukList;
class DoseringList;
class DoseFastTidspunktList;

class PKortdose {
    friend FestDeserializer;
private:
    PValueWithCodeset kortdose;
    PString beskrivelseTerm;
    GenericListItems legemiddelforbruk;
public:
    PKortdose(const Kortdose &, LegemiddelforbrukList &, DoseringList &, DoseFastTidspunktList &, std::string &strblock,
              std::map<std::string,uint32_t> &cache);
};


#endif //LEGEMFEST_PKORTDOSE_H
