//
// Created by sigsegv on 12/12/22.
//

#ifndef LEGEMFEST_PAKNINGSINFO_H
#define LEGEMFEST_PAKNINGSINFO_H

#include <string>
#include "EnhetPakning.h"
#include "Pakningstype.h"
#include "DDD.h"

class Pakningsinfo {
private:
    std::string merkevareId;
    std::string pakningsstr;
    EnhetPakning enhetPakning;
    Pakningstype pakningstype;
    std::string mengde;
    DDD ddd;
    int statistikkfaktor;
    int antall;
public:
    Pakningsinfo() : merkevareId(), pakningsstr(), enhetPakning(), pakningstype(), mengde(), ddd(), statistikkfaktor(0),
            antall(0) {}
    Pakningsinfo(const std::string &merkevareId, const std::string &pakningsstr, const EnhetPakning &enhetPakning,
                 const Pakningstype &pakningstype, const std::string &mengde, const DDD &ddd, int statistikkfaktor,
                 int antall) :
            merkevareId(merkevareId), pakningsstr(pakningsstr), enhetPakning(enhetPakning), pakningstype(pakningstype),
            mengde(mengde), ddd(ddd), statistikkfaktor(statistikkfaktor), antall(antall) {}
    [[nodiscard]] std::string GetMerkevareId() const;
    [[nodiscard]] std::string GetPakningsstr() const;
    [[nodiscard]] EnhetPakning GetEnhetPakning() const;
    [[nodiscard]] Pakningstype GetPakningstype() const;
    [[nodiscard]] std::string GetMengde() const;
    [[nodiscard]] DDD GetDDD() const;
    int GetStatistikkfaktor() const;
    int GetAntall() const;
};


#endif //LEGEMFEST_PAKNINGSINFO_H
