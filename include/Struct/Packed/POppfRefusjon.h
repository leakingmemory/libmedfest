//
// Created by sigsegv on 2/6/23.
//

#ifndef LEGEMFEST_POPPFREFUSJON_H
#define LEGEMFEST_POPPFREFUSJON_H

#include <variant>
#include "POppf.h"
#include "PRefusjonshjemmel.h"

class FestDeserializer;
class OppfRefusjon;
class FestUuidList;
class POppfRefusjon_1_4_0;

class POppfRefusjon_0_0_0 : public POppf, public PRefusjonshjemmel_0_0_0 {
    friend FestDeserializer;
    friend POppfRefusjon_1_4_0;
public:
    POppfRefusjon_0_0_0(const OppfRefusjon &, RefusjonskodeList_0_0_0 &, RefusjonskodeList_0_1_0 &, RefusjonskodeList_1_2_0 &, RefRefusjonsvilkarList_0_0_0 &, RefRefusjonsvilkarList_1_2_0 &, StringList &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    POppfRefusjon_0_0_0(const OppfRefusjon &, RefusjonskodeList_0_1_0 &, RefusjonskodeList_1_2_0 &, RefRefusjonsvilkarList_0_0_0 &, RefRefusjonsvilkarList_1_2_0 &, StringList &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const POppfRefusjon_0_0_0 &) const;
};

class POppfRefusjon_1_4_0 : public POppf, public PRefusjonshjemmel_1_4_0 {
    friend FestDeserializer;
public:
    POppfRefusjon_1_4_0(const OppfRefusjon &, RefusjonskodeList_0_0_0 &, RefusjonskodeList_0_1_0 &, RefusjonskodeList_1_2_0 &, RefRefusjonsvilkarList_0_0_0 &, RefRefusjonsvilkarList_1_2_0 &, RefusjonsgruppeList &, StringList &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    POppfRefusjon_1_4_0(const OppfRefusjon &, RefusjonskodeList_0_1_0 &, RefusjonskodeList_1_2_0 &, RefRefusjonsvilkarList_0_0_0 &, RefRefusjonsvilkarList_1_2_0 &, RefusjonsgruppeList &, StringList &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    POppfRefusjon_1_4_0(const POppfRefusjon_0_0_0 &, RefusjonsgruppeList &);
    bool operator == (const POppfRefusjon_1_4_0 &) const;
};

class POppfRefusjon : public std::variant<POppfRefusjon_0_0_0,POppfRefusjon_1_4_0>, public POppf, public PRefusjonshjemmel {
public:
    explicit POppfRefusjon(const POppfRefusjon_0_0_0 &obj);
    explicit POppfRefusjon(POppfRefusjon_0_0_0 &&obj);
    explicit POppfRefusjon(const POppfRefusjon_1_4_0 &obj);
    explicit POppfRefusjon(POppfRefusjon_1_4_0 &&obj);
    bool operator == (const POppfRefusjon &) const;
};

#endif //LEGEMFEST_POPPFREFUSJON_H
