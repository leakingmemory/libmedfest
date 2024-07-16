//
// Created by sigsegv on 1/10/23.
//

#ifndef LEGEMFEST_PLEGEMIDDELMERKEVARE_H
#define LEGEMFEST_PLEGEMIDDELMERKEVARE_H

#include "PValueWithDistinguishedName.h"
#include "PValueWithCodeset.h"
#include "PFestId.h"
#include "PPreparatomtaleavsnitt.h"
#include "PLegemiddel.h"
#include <variant>

class FestDeserializer;
class LegemiddelMerkevare;
class ReseptgyldighetList;
class ValueWithCodesetList;
class FestUuidList_0_0_0;
class FestUuidList_0_4_0;
class PLegemiddelMerkevare_0_4_0;

class PLegemiddelMerkevare_0_0_0 : public PLegemiddel_0_0_0 {
    friend FestDeserializer;
    friend PLegemiddelMerkevare_0_4_0;
private:
    PValueWithCodeset vaksinestandard;
    PValueWithDistinguishedName preparattype;
    PValueWithDistinguishedName smak;
    PString varenavn;
    PString legemiddelformLang;
    PString produsent;
    PString referanseprodukt;
    PFestId id;
    PPreparatomtaleavsnitt preparatomtaleavsnitt;
    GenericListItems32 sortertVirkestoffUtenStyrke;
    GenericListItems32 reseptgyldighet;
    uint8_t varseltrekant : 2;
public:
    PLegemiddelMerkevare_0_0_0(const LegemiddelMerkevare &, std::string &strblock, std::map<std::string,uint32_t> &cache,
                         std::vector<FestUuid> &festidblock, FestUuidList_0_0_0 &festUuidList,
                         ValueWithCodesetList &valueWithCodesetList, ReseptgyldighetList &reseptgyldighetList);
    bool operator == (const PLegemiddelMerkevare_0_0_0 &) const;
    PValueWithCodeset GetVaksinestandard() const;
    PValueWithDistinguishedName GetPreparattype() const;
    PValueWithDistinguishedName GetSmak() const;
    PString GetVarenavn() const;
    PString GetLegemiddelformLang() const;
    PString GetProdusent() const;
    PString GetReferanseprodukt() const;
    PFestId GetId() const;
    PPreparatomtaleavsnitt GetPreparatomtaleavsnitt() const;
    GenericListItems32 GetSortertVirkestoffUtenStyrke() const;
    GenericListItems32 GetReseptgyldighet() const;
    uint8_t GetVarseltrekant() const;
};

class PLegemiddelMerkevare_0_4_0 : public PLegemiddel_0_4_0 {
    friend FestDeserializer;
private:
    PValueWithCodeset vaksinestandard;
    PValueWithDistinguishedName preparattype;
    PValueWithDistinguishedName smak;
    PString varenavn;
    PString legemiddelformLang;
    PString produsent;
    PString referanseprodukt;
    PFestId id;
    PPreparatomtaleavsnitt preparatomtaleavsnitt;
    GenericListItems64 sortertVirkestoffUtenStyrke;
    GenericListItems32 reseptgyldighet;
    uint8_t varseltrekant : 2;
public:
    PLegemiddelMerkevare_0_4_0(const LegemiddelMerkevare &, std::string &strblock, std::map<std::string,uint32_t> &cache,
                         std::vector<FestUuid> &festidblock, FestUuidList_0_4_0 &festUuidList,
                         ValueWithCodesetList &valueWithCodesetList, ReseptgyldighetList &reseptgyldighetList);
    PLegemiddelMerkevare_0_4_0(const PLegemiddelMerkevare_0_0_0 &);
    bool operator == (const PLegemiddelMerkevare_0_4_0 &) const;
    PValueWithCodeset GetVaksinestandard() const;
    PValueWithDistinguishedName GetPreparattype() const;
    PValueWithDistinguishedName GetSmak() const;
    PString GetVarenavn() const;
    PString GetLegemiddelformLang() const;
    PString GetProdusent() const;
    PString GetReferanseprodukt() const;
    PFestId GetId() const;
    PPreparatomtaleavsnitt GetPreparatomtaleavsnitt() const;
    GenericListItems64 GetSortertVirkestoffUtenStyrke() const;
    GenericListItems32 GetReseptgyldighet() const;
    uint8_t GetVarseltrekant() const;
};

class PLegemiddelMerkevare : public PLegemiddel, public std::variant<PLegemiddelMerkevare_0_4_0,PLegemiddelMerkevare_0_0_0> {
public:
    PLegemiddelMerkevare(const PLegemiddelMerkevare_0_4_0 &);
    PLegemiddelMerkevare(const PLegemiddelMerkevare_0_0_0 &);
    PValueWithCodeset GetVaksinestandard() const;
    PValueWithDistinguishedName GetPreparattype() const;
    PValueWithDistinguishedName GetSmak() const;
    PString GetVarenavn() const;
    PString GetLegemiddelformLang() const;
    PString GetProdusent() const;
    PString GetReferanseprodukt() const;
    PFestId GetId() const;
    PPreparatomtaleavsnitt GetPreparatomtaleavsnitt() const;
    std::variant<GenericListItems32, GenericListItems64> GetSortertVirkestoffUtenStyrke() const;
    GenericListItems32 GetReseptgyldighet() const;
    uint8_t GetVarseltrekant() const;
};

#endif //LEGEMFEST_PLEGEMIDDELMERKEVARE_H
