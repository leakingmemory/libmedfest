//
// Created by sigsegv on 2/2/23.
//

#ifndef LEGEMFEST_POPPFVIRKESTOFFMEDSTYRKE_H
#define LEGEMFEST_POPPFVIRKESTOFFMEDSTYRKE_H

#include "POppf.h"
#include "PVirkestoffMedStyrke.h"

class FestDeserializer;
class OppfVirkestoffMedStyrke;

class POppfVirkestoffMedStyrke : public POppf, public PVirkestoffMedStyrke {
public:
    POppfVirkestoffMedStyrke(const OppfVirkestoffMedStyrke &, std::vector<FestUuid> &uuidblock, std::string &strblock,
                             std::map<std::string,uint32_t> &cache);
};


#endif //LEGEMFEST_POPPFVIRKESTOFFMEDSTYRKE_H
