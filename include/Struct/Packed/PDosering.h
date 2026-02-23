//
// Created by sigsegv on 2/14/23.
//

#ifndef LEGEMFEST_PDOSERING_H
#define LEGEMFEST_PDOSERING_H

#include "GenericListStorage.h"
#include <map>
#include <string>

class FestDeserializer_0;
class FestDeserializer_1;
class Dosering;
class DoseFastTidspunktList;

class PDosering : private GenericListItems32 {
    friend FestDeserializer_0;
    friend FestDeserializer_1;
public:
    PDosering(const Dosering &, DoseFastTidspunktList &, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PDosering &) const;
};


#endif //LEGEMFEST_PDOSERING_H
