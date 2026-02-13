//
// Created by sigsegv on 2/10/23.
//

#ifndef LEGEMFEST_POPPFBYTTEGRUPPE_H
#define LEGEMFEST_POPPFBYTTEGRUPPE_H

#include "POppf.h"
#include "PByttegruppe.h"
#include <variant>

class FestDeserializer;
class OppfByttegruppe;

class POppfByttegruppe_0_0_0 : public POppf, public PByttegruppe_0_0_0 {
    friend FestDeserializer;
public:
    POppfByttegruppe_0_0_0(const OppfByttegruppe &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    ~POppfByttegruppe_0_0_0();
    bool operator == (const POppfByttegruppe_0_0_0 &) const;
};

class POppfByttegruppe_1_5_0 : public POppf, public PByttegruppe_1_5_0 {
    friend FestDeserializer;
public:
    POppfByttegruppe_1_5_0(const OppfByttegruppe &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    POppfByttegruppe_1_5_0(const POppfByttegruppe_0_0_0 &);
    ~POppfByttegruppe_1_5_0();
    bool operator == (const POppfByttegruppe_1_5_0 &) const;
};

class POppfByttegruppe : public POppf, public PByttegruppe {
public:
    POppfByttegruppe(const POppfByttegruppe_0_0_0 &poppf) : POppf(poppf), PByttegruppe(poppf) {
    }
    POppfByttegruppe(const POppfByttegruppe_1_5_0 &poppf) : POppf(poppf), PByttegruppe(poppf) {
    }
    ~POppfByttegruppe();
    bool operator == (const POppfByttegruppe &) const;
};


#endif //LEGEMFEST_POPPFBYTTEGRUPPE_H
