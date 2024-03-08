//
// Created by sigsegv on 1/18/23.
//

#include <Struct/Packed/PPakningsinfo.h>
#include <Struct/Decoded/Pakningsinfo.h>

PPakningsinfo::PPakningsinfo(const Pakningsinfo &pakningsinfo, std::vector<FestUuid> &uuidblock,
                             PakningskomponentList &pakningskomponentList, std::string &strblock,
                             std::map<std::string,uint32_t> &cache) :
        merkevareId(pakningsinfo.GetMerkevareId(), uuidblock),
        pakningsstr(pakningsinfo.GetPakningsstr(), strblock, cache),
        enhetPakning(pakningsinfo.GetEnhetPakning(), strblock, cache),
        pakningstype(pakningsinfo.GetPakningstype(), strblock, cache),
        ddd(pakningsinfo.GetDDD(), strblock, cache),
        mengde(pakningsinfo.GetMengde(), strblock, cache),
        pakningskomponent(),
        statistikkfaktor(pakningsinfo.GetStatistikkfaktor()),
        antall(pakningsinfo.GetAntall()),
        multippel(pakningsinfo.GetMultippel()){
    {
        std::vector<PPakningskomponent> list{};
        for (const auto &p : pakningsinfo.GetPakningskomponent()) {
            list.emplace_back(p, strblock, cache);
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