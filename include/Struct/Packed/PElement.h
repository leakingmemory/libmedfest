//
// Created by sigsegv on 2/5/23.
//

#ifndef LEGEMFEST_PELEMENT_H
#define LEGEMFEST_PELEMENT_H

#include "PTerm.h"
#include "PFestId.h"
#include "GenericListStorage.h"

class FestDeserializer;
class Element;
class TermList;

class PElement_0_0_0 : public PTerm {
    friend FestDeserializer;
private:
    PString id;
    PString kode;
public:
    PElement_0_0_0(const Element &, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PElement_0_0_0 &other) const;
};

class PElement_0_3_0 {
    friend FestDeserializer;
private:
    PString id;
    PString kode;
    GenericListItems64 term;
public:
    PElement_0_3_0(const Element &, TermList &, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PElement_0_3_0 &other) const;
};

#endif //LEGEMFEST_PELEMENT_H
