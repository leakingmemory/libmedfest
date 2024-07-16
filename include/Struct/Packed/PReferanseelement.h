//
// Created by sigsegv on 2/9/23.
//

#ifndef LEGEMFEST_PREFERANSEELEMENT_H
#define LEGEMFEST_PREFERANSEELEMENT_H

#include "PValueWithDistinguishedName.h"
#include "GenericListStorage.h"
#include <variant>

class FestDeserializer;
class Referanseelement;
class FestUuidList_0_0_0;
class FestUuidList_0_4_0;
class PReferanseelement_0_4_0;

class PReferanseelement_0_0_0 {
    friend FestDeserializer;
    friend PReferanseelement_0_4_0;
private:
    PValueWithDistinguishedName klasse;
    GenericListItems32 refs;
public:
    PReferanseelement_0_0_0(const Referanseelement &, FestUuidList_0_0_0 &, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PReferanseelement_0_0_0 &) const;
};

class PReferanseelement_0_4_0 {
    friend FestDeserializer;
private:
    PValueWithDistinguishedName klasse;
    GenericListItems64 refs;
public:
    PReferanseelement_0_4_0(const Referanseelement &, FestUuidList_0_4_0 &, std::string &strblock, std::map<std::string,uint32_t> &cache);
    PReferanseelement_0_4_0(const PReferanseelement_0_0_0 &);
    bool operator == (const PReferanseelement_0_4_0 &) const;
};

class PReferanseelement : public std::variant<PReferanseelement_0_0_0,PReferanseelement_0_4_0> {
public:
    PReferanseelement(const PReferanseelement_0_0_0 &);
    PReferanseelement(const PReferanseelement_0_4_0 &);
};

#endif //LEGEMFEST_PREFERANSEELEMENT_H
