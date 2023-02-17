//
// Created by sigsegv on 2/14/23.
//

#ifndef LEGEMFEST_PLEGEMIDDELFORBRUK_H
#define LEGEMFEST_PLEGEMIDDELFORBRUK_H

#include "GenericListStorage.h"
#include "PString.h"

class FestDeserializer;
class Legemiddelforbruk;
class DoseringList;
class DoseFastTidspunktList;

class PLegemiddelforbruk {
    friend FestDeserializer;
private:
    GenericListItems dosering;
    PString periode;
    double mengde;
    int64_t lopenr : 48;
    int16_t iterasjoner;
public:
    PLegemiddelforbruk(const Legemiddelforbruk &, DoseringList &, DoseFastTidspunktList &, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PLegemiddelforbruk &) const;
};


#endif //LEGEMFEST_PLEGEMIDDELFORBRUK_H
