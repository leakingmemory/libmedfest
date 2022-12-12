//
// Created by sigsegv on 12/12/22.
//

#ifndef LEGEMFEST_PAKNINGSINFO_H
#define LEGEMFEST_PAKNINGSINFO_H

#include <string>
#include "EnhetPakning.h"
#include "Pakningstype.h"
#include "DDD.h"
#include "Pakningskomponent.h"
#include <vector>

class Pakningsinfo {
private:
    std::string merkevareId;
    std::string pakningsstr;
    EnhetPakning enhetPakning;
    Pakningstype pakningstype;
    std::string mengde;
    DDD ddd;
    std::vector<Pakningskomponent> pakningskomponent;
    double statistikkfaktor;
    int antall;
public:
    Pakningsinfo() : merkevareId(), pakningsstr(), enhetPakning(), pakningstype(), mengde(), ddd(), pakningskomponent(),
            statistikkfaktor(0.0), antall(0) {}
    Pakningsinfo(const std::string &merkevareId, const std::string &pakningsstr, const EnhetPakning &enhetPakning,
                 const Pakningstype &pakningstype, const std::string &mengde, const DDD &ddd,
                 std::vector<Pakningskomponent> pakningskomponent, double statistikkfaktor, int antall) :
            merkevareId(merkevareId), pakningsstr(pakningsstr), enhetPakning(enhetPakning), pakningstype(pakningstype),
            mengde(mengde), ddd(ddd), pakningskomponent(pakningskomponent), statistikkfaktor(statistikkfaktor),
            antall(antall) {}
    [[nodiscard]] std::string GetMerkevareId() const;
    [[nodiscard]] std::string GetPakningsstr() const;
    [[nodiscard]] EnhetPakning GetEnhetPakning() const;
    [[nodiscard]] Pakningstype GetPakningstype() const;
    [[nodiscard]] std::string GetMengde() const;
    [[nodiscard]] DDD GetDDD() const;
    [[nodiscard]] std::vector<Pakningskomponent> GetPakningskomponent() const;
    double GetStatistikkfaktor() const;
    int GetAntall() const;

};


#endif //LEGEMFEST_PAKNINGSINFO_H
