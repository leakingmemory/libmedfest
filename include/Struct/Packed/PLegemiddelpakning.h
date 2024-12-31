//
// Created by sigsegv on 1/18/23.
//

#ifndef LEGEMFEST_PLEGEMIDDELPAKNING_H
#define LEGEMFEST_PLEGEMIDDELPAKNING_H

#include "PLegemiddelCore.h"
#include "PFestId.h"
#include "PPreparatomtaleavsnitt.h"
#include "PMarkedsforingsinfo.h"
#include "PRefusjon.h"
#include "PPakningByttegruppe.h"
#include <variant>

class FestDeserializer;
class Legemiddelpakning;
class PakningskomponentList;
class PakningsinfoList;
class PrisVareList;
class FestUuidList;
class StringList;
class RefusjonList;
class PLegemiddelpakning_0_4_0;
class PLegemiddelpakning_1_3_0;

class PLegemiddelpakning_0_0_0 : public PLegemiddelCore_0_0_0 {
    friend FestDeserializer;
    friend PLegemiddelpakning_0_4_0;
    friend PLegemiddelpakning_1_3_0;
private:
    PValueWithDistinguishedName preparattype;
    PFestId id;
    PString varenr;
    PString ean;
    PValueWithDistinguishedName oppbevaring;
    GenericListItems32 pakningsinfo;
    GenericListItems32 prisVare;
    PMarkedsforingsinfo markedsforingsinfo;
    PRefusjon refusjon;
    PPakningByttegruppe pakningByttegruppe;
    PPreparatomtaleavsnitt preparatomtaleavsnitt;
    bool ikkeKonservering : 1;
public:
    PLegemiddelpakning_0_0_0(const Legemiddelpakning &, PakningskomponentList &pakningskomponentList,
                       PakningsinfoList &pakningsinfoList, PrisVareList &prisVareList, StringList &, FestUuidList_0_0_0 &,
                       std::vector<FestUuid> &uuidblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PLegemiddelpakning_0_0_0 &) const;
    PValueWithDistinguishedName GetPreparattype() const;
    PFestId GetId() const;
    PString GetVarenr() const;
    PString GetEan() const;
    PValueWithDistinguishedName GetOppbevaring() const;
    GenericListItems32 GetPakningsinfo() const;
    GenericListItems32 GetPrisVare() const;
    PMarkedsforingsinfo GetMarkedsforingsinfo() const;
    PRefusjon GetRefusjon() const;
    PPakningByttegruppe GetPakningByttegruppe() const;
    PPreparatomtaleavsnitt GetPreparatomtaleavsnitt() const;
    bool GetIkkeKonservering() const;
};

class PLegemiddelpakning_0_4_0 : public PLegemiddelCore_0_4_0 {
    friend FestDeserializer;
    friend PLegemiddelpakning_1_3_0;
private:
    PValueWithDistinguishedName preparattype;
    PFestId id;
    PString varenr;
    PString ean;
    PValueWithDistinguishedName oppbevaring;
    GenericListItems32 pakningsinfo;
    GenericListItems32 prisVare;
    PMarkedsforingsinfo markedsforingsinfo;
    PRefusjon refusjon;
    PPakningByttegruppe pakningByttegruppe;
    PPreparatomtaleavsnitt preparatomtaleavsnitt;
    bool ikkeKonservering : 1;
public:
    PLegemiddelpakning_0_4_0(const Legemiddelpakning &, PakningskomponentList &pakningskomponentList,
                       PakningsinfoList &pakningsinfoList, PrisVareList &prisVareList, StringList &, FestUuidList_0_4_0 &,
                       std::vector<FestUuid> &uuidblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    PLegemiddelpakning_0_4_0(const PLegemiddelpakning_0_0_0 &);
    bool operator == (const PLegemiddelpakning_0_4_0 &) const;
    PValueWithDistinguishedName GetPreparattype() const;
    PFestId GetId() const;
    PString GetVarenr() const;
    PString GetEan() const;
    PValueWithDistinguishedName GetOppbevaring() const;
    GenericListItems32 GetPakningsinfo() const;
    GenericListItems32 GetPrisVare() const;
    PMarkedsforingsinfo GetMarkedsforingsinfo() const;
    PRefusjon GetRefusjon() const;
    PPakningByttegruppe GetPakningByttegruppe() const;
    PPreparatomtaleavsnitt GetPreparatomtaleavsnitt() const;
    bool GetIkkeKonservering() const;
};

class PLegemiddelpakning_1_3_0 : public PLegemiddelCore_0_4_0 {
    friend FestDeserializer;
private:
    PValueWithDistinguishedName preparattype;
    PFestId id;
    PString varenr;
    PString ean;
    PValueWithDistinguishedName oppbevaring;
    GenericListItems32 pakningsinfo;
    GenericListItems32 prisVare;
    PMarkedsforingsinfo markedsforingsinfo;
    GenericListItems32 refusjon;
    PPakningByttegruppe pakningByttegruppe;
    PPreparatomtaleavsnitt preparatomtaleavsnitt;
    bool ikkeKonservering : 1;
public:
    PLegemiddelpakning_1_3_0(const Legemiddelpakning &, PakningskomponentList &pakningskomponentList,
                             PakningsinfoList &pakningsinfoList, PrisVareList &prisVareList, StringList &, FestUuidList_0_4_0 &,
                             std::vector<FestUuid> &uuidblock, std::string &strblock, std::map<std::string,uint32_t> &cache, RefusjonList &refusjonList);
    PLegemiddelpakning_1_3_0(const PLegemiddelpakning_0_4_0 &, RefusjonList &refusjonList);
    PLegemiddelpakning_1_3_0(const PLegemiddelpakning_0_0_0 &, RefusjonList &refusjonList);
    bool operator == (const PLegemiddelpakning_1_3_0 &) const;
    PValueWithDistinguishedName GetPreparattype() const;
    PFestId GetId() const;
    PString GetVarenr() const;
    PString GetEan() const;
    PValueWithDistinguishedName GetOppbevaring() const;
    GenericListItems32 GetPakningsinfo() const;
    GenericListItems32 GetPrisVare() const;
    PMarkedsforingsinfo GetMarkedsforingsinfo() const;
    GenericListItems32 GetRefusjon() const;
    PPakningByttegruppe GetPakningByttegruppe() const;
    PPreparatomtaleavsnitt GetPreparatomtaleavsnitt() const;
    bool GetIkkeKonservering() const;
};

class PLegemiddelpakning : public PLegemiddelCore, public std::variant<PLegemiddelpakning_0_0_0,PLegemiddelpakning_0_4_0,PLegemiddelpakning_1_3_0> {
public:
    PLegemiddelpakning(const PLegemiddelpakning_0_0_0 &);
    PLegemiddelpakning(const PLegemiddelpakning_0_4_0 &);
    PLegemiddelpakning(const PLegemiddelpakning_1_3_0 &);
    PValueWithDistinguishedName GetPreparattype() const;
    PFestId GetId() const;
    PString GetVarenr() const;
    PString GetEan() const;
    PValueWithDistinguishedName GetOppbevaring() const;
    GenericListItems32 GetPakningsinfo() const;
    GenericListItems32 GetPrisVare() const;
    PMarkedsforingsinfo GetMarkedsforingsinfo() const;
    PPakningByttegruppe GetPakningByttegruppe() const;
    PPreparatomtaleavsnitt GetPreparatomtaleavsnitt() const;
    bool GetIkkeKonservering() const;
};

#endif //LEGEMFEST_PLEGEMIDDELPAKNING_H
