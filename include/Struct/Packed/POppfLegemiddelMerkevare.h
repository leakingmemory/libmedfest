//
// Created by sigsegv on 1/13/23.
//

#ifndef LEGEMFEST_POPPFLEGEMIDDELMERKEVARE_H
#define LEGEMFEST_POPPFLEGEMIDDELMERKEVARE_H

#include "POppf.h"
#include "PLegemiddelMerkevare.h"
#include <variant>

class OppfLegemiddelMerkevare;

class POppfLegemiddelMerkevare_0_0_0 : public POppf, public PLegemiddelMerkevare_0_0_0 {
public:
    POppfLegemiddelMerkevare_0_0_0(const OppfLegemiddelMerkevare &oppf, std::string &strblock,
                             std::map<std::string,uint32_t> &cache, std::vector<FestUuid> &festidblock,
                             FestUuidList_0_0_0 &festUuidList, ValueWithCodesetList &valueWithCodesetList,
                             ReseptgyldighetList &reseptgyldighetList);
    bool operator == (const POppfLegemiddelMerkevare_0_0_0 &) const;
};

class POppfLegemiddelMerkevare_0_4_0 : public POppf, public PLegemiddelMerkevare_0_4_0 {
public:
    POppfLegemiddelMerkevare_0_4_0(const OppfLegemiddelMerkevare &oppf, std::string &strblock,
                             std::map<std::string,uint32_t> &cache, std::vector<FestUuid> &festidblock,
                             FestUuidList_0_4_0 &festUuidList, ValueWithCodesetList &valueWithCodesetList,
                             ReseptgyldighetList &reseptgyldighetList);
    POppfLegemiddelMerkevare_0_4_0(const POppfLegemiddelMerkevare_0_0_0 &);
    bool operator == (const POppfLegemiddelMerkevare_0_4_0 &) const;
};

class POppfLegemiddelMerkevare : public POppf, public PLegemiddelMerkevare {
public:
    POppfLegemiddelMerkevare() = delete;
    POppfLegemiddelMerkevare(const POppfLegemiddelMerkevare_0_0_0 &);
    POppfLegemiddelMerkevare(const POppfLegemiddelMerkevare_0_4_0 &);
};

#endif //LEGEMFEST_POPPFLEGEMIDDELMERKEVARE_H
