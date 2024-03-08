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

class FestDeserializer;
class VarselSlv;
class ValueWithCodesetList;
class FestUuidList;

class PVarselSlv {
    friend FestDeserializer;
private:
    PValueWithCodeset type;
    PReferanseelement referanseelement;
    PLenke lenke;
    GenericListItems visningsregel;
    PString overskrift;
    PString varseltekst;
    PString fraDato;
public:
    PVarselSlv(const VarselSlv &, ValueWithCodesetList &, FestUuidList &, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PVarselSlv &) const;
};


#endif //LEGEMFEST_PVARSELSLV_H
