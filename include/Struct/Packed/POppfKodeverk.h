//
// Created by sigsegv on 2/5/23.
//

#ifndef LEGEMFEST_POPPFKODEVERK_H
#define LEGEMFEST_POPPFKODEVERK_H

#include "POppf.h"
#include "PInfo.h"
#include "GenericListStorage.h"
#include <variant>

class FestDeserializer;
class OppfKodeverk;
class ElementList_0_0_0;
class ElementList_0_3_0;
class TermList;
class POppfKodeverk_0_3_0;

class POppfKodeverk_0_0_0 : public POppf, public PInfo {
    friend FestDeserializer;
    friend POppfKodeverk_0_3_0;
private:
    GenericListItems32 elements;
public:
    POppfKodeverk_0_0_0(const OppfKodeverk &, ElementList_0_0_0 &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const POppfKodeverk_0_0_0 &) const;
};

class POppfKodeverk_0_3_0 : public POppf, public PInfo {
    friend FestDeserializer;
private:
    GenericListItems64 elements;
public:
    POppfKodeverk_0_3_0(const OppfKodeverk &, ElementList_0_3_0 &, TermList &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    POppfKodeverk_0_3_0(const POppfKodeverk_0_0_0 &, const FestDeserializer &, ElementList_0_3_0 &, TermList &, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const POppfKodeverk_0_3_0 &) const;
};

class POppfKodeverk : public std::variant<POppfKodeverk_0_0_0,POppfKodeverk_0_3_0> {
public:
    POppfKodeverk() = delete;
    explicit POppfKodeverk(const POppfKodeverk_0_0_0 &);
    explicit POppfKodeverk(const POppfKodeverk_0_3_0 &);
};

#endif //LEGEMFEST_POPPFKODEVERK_H
