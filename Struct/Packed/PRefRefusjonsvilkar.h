//
// Created by sigsegv on 2/5/23.
//

#ifndef LEGEMFEST_PREFREFUSJONSVILKAR_H
#define LEGEMFEST_PREFREFUSJONSVILKAR_H

#include "PFestId.h"
#include "PString.h"
#include <map>

class FestDeserializer;
class RefRefusjonsvilkar;

class PRefRefusjonsvilkar {
    friend FestDeserializer;
private:
    PFestId id;
    PString fraDato;
public:
    PRefRefusjonsvilkar(const RefRefusjonsvilkar &, std::vector<FestUuid> &idblock, std::string &strblock,
                        std::map<std::string,uint32_t> &cache);
    bool operator == (const PRefRefusjonsvilkar &other) const;
};


#endif //LEGEMFEST_PREFREFUSJONSVILKAR_H
