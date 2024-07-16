//
// Created by sigsegv on 2/9/23.
//

#ifndef LEGEMFEST_PVARSELSLV_H
#define LEGEMFEST_PVARSELSLV_H

#include "PValueWithCodeset.h"
#include "GenericListStorage.h"
#include "PLenke.h"
#include "PReferanseelement.h"
#include <map>
#include <variant>

class FestDeserializer;
class VarselSlv;
class ValueWithCodesetList;
class FestUuidList_0_4_0;
class FestUuidList_0_0_0;
class PVarselSlv_0_4_0;

class PVarselSlv_0_0_0 {
    friend FestDeserializer;
    friend PVarselSlv_0_4_0;
private:
    PValueWithCodeset type;
    PReferanseelement_0_0_0 referanseelement;
    PLenke lenke;
    GenericListItems32 visningsregel;
    PString overskrift;
    PString varseltekst;
    PString fraDato;
public:
    PVarselSlv_0_0_0(const VarselSlv &, ValueWithCodesetList &, FestUuidList_0_0_0 &, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PVarselSlv_0_0_0 &) const;
};

class PVarselSlv_0_4_0 {
    friend FestDeserializer;
private:
    PValueWithCodeset type;
    PReferanseelement_0_4_0 referanseelement;
    PLenke lenke;
    GenericListItems32 visningsregel;
    PString overskrift;
    PString varseltekst;
    PString fraDato;
public:
    PVarselSlv_0_4_0(const VarselSlv &, ValueWithCodesetList &, FestUuidList_0_4_0 &, std::string &strblock, std::map<std::string,uint32_t> &cache);
    PVarselSlv_0_4_0(const PVarselSlv_0_0_0 &);
    bool operator == (const PVarselSlv_0_4_0 &) const;
};

class PVarselSlv : public std::variant<PVarselSlv_0_0_0,PVarselSlv_0_4_0> {
public:
    PVarselSlv(const PVarselSlv_0_0_0 &);
    PVarselSlv(const PVarselSlv_0_4_0 &);
};

#endif //LEGEMFEST_PVARSELSLV_H
