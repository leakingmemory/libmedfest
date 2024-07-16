//
// Created by sigsegv on 2/18/23.
//

#ifndef LEGEMFEST_PFEST_H
#define LEGEMFEST_PFEST_H

#include "GenericListStorage.h"
#include "PString.h"
#include <variant>

class FestDeserializer;
class FestVectors;
class FestData;
class Uint16List_V_0_0_0;
class Uint16List;
class Uint32List;
class PFest_V_0_2_0_or_later;
class PFest_V_0_2_0;
class PFest_V_0_3_0;
class PFest_V_0_4_0;

class PFest_V_0_0_0 {
    friend FestDeserializer;
    friend FestVectors;
    friend PFest_V_0_2_0_or_later;
    friend PFest_V_0_3_0;
    friend PFest_V_0_4_0;
private:
    PString dato;
    GenericListItems32 legemiddelMerkevare;
    GenericListItems32 legemiddelpakning;
    GenericListItems32 legemiddelVirkestoff;
    GenericListItems32 medForbrMatr;
    GenericListItems32 naringsmiddel;
    GenericListItems32 brystprotese;
    GenericListItems32 legemiddeldose;
    GenericListItems32 virkestoffMedStyrke;
    GenericListItems32 virkestoff;
    GenericListItems32 kodeverk;
    GenericListItems32 refusjon;
    GenericListItems32 vilkar;
    GenericListItems32 varselSlv;
    GenericListItems32 byttegruppe;
    GenericListItems32 interaksjon;
    GenericListItems32 interaksjonIkkeVurdert;
    GenericListItems32 strDosering;
    PFest_V_0_0_0() = default;
public:
    PFest_V_0_0_0(const FestData &, Uint16List_V_0_0_0 &uint16LegacyList, std::string &strblock, std::map<std::string,uint32_t> &cache);
};

class PFest_V_0_2_0_or_later {
    friend FestDeserializer;
    friend FestVectors;
    friend PFest_V_0_2_0;
    friend PFest_V_0_3_0;
    friend PFest_V_0_4_0;
private:
    PString dato;
    GenericListItems64 legemiddelMerkevare;
    GenericListItems64 legemiddelpakning;
    GenericListItems64 legemiddelVirkestoff;
    GenericListItems64 medForbrMatr;
    GenericListItems64 naringsmiddel;
    GenericListItems64 brystprotese;
    GenericListItems64 legemiddeldose;
    GenericListItems64 virkestoffMedStyrke;
    GenericListItems64 virkestoff;
    GenericListItems64 kodeverk;
    GenericListItems64 refusjon;
    GenericListItems64 vilkar;
    GenericListItems64 varselSlv;
    GenericListItems64 byttegruppe;
    GenericListItems64 interaksjon;
    GenericListItems64 interaksjonIkkeVurdert;
    GenericListItems64 strDosering;
private:
    PFest_V_0_2_0_or_later() = default;
    PFest_V_0_2_0_or_later(const PFest_V_0_0_0 &legacy);
public:
    PFest_V_0_2_0_or_later(const FestData &, GenericListItems64 legemiddelMerkevare, GenericListItems64 legemiddelpakning, GenericListItems64 legemiddelVirkestoff, GenericListItems64 legemiddeldose, GenericListItems64 kodeverk, Uint16List &uint16NewList, std::string &strblock, std::map<std::string,uint32_t> &cache);
};

class PFest_V_0_2_0 : public PFest_V_0_2_0_or_later {
    friend FestDeserializer;
    friend FestVectors;
private:
    PFest_V_0_2_0(const PFest_V_0_0_0 &legacy);
public:
    PFest_V_0_2_0(const FestData &, Uint16List &uint16NewList, std::string &strblock, std::map<std::string,uint32_t> &cache);
};

class PFest_V_0_3_0 : public PFest_V_0_2_0_or_later {
    friend FestDeserializer;
    friend FestVectors;
private:
    PFest_V_0_3_0(const PFest_V_0_0_0 &legacy, const FestDeserializer &festDeserializer, Uint32List &uint32list);
    PFest_V_0_3_0(const PFest_V_0_2_0 &legacy, const FestDeserializer &festDeserializer, Uint32List &uint32list);
public:
    PFest_V_0_3_0(const FestData &, Uint32List &uint32List, Uint16List &uint16NewList, std::string &strblock, std::map<std::string,uint32_t> &cache);
};

class PFest_V_0_4_0 : public PFest_V_0_2_0_or_later {
    friend FestDeserializer;
    friend FestVectors;
private:
    PFest_V_0_4_0(const PFest_V_0_0_0 &legacy, const FestDeserializer &festDeserializer, Uint32List &uint32list);
    PFest_V_0_4_0(const PFest_V_0_2_0 &legacy, const FestDeserializer &festDeserializer, Uint32List &uint32list);
    PFest_V_0_4_0(const PFest_V_0_3_0 &legacy);
public:
    PFest_V_0_4_0(const FestData &, Uint32List &uint32List, Uint16List &uint16NewList, std::string &strblock, std::map<std::string,uint32_t> &cache);
};

class PFest : public std::variant<PFest_V_0_0_0,PFest_V_0_2_0,PFest_V_0_3_0,PFest_V_0_4_0> {
public:
    PFest(const PFest_V_0_0_0 &);
    PFest(const PFest_V_0_2_0 &);
    PFest(const PFest_V_0_3_0 &);
    PFest(const PFest_V_0_4_0 &);
};

#endif //LEGEMFEST_PFEST_H
