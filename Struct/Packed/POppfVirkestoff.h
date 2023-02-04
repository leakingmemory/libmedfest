//
// Created by sigsegv on 2/4/23.
//

#ifndef LEGEMFEST_POPPFVIRKESTOFF_H
#define LEGEMFEST_POPPFVIRKESTOFF_H

#include "POppf.h"
#include "PVirkestoff.h"

class OppfVirkestoff;

class POppfVirkestoff : public POppf, public PVirkestoff {
public:
    POppfVirkestoff(const OppfVirkestoff &, FestUuidList &festUuidList, std::vector<FestUuid> &idblock,
                    std::string &strblock, std::map<std::string,uint32_t> &cache);
};


#endif //LEGEMFEST_POPPFVIRKESTOFF_H
