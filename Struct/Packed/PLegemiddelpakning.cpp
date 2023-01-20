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
                                       PrisVareList &prisVareList, FestUuidList &festUuidList,
                                       std::vector<FestUuid> &uuidblock, std::string &strblock) :
        PLegemiddelCore(legemiddelpakning, strblock, festUuidList),
        id(legemiddelpakning.GetId(), uuidblock),
        varenr(legemiddelpakning.GetVarenr(), strblock),
        ean(legemiddelpakning.GetEan(), strblock),
        oppbevaring(legemiddelpakning.GetOppbevaring(), strblock),
        pakningsinfo(),
        prisVare(),
        markedsforingsinfo(legemiddelpakning.GetMarkedsforingsinfo(), strblock),
        refusjon(legemiddelpakning.GetRefusjon(), uuidblock, strblock),
        pakningByttegruppe(legemiddelpakning.GetPakningByttegruppe(), uuidblock, strblock),
        preparatomtaleavsnitt(legemiddelpakning.GetPreparatomtaleavsnitt(), strblock),
        ikkeKonservering(legemiddelpakning.GetIkkeKonservering())
{
    {
        std::vector<PPakningsinfo> list{};
        for (const auto &p : legemiddelpakning.GetPakningsinfo()) {
            list.emplace_back(p, uuidblock, pakningskomponentList, strblock);
        }
        pakningsinfo = pakningsinfoList.StoreList(list);
    }
    {
        std::vector<PPrisVare> list{};
        for (const auto &p : legemiddelpakning.GetPrisVare()) {
            list.emplace_back(p, strblock);
        }
        prisVare = prisVareList.StoreList(list);
    }
}