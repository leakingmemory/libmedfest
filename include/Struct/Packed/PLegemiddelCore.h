//
// Created by sigsegv on 1/11/23.
//

#ifndef LEGEMFEST_PLEGEMIDDELCORE_H
#define LEGEMFEST_PLEGEMIDDELCORE_H

#include "PValueWithCodeset.h"
#include "GenericListStorage.h"
#include <variant>

class FestDeserializer;
class LegemiddelCore;
class FestUuidList_0_0_0;
class FestUuidList_0_4_0;
class PLegemiddelCore_0_4_0;

class PLegemiddelCore_0_0_0 {
    friend FestDeserializer;
    friend PLegemiddelCore_0_4_0;
private:
    PValueWithCodeset atc;
    PString navnFormStyrke;
    PValueWithDistinguishedName reseptgruppe;
    PValueWithCodeset legemiddelformKort;
    GenericListItems32 refVilkar;
    PValueWithDistinguishedName typeSoknadSlv;
    PValueWithCodeset svartTrekant;
    uint8_t opioidsoknad : 2;
public:
    PLegemiddelCore_0_0_0(const LegemiddelCore &legemiddelCore, std::string &strblock, std::map<std::string,uint32_t> &cache, FestUuidList_0_0_0 &festUuidList);
    bool operator == (const PLegemiddelCore_0_0_0 &) const;
    [[nodiscard]] PString GetNavnFormStyrke() const;
    [[nodiscard]] PValueWithDistinguishedName GetReseptgruppe() const;
    [[nodiscard]] PValueWithCodeset GetLegemiddelformKort() const;
    [[nodiscard]] GenericListItems32 GetRefVilkar() const;
    [[nodiscard]] PValueWithDistinguishedName GetTypeSoknadSlv() const;
    [[nodiscard]] PValueWithCodeset GetSvartTrekant() const;
    uint8_t GetOpioidsoknad() const;
};

class PLegemiddelCore_0_4_0 {
    friend FestDeserializer;
private:
    PValueWithCodeset atc;
    PString navnFormStyrke;
    PValueWithDistinguishedName reseptgruppe;
    PValueWithCodeset legemiddelformKort;
    GenericListItems64 refVilkar;
    PValueWithDistinguishedName typeSoknadSlv;
    PValueWithCodeset svartTrekant;
    uint8_t opioidsoknad : 2;
public:
    PLegemiddelCore_0_4_0(const LegemiddelCore &legemiddelCore, std::string &strblock, std::map<std::string,uint32_t> &cache, FestUuidList_0_4_0 &festUuidList);
    PLegemiddelCore_0_4_0(const PLegemiddelCore_0_0_0 &);
    bool operator == (const PLegemiddelCore_0_4_0 &) const;
    [[nodiscard]] PString GetNavnFormStyrke() const;
    [[nodiscard]] PValueWithDistinguishedName GetReseptgruppe() const;
    [[nodiscard]] PValueWithCodeset GetLegemiddelformKort() const;
    [[nodiscard]] GenericListItems64 GetRefVilkar() const;
    [[nodiscard]] PValueWithDistinguishedName GetTypeSoknadSlv() const;
    [[nodiscard]] PValueWithCodeset GetSvartTrekant() const;
    uint8_t GetOpioidsoknad() const;
};

class PLegemiddelCore : public std::variant<PLegemiddelCore_0_0_0,PLegemiddelCore_0_4_0> {
public:
    PLegemiddelCore(const PLegemiddelCore_0_0_0 &);
    PLegemiddelCore(const PLegemiddelCore_0_4_0 &);
    [[nodiscard]] PString GetNavnFormStyrke() const;
    [[nodiscard]] PValueWithDistinguishedName GetReseptgruppe() const;
    [[nodiscard]] PValueWithCodeset GetLegemiddelformKort() const;
    [[nodiscard]] std::variant<GenericListItems32, GenericListItems64> GetRefVilkar() const;
    [[nodiscard]] PValueWithDistinguishedName GetTypeSoknadSlv() const;
    [[nodiscard]] PValueWithCodeset GetSvartTrekant() const;
    uint8_t GetOpioidsoknad() const;
};

#endif //LEGEMFEST_PLEGEMIDDELCORE_H
