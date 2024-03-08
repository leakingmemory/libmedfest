//
// Created by sigsegv on 2/14/23.
//

#ifndef LEGEMFEST_PDOSEFASTTIDSPUNKT_H
#define LEGEMFEST_PDOSEFASTTIDSPUNKT_H

#include "PValueUnit.h"
#include "PValueWithDistinguishedName.h"

class FestDeserializer;
class DoseFastTidspunkt;

class PDoseFastTidspunkt {
    friend FestDeserializer;
private:
    PValueUnit mengde;
    PValueUnit intervall;
    PValueWithDistinguishedName tidsomrade;
    uint16_t dagerPa : 15;
    uint16_t dagerAv : 15;
    bool gisEksakt : 1;
public:
    PDoseFastTidspunkt(const DoseFastTidspunkt &, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PDoseFastTidspunkt &) const;
};


#endif //LEGEMFEST_PDOSEFASTTIDSPUNKT_H
