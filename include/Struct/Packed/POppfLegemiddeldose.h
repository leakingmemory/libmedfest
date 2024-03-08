//
// Created by sigsegv on 2/1/23.
//

#ifndef LEGEMFEST_POPPFLEGEMIDDELDOSE_H
#define LEGEMFEST_POPPFLEGEMIDDELDOSE_H

#include "POppf.h"
#include "PLegemiddeldose.h"

class OppfLegemiddeldose;

class POppfLegemiddeldose : public POppf, public PLegemiddeldose {
public:
    POppfLegemiddeldose(const OppfLegemiddeldose &, PakningskomponentInfoList &, FestUuidList &,
                        std::vector<FestUuid> &, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const POppfLegemiddeldose &) const;
};


#endif //LEGEMFEST_POPPFLEGEMIDDELDOSE_H
