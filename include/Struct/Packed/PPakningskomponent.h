//
// Created by sigsegv on 1/18/23.
//

#ifndef LEGEMFEST_PPAKNINGSKOMPONENT_H
#define LEGEMFEST_PPAKNINGSKOMPONENT_H

#include "PPakningskomponentInfo.h"

class FestDeserializer;
class Pakningskomponent;

class PPakningskomponent : public PPakningskomponentInfo {
    friend FestDeserializer;
private:
    uint16_t antall;
public:
    PPakningskomponent(const Pakningskomponent &, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PPakningskomponent &other) const;
};


#endif //LEGEMFEST_PPAKNINGSKOMPONENT_H
