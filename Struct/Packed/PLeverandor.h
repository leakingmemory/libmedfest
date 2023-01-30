//
// Created by sigsegv on 1/29/23.
//

#ifndef LEGEMFEST_PLEVERANDOR_H
#define LEGEMFEST_PLEVERANDOR_H

#include "PString.h"

class FestDeserializer;
class Leverandor;

class PLeverandor {
    friend FestDeserializer;
private:
    PString navn;
    PString adresse;
    PString telefon;
public:
    PLeverandor(const Leverandor &leverandor, std::string &strblock);
};


#endif //LEGEMFEST_PLEVERANDOR_H
