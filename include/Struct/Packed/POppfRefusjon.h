//
// Created by sigsegv on 2/6/23.
//

#ifndef LEGEMFEST_POPPFREFUSJON_H
#define LEGEMFEST_POPPFREFUSJON_H

#include "POppf.h"
#include "PRefusjonshjemmel.h"

class FestDeserializer;
class OppfRefusjon;
class FestUuidList;

class POppfRefusjon : public POppf, public PRefusjonshjemmel {
    friend FestDeserializer;
public:
    POppfRefusjon(const OppfRefusjon &, RefusjonskodeList_0_0_0 &, RefusjonskodeList_0_1_0 &, RefusjonskodeList_1_2_0 &, RefRefusjonsvilkarList_0_0_0 &, RefRefusjonsvilkarList_1_2_0 &, StringList &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    POppfRefusjon(const OppfRefusjon &, RefusjonskodeList_0_1_0 &, RefusjonskodeList_1_2_0 &, RefRefusjonsvilkarList_0_0_0 &, RefRefusjonsvilkarList_1_2_0 &, StringList &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const POppfRefusjon &) const;
};


#endif //LEGEMFEST_POPPFREFUSJON_H
