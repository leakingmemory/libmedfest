//
// Created by sigsegv on 1/18/23.
//

#ifndef LEGEMFEST_PPAKNINGSKOMPONENTINFO_H
#define LEGEMFEST_PPAKNINGSKOMPONENTINFO_H

#include "PValueWithCodeset.h"
#include "PValueUnit.h"

class FestDeserializer;
class PakningskomponentInfo;

class PPakningskomponentInfo {
private:
    PValueWithCodeset pakningstype;
    PValueUnit mengde;
public:
    PPakningskomponentInfo(const PakningskomponentInfo &, std::string &strblock);
    bool operator == (const PPakningskomponentInfo &other) const;
};


#endif //LEGEMFEST_PPAKNINGSKOMPONENTINFO_H
