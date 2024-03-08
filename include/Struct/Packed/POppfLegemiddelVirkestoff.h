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
                              std::map<std::string,uint32_t> &cache, std::vector<FestUuid> uuidlist, StringList &,
                              FestUuidList &, ValueWithCodesetList &valueWithCodesetList, RefusjonList &refusjonList);
    bool operator == (const POppfLegemiddelVirkestoff &) const;
};


#endif //LEGEMFEST_POPPFLEGEMIDDELVIRKESTOFF_H
