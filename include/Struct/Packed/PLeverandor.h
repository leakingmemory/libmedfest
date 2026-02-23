//
// Created by sigsegv on 1/29/23.
//

#ifndef LEGEMFEST_PLEVERANDOR_H
#define LEGEMFEST_PLEVERANDOR_H

#include "PString.h"

class FestDeserializer_0;
class FestDeserializer_1;
class Leverandor;

class PLeverandor {
    friend FestDeserializer_0;
    friend FestDeserializer_1;
private:
    PString navn;
    PString adresse;
    PString telefon;
public:
    PLeverandor(const Leverandor &leverandor, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PLeverandor &) const;
};


#endif //LEGEMFEST_PLEVERANDOR_H
