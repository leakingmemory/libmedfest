//
// Created by sigsegv on 2/12/23.
//

#ifndef LEGEMFEST_POPPFINTERAKSJON_H
#define LEGEMFEST_POPPFINTERAKSJON_H

#include "POppf.h"
#include "PInteraksjon.h"

class FestDeserializer;
class OppfInteraksjon;

class POppfInteraksjon : public POppf, public PInteraksjon {
    friend FestDeserializer;
public:
    POppfInteraksjon(const OppfInteraksjon &, ReferanseList &, SubstansgruppeList &, SubstansList &, ValueWithCodesetList &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
};


#endif //LEGEMFEST_POPPFINTERAKSJON_H
