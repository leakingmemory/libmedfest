//
// Created by sigsegv on 2/11/23.
//

#ifndef LEGEMFEST_PREFERANSE_H
#define LEGEMFEST_PREFERANSE_H

#include "PString.h"
#include <map>

class FestDeserializer;
class Referanse;

class PReferanse {
    friend FestDeserializer;
private:
    PString kilde;
    PString lenke;
public:
    PReferanse(const Referanse &, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PReferanse &other) const;
};


#endif //LEGEMFEST_PREFERANSE_H
