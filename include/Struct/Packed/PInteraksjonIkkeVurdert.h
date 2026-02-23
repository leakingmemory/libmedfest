//
// Created by sigsegv on 2/13/23.
//

#ifndef LEGEMFEST_PINTERAKSJONIKKEVURDERT_H
#define LEGEMFEST_PINTERAKSJONIKKEVURDERT_H

#include "PValueWithCodeset.h"

class FestDeserializer_0;
class FestDeserializer_1;
class InteraksjonIkkeVurdert;

class PInteraksjonIkkeVurdert {
    friend FestDeserializer_0;
    friend FestDeserializer_1;
private:
    PValueWithCodeset atc;
public:
    PInteraksjonIkkeVurdert(const InteraksjonIkkeVurdert &, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PInteraksjonIkkeVurdert &other) const {
        return atc == other.atc;
    }
};


#endif //LEGEMFEST_PINTERAKSJONIKKEVURDERT_H
