//
// Created by sigsegv on 2/8/23.
//

#ifndef LEGEMFEST_POPPFVILKAR_H
#define LEGEMFEST_POPPFVILKAR_H

#include "POppf.h"
#include "PVilkar.h"

class FestDeserializer;
class OppfVilkar;

class POppfVilkar : public POppf, public PVilkar {
    friend FestDeserializer;
public:
    POppfVilkar(const OppfVilkar &, std::vector<FestUuid> &idblock, std::string &strblock,
                std::map<std::string,uint32_t> &cache);
};


#endif //LEGEMFEST_POPPFVILKAR_H
