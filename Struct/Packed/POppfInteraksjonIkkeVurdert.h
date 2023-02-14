//
// Created by sigsegv on 2/13/23.
//

#ifndef LEGEMFEST_POPPFINTERAKSJONIKKEVURDERT_H
#define LEGEMFEST_POPPFINTERAKSJONIKKEVURDERT_H

#include "POppf.h"
#include "PInteraksjonIkkeVurdert.h"

class FestDeserializer;
class OppfInteraksjonIkkeVurdert;

class POppfInteraksjonIkkeVurdert : public POppf, public PInteraksjonIkkeVurdert {
    friend FestDeserializer;
public:
    POppfInteraksjonIkkeVurdert(const OppfInteraksjonIkkeVurdert &, std::vector<FestUuid> &idblock, std::string &strblock,
                                std::map<std::string,uint32_t> &cache);
};


#endif //LEGEMFEST_POPPFINTERAKSJONIKKEVURDERT_H
