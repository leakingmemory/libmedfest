//
// Created by sigsegv on 1/24/23.
//

#ifndef LEGEMFEST_POPPFLEGEMIDDELVIRKESTOFF_H
#define LEGEMFEST_POPPFLEGEMIDDELVIRKESTOFF_H

#include "POppf.h"
#include "PLegemiddelVirkestoff.h"
#include <variant>

class OppfLegemiddelVirkestoff;

class POppfLegemiddelVirkestoff_0_0_0 : public POppf, public PLegemiddelVirkestoff_0_0_0 {
public:
    POppfLegemiddelVirkestoff_0_0_0(const OppfLegemiddelVirkestoff &oppf, std::string &strblock,
                              std::map<std::string,uint32_t> &cache, std::vector<FestUuid> &uuidlist, StringList &,
                              FestUuidList_0_0_0 &, ValueWithCodesetList &valueWithCodesetList, RefusjonList &refusjonList);
    bool operator == (const POppfLegemiddelVirkestoff_0_0_0 &) const;
};

class POppfLegemiddelVirkestoff_0_4_0 : public POppf, public PLegemiddelVirkestoff_0_4_0 {
public:
    POppfLegemiddelVirkestoff_0_4_0(const OppfLegemiddelVirkestoff &oppf, std::string &strblock,
                              std::map<std::string,uint32_t> &cache, std::vector<FestUuid> &uuidlist, StringList &,
                              FestUuidList_0_4_0 &, ValueWithCodesetList &valueWithCodesetList, RefusjonList &refusjonList);
    POppfLegemiddelVirkestoff_0_4_0(const POppfLegemiddelVirkestoff_0_0_0 &);
    bool operator == (const POppfLegemiddelVirkestoff_0_4_0 &) const;
};

class POppfLegemiddelVirkestoff : public POppf, public PLegemiddelVirkestoff {
public:
    POppfLegemiddelVirkestoff(const POppfLegemiddelVirkestoff_0_0_0 &);
    POppfLegemiddelVirkestoff(const POppfLegemiddelVirkestoff_0_4_0 &);
};

#endif //LEGEMFEST_POPPFLEGEMIDDELVIRKESTOFF_H
