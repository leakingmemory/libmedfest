//
// Created by sigsegv on 2/14/23.
//

#ifndef LEGEMFEST_PDOSERING_H
#define LEGEMFEST_PDOSERING_H

#include "GenericListStorage.h"
#include <map>
#include <string>

class FestDeserializer;
class Dosering;
class DoseFastTidspunktList;

class PDosering : private GenericListItems32 {
    friend FestDeserializer;
public:
    PDosering(const Dosering &, DoseFastTidspunktList &, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PDosering &) const;
};


#endif //LEGEMFEST_PDOSERING_H
