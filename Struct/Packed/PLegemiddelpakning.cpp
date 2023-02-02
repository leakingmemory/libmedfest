//
// Created by sigsegv on 1/18/23.
//

#include "PLegemiddelpakning.h"
#include "PPakningsinfo.h"
#include "PPrisVare.h"
#include "PakningsinfoList.h"
#include "PrisVareList.h"
#include "../Decoded/Legemiddelpakning.h"

PLegemiddelpakning::PLegemiddelpakning(const Legemiddelpakning &legemiddelpakning,
                                       PakningskomponentList &pakningskomponentList, PakningsinfoList &pakningsinfoList,
                                       PrisVareList &prisVareList, StringList &stringList, FestUuidList &festUuidList,
                                       std::vector<FestUuid> &uuidblock, std::string &strblock,
                                       std::map<std::string,uint32_t> &cache) :
        PLegemiddelCore(legemiddelpakning, strblock, cache, festUuidList),
        id(legemiddelpakning.GetId(), uuidblock),
        varenr(legemiddelpakning.GetVarenr(), strblock, cache),
        ean(legemiddelpakning.GetEan(), strblock, cache),
        oppbevaring(legemiddelpakning.GetOppbevaring(), strblock, cache),
        pakningsinfo(),
        prisVare(),
        markedsforingsinfo(legemiddelpakning.GetMarkedsforingsinfo(), strblock, cache),
        refusjon(legemiddelpakning.GetRefusjon(), stringList, strblock, cache),
        pakningByttegruppe(legemiddelpakning.GetPakningByttegruppe(), uuidblock, strblock, cache),
        preparatomtaleavsnitt(legemiddelpakning.GetPreparatomtaleavsnitt(), strblock, cache),
        ikkeKonservering(legemiddelpakning.GetIkkeKonservering())
{
    {
        std::vector<PPakningsinfo> list{};
        for (const auto &p : legemiddelpakning.GetPakningsinfo()) {
            list.emplace_back(p, uuidblock, pakningskomponentList, strblock, cache);
        }
        pakningsinfo = pakningsinfoList.StoreList(list);
    }
    {
        std::vector<PPrisVare> list{};
        for (const auto &p : legemiddelpakning.GetPrisVare()) {
            list.emplace_back(p, strblock, cache);
        }
        prisVare = prisVareList.StoreList(list);
    }
}