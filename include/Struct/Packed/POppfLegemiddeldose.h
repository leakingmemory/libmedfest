//
// Created by sigsegv on 2/1/23.
//

#ifndef LEGEMFEST_POPPFLEGEMIDDELDOSE_H
#define LEGEMFEST_POPPFLEGEMIDDELDOSE_H

#include "POppf.h"
#include "PLegemiddeldose.h"
#include <variant>

class OppfLegemiddeldose;

class POppfLegemiddeldose_0_0_0 : public POppf, public PLegemiddeldose_0_0_0 {
public:
    POppfLegemiddeldose_0_0_0(const OppfLegemiddeldose &, PakningskomponentInfoList &, FestUuidList_0_0_0 &,
                        std::vector<FestUuid> &, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const POppfLegemiddeldose_0_0_0 &) const;
};

class POppfLegemiddeldose_0_4_0 : public POppf, public PLegemiddeldose_0_4_0 {
public:
    POppfLegemiddeldose_0_4_0(const OppfLegemiddeldose &, PakningskomponentInfoList &, FestUuidList_0_4_0 &,
                        std::vector<FestUuid> &, std::string &strblock, std::map<std::string,uint32_t> &cache);
    POppfLegemiddeldose_0_4_0(const POppfLegemiddeldose_0_0_0 &);
    bool operator == (const POppfLegemiddeldose_0_4_0 &) const;
};

class POppfLegemiddeldose : public POppf, public PLegemiddeldose {
public:
    POppfLegemiddeldose(const POppfLegemiddeldose_0_0_0 &);
    POppfLegemiddeldose(const POppfLegemiddeldose_0_4_0 &);
};

#endif //LEGEMFEST_POPPFLEGEMIDDELDOSE_H
