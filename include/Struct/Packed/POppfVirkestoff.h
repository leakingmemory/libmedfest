//
// Created by sigsegv on 2/4/23.
//

#ifndef LEGEMFEST_POPPFVIRKESTOFF_H
#define LEGEMFEST_POPPFVIRKESTOFF_H

#include "POppf.h"
#include "PVirkestoff.h"
#include <variant>

class OppfVirkestoff;

class POppfVirkestoff_0_0_0 : public POppf, public PVirkestoff_0_0_0 {
public:
    POppfVirkestoff_0_0_0(const OppfVirkestoff &, FestUuidList_0_0_0 &festUuidList, std::vector<FestUuid> &idblock,
                    std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const POppfVirkestoff_0_0_0 &) const;
};

class POppfVirkestoff_0_4_0 : public POppf, public PVirkestoff_0_4_0 {
public:
    POppfVirkestoff_0_4_0(const OppfVirkestoff &, FestUuidList_0_4_0 &festUuidList, std::vector<FestUuid> &idblock,
                    std::string &strblock, std::map<std::string,uint32_t> &cache);
    POppfVirkestoff_0_4_0(const POppfVirkestoff_0_0_0 &poppf);
    bool operator == (const POppfVirkestoff_0_4_0 &) const;
};

class POppfVirkestoff : public POppf, public PVirkestoff {
public:
    POppfVirkestoff(const POppfVirkestoff_0_0_0 &);
    POppfVirkestoff(const POppfVirkestoff_0_4_0 &);
};

#endif //LEGEMFEST_POPPFVIRKESTOFF_H
