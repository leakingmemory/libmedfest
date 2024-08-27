//
// Created by sigsegv on 2/5/23.
//

#ifndef LEGEMFEST_PREFREFUSJONSVILKAR_H
#define LEGEMFEST_PREFREFUSJONSVILKAR_H

#include "PFestId.h"
#include "PString.h"
#include <map>
#include <variant>

class FestDeserializer;
class RefRefusjonsvilkar;
class PRefRefusjonsvilkar_1_2_0;

class PRefRefusjonsvilkar_0_0_0 {
    friend FestDeserializer;
    friend PRefRefusjonsvilkar_1_2_0;
private:
    PFestId id;
    PString fraDato;
public:
    PRefRefusjonsvilkar_0_0_0(const RefRefusjonsvilkar &, std::vector<FestUuid> &idblock, std::string &strblock,
                        std::map<std::string,uint32_t> &cache);
    bool operator == (const PRefRefusjonsvilkar_0_0_0 &other) const;
};

class PRefRefusjonsvilkar_1_2_0 {
    friend FestDeserializer;
private:
    PFestId id;
    PString fraDato;
    PString tilDato;
public:
    PRefRefusjonsvilkar_1_2_0(const RefRefusjonsvilkar &, std::vector<FestUuid> &idblock, std::string &strblock,
                        std::map<std::string,uint32_t> &cache);
    PRefRefusjonsvilkar_1_2_0(const PRefRefusjonsvilkar_0_0_0 &refRefusjonsvilkar);
    bool operator == (const PRefRefusjonsvilkar_1_2_0 &other) const;
};

class PRefRefusjonsvilkar : public std::variant<PRefRefusjonsvilkar_0_0_0,PRefRefusjonsvilkar_1_2_0> {
public:
    PRefRefusjonsvilkar(const PRefRefusjonsvilkar_0_0_0 &);
    PRefRefusjonsvilkar(const PRefRefusjonsvilkar_1_2_0 &);
    bool operator == (const PRefRefusjonsvilkar &other) const;
};

#endif //LEGEMFEST_PREFREFUSJONSVILKAR_H
