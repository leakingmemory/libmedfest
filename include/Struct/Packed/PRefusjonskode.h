//
// Created by sigsegv on 2/6/23.
//

#ifndef LEGEMFEST_PREFUSJONSKODE_H
#define LEGEMFEST_PREFUSJONSKODE_H

#include "PValueWithCodeset.h"
#include "GenericListStorage.h"
#include <variant>

class FestDeserializer;
class Refusjonskode;
class RefRefusjonsvilkarList_0_0_0;
class RefRefusjonsvilkarList_1_2_0;
class StringList;
class FestUuid;

class PRefusjonskode_0_1_0;
class PRefusjonskode_1_2_0;

class PRefusjonskode_0_0_0 {
    friend FestDeserializer;
    friend PRefusjonskode_0_1_0;
    friend PRefusjonskode_1_2_0;
private:
    PValueWithCodeset refusjonskode;
    PString gyldigFraDato;
    PString forskrivesTilDato;
    GenericListItems32 underterm;
    GenericListItems32 refusjonsvilkar;
public:
    explicit PRefusjonskode_0_0_0(const PRefusjonskode_0_1_0 &);
    PRefusjonskode_0_0_0(const Refusjonskode &, RefRefusjonsvilkarList_0_0_0 &, StringList &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator ==(const PRefusjonskode_0_0_0 &other) const;
};

class PRefusjonskode_0_1_0 {
    friend FestDeserializer;
    friend PRefusjonskode_0_0_0;
    friend PRefusjonskode_1_2_0;
private:
    PValueWithCodeset refusjonskode;
    PString gyldigFraDato;
    PString forskrivesTilDato;
    PString utleveresTilDato;
    GenericListItems32 underterm;
    GenericListItems32 refusjonsvilkar;
public:
    explicit PRefusjonskode_0_1_0(const PRefusjonskode_0_0_0 &);
    PRefusjonskode_0_1_0(const Refusjonskode &, RefRefusjonsvilkarList_0_0_0 &, StringList &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator ==(const PRefusjonskode_0_1_0 &other) const;
};

class PRefusjonskode_1_2_0 {
    friend FestDeserializer;
    friend PRefusjonskode_0_0_0;
private:
    PValueWithCodeset refusjonskode;
    PString gyldigFraDato;
    PString forskrivesTilDato;
    PString utleveresTilDato;
    GenericListItems32 underterm;
    GenericListItems32 refusjonsvilkar;
public:
    explicit PRefusjonskode_1_2_0(const PRefusjonskode_0_0_0 &);
    explicit PRefusjonskode_1_2_0(const PRefusjonskode_0_1_0 &);
    PRefusjonskode_1_2_0(const Refusjonskode &, RefRefusjonsvilkarList_1_2_0 &, StringList &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator ==(const PRefusjonskode_1_2_0 &other) const;
};

class PRefusjonskode : public std::variant<PRefusjonskode_0_0_0,PRefusjonskode_0_1_0,PRefusjonskode_1_2_0> {
public:
    PRefusjonskode(const PRefusjonskode_0_0_0 &);
    PRefusjonskode(const PRefusjonskode_0_1_0 &);
    PRefusjonskode(const PRefusjonskode_1_2_0 &);
    bool operator == (const PRefusjonskode &other) const;
};

#endif //LEGEMFEST_PREFUSJONSKODE_H
