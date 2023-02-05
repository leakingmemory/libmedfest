//
// Created by sigsegv on 2/4/23.
//

#ifndef LEGEMFEST_PINFO_H
#define LEGEMFEST_PINFO_H

#include "PFestId.h"
#include "PString.h"
#include <vector>
#include <map>

class FestDeserializer;
class Info;
class FestUuid;

class PInfo {
    friend FestDeserializer;
private:
    PString betegnelse;
    PString kortnavn;
    PString ansvarligUtgiver;
    PString id;
public:
    PInfo(const Info &, std::string &strblock, std::map<std::string,uint32_t> &cache);
};


#endif //LEGEMFEST_PINFO_H
