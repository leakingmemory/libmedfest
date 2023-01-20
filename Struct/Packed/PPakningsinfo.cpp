//
// Created by sigsegv on 1/18/23.
//

#include "PPakningsinfo.h"
#include "../Decoded/Pakningsinfo.h"

PPakningsinfo::PPakningsinfo(const Pakningsinfo &pakningsinfo, std::vector<FestUuid> &uuidblock,
                             PakningskomponentList &pakningskomponentList, std::string &strblock) :
        merkevareId(pakningsinfo.GetMerkevareId(), uuidblock),
        pakningsstr(pakningsinfo.GetPakningsstr(), strblock),
        enhetPakning(pakningsinfo.GetEnhetPakning(), strblock),
        pakningstype(pakningsinfo.GetPakningstype(), strblock),
        ddd(pakningsinfo.GetDDD(), strblock),
        mengde(pakningsinfo.GetMengde(), strblock),
        pakningskomponent(),
        statistikkfaktor(pakningsinfo.GetStatistikkfaktor()),
        antall(pakningsinfo.GetAntall()),
        multippel(pakningsinfo.GetMultippel()){
    {
        std::vector<PPakningskomponent> list{};
        for (const auto &p : pakningsinfo.GetPakningskomponent()) {
            list.emplace_back(p, strblock);
        }
        pakningskomponent = pakningskomponentList.StoreList(list);
    }
}

bool PPakningsinfo::operator==(const PPakningsinfo &other) const {
    return  merkevareId == other.merkevareId && pakningsstr == other.pakningsstr &&
            enhetPakning == other.enhetPakning && pakningstype == other.pakningstype &&
            ddd == other.ddd && mengde == other.mengde &&
            pakningskomponent == other.pakningskomponent && statistikkfaktor == other.statistikkfaktor &&
            antall == other.antall && multippel == other.multippel;
}