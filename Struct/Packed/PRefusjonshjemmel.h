//
// Created by sigsegv on 2/6/23.
//

#ifndef LEGEMFEST_PREFUSJONSHJEMMEL_H
#define LEGEMFEST_PREFUSJONSHJEMMEL_H

#include "PRefusjonsgruppe.h"

class Refusjonshjemmel;

class PRefusjonshjemmel : public PRefusjonsgruppe {
    friend FestDeserializer;
private:
    PValueWithCodeset refusjonshjemmel;
    bool kreverVarekobling : 1;
    bool kreverVedtak : 1;
public:
    PRefusjonshjemmel(const Refusjonshjemmel &, RefusjonskodeList &, RefRefusjonsvilkarList &, StringList &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PRefusjonshjemmel &) const;
};


#endif //LEGEMFEST_PREFUSJONSHJEMMEL_H
