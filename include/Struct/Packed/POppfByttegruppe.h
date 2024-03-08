//
// Created by sigsegv on 2/10/23.
//

#ifndef LEGEMFEST_POPPFBYTTEGRUPPE_H
#define LEGEMFEST_POPPFBYTTEGRUPPE_H

#include "POppf.h"
#include "PByttegruppe.h"

class FestDeserializer;
class OppfByttegruppe;

class POppfByttegruppe : public POppf, public PByttegruppe {
    friend FestDeserializer;
public:
    POppfByttegruppe(const OppfByttegruppe &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const POppfByttegruppe &) const;
};


#endif //LEGEMFEST_POPPFBYTTEGRUPPE_H
