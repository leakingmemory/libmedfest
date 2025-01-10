//
// Created by sigsegv on 2/6/23.
//

#ifndef LEGEMFEST_PREFUSJONSHJEMMEL_H
#define LEGEMFEST_PREFUSJONSHJEMMEL_H

#include <variant>
#include "PRefusjonsgruppe.h"

class Refusjonshjemmel;
class RefusjonsgruppeList;
class PRefusjonshjemmel_1_4_0;

class PRefusjonshjemmel_0_0_0 : public PRefusjonsgruppe {
    friend FestDeserializer;
    friend PRefusjonshjemmel_1_4_0;
private:
    PValueWithCodeset refusjonshjemmel;
    bool kreverVarekobling : 1;
    bool kreverVedtak : 1;
public:
    PRefusjonshjemmel_0_0_0(const Refusjonshjemmel &, RefusjonskodeList_0_0_0 &, RefusjonskodeList_0_1_0 &, RefusjonskodeList_1_2_0 &, RefRefusjonsvilkarList_0_0_0 &, RefRefusjonsvilkarList_1_2_0 &, StringList &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    PRefusjonshjemmel_0_0_0(const Refusjonshjemmel &, RefusjonskodeList_0_1_0 &, RefusjonskodeList_1_2_0 &, RefRefusjonsvilkarList_0_0_0 &, RefRefusjonsvilkarList_1_2_0 &, StringList &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PRefusjonshjemmel_0_0_0 &) const;
};

class PRefusjonshjemmel_1_4_0 {
    friend FestDeserializer;
private:
    PValueWithCodeset refusjonshjemmel;
    GenericListItems64 refusjonsgruppe;
    bool kreverVarekobling : 1;
    bool kreverVedtak : 1;
public:
    PRefusjonshjemmel_1_4_0(const Refusjonshjemmel &, RefusjonskodeList_0_0_0 &, RefusjonskodeList_0_1_0 &, RefusjonskodeList_1_2_0 &, RefRefusjonsvilkarList_0_0_0 &, RefRefusjonsvilkarList_1_2_0 &, RefusjonsgruppeList &, StringList &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    PRefusjonshjemmel_1_4_0(const Refusjonshjemmel &, RefusjonskodeList_0_1_0 &, RefusjonskodeList_1_2_0 &, RefRefusjonsvilkarList_0_0_0 &, RefRefusjonsvilkarList_1_2_0 &, RefusjonsgruppeList &, StringList &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    PRefusjonshjemmel_1_4_0(const PRefusjonshjemmel_0_0_0 &, RefusjonsgruppeList &);
    bool operator == (const PRefusjonshjemmel_1_4_0 &) const;
};

class PRefusjonshjemmel : public std::variant<PRefusjonshjemmel_0_0_0,PRefusjonshjemmel_1_4_0> {
public:
    PRefusjonshjemmel(const PRefusjonshjemmel_0_0_0 &);
    PRefusjonshjemmel(const PRefusjonshjemmel_1_4_0 &);
    bool operator == (const PRefusjonshjemmel &) const;
};

#endif //LEGEMFEST_PREFUSJONSHJEMMEL_H
