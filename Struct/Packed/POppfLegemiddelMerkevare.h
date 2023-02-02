//
// Created by sigsegv on 1/13/23.
//

#ifndef LEGEMFEST_POPPFLEGEMIDDELMERKEVARE_H
#define LEGEMFEST_POPPFLEGEMIDDELMERKEVARE_H

#include "POppf.h"
#include "PLegemiddelMerkevare.h"

class OppfLegemiddelMerkevare;

class POppfLegemiddelMerkevare : public POppf, public PLegemiddelMerkevare {
public:
    POppfLegemiddelMerkevare(const OppfLegemiddelMerkevare &oppf, std::string &strblock,
                             std::map<std::string,uint32_t> &cache, std::vector<FestUuid> &festidblock,
                             FestUuidList &festUuidList, ValueWithCodesetList &valueWithCodesetList,
                             ReseptgyldighetList &reseptgyldighetList);
};


#endif //LEGEMFEST_POPPFLEGEMIDDELMERKEVARE_H
