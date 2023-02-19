//
// Created by sigsegv on 2/13/23.
//

#ifndef LEGEMFEST_PINTERAKSJONIKKEVURDERT_H
#define LEGEMFEST_PINTERAKSJONIKKEVURDERT_H

#include "PValueWithCodeset.h"

class FestDeserializer;
class InteraksjonIkkeVurdert;

class PInteraksjonIkkeVurdert {
    friend FestDeserializer;
private:
    PValueWithCodeset atc;
public:
    PInteraksjonIkkeVurdert(const InteraksjonIkkeVurdert &, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PInteraksjonIkkeVurdert &other) const {
        return atc == other.atc;
    }
};


#endif //LEGEMFEST_PINTERAKSJONIKKEVURDERT_H
