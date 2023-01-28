//
// Created by sigsegv on 1/24/23.
//

#ifndef LEGEMFEST_POPPFLEGEMIDDELVIRKESTOFF_H
#define LEGEMFEST_POPPFLEGEMIDDELVIRKESTOFF_H

#include "POppf.h"
#include "PLegemiddelVirkestoff.h"

class OppfLegemiddelVirkestoff;

class POppfLegemiddelVirkestoff : public POppf, public PLegemiddelVirkestoff {
public:
    POppfLegemiddelVirkestoff(const OppfLegemiddelVirkestoff &oppf, std::string &strblock,
                              std::vector<FestUuid> uuidlist, FestUuidList &festUuidList,
                              ValueWithCodesetList &valueWithCodesetList, RefusjonList &refusjonList);
};


#endif //LEGEMFEST_POPPFLEGEMIDDELVIRKESTOFF_H
