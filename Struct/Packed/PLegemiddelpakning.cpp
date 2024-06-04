//
// Created by sigsegv on 1/18/23.
//

#include <Struct/Packed/PLegemiddelpakning.h>
#include <Struct/Packed/PPakningsinfo.h>
#include <Struct/Packed/PPrisVare.h>
#include <Struct/Packed/PakningsinfoList.h>
#include <Struct/Packed/PrisVareList.h>
#include <Struct/Decoded/Legemiddelpakning.h>

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

bool PLegemiddelpakning::operator==(const PLegemiddelpakning &other) const {
    return id == other.id &&
        static_cast<PLegemiddelCore>(*this) == static_cast<PLegemiddelCore>(other) &&
        preparattype == other.preparattype &&
        varenr == other.varenr &&
        ean == other.ean &&
        oppbevaring == other.oppbevaring &&
        pakningsinfo == other.pakningsinfo &&
        prisVare == other.prisVare &&
        markedsforingsinfo == other.markedsforingsinfo &&
        refusjon == other.refusjon &&
        pakningByttegruppe == other.pakningByttegruppe &&
        preparatomtaleavsnitt == other.preparatomtaleavsnitt &&
        ikkeKonservering == other.ikkeKonservering;
}

PValueWithDistinguishedName PLegemiddelpakning::GetPreparattype() const {
    return preparattype;
}
PFestId PLegemiddelpakning::GetId() const {
    return id;
}
PString PLegemiddelpakning::GetVarenr() const {
    return varenr;
}
PString PLegemiddelpakning::GetEan() const {
    return ean;
}
PValueWithDistinguishedName PLegemiddelpakning::GetOppbevaring() const {
    return oppbevaring;
}
GenericListItems32 PLegemiddelpakning::GetPakningsinfo() const {
    return pakningsinfo;
}
GenericListItems32 PLegemiddelpakning::GetPrisVare() const {
    return prisVare;
}
PMarkedsforingsinfo PLegemiddelpakning::GetMarkedsforingsinfo() const {
    return markedsforingsinfo;
}
PRefusjon PLegemiddelpakning::GetRefusjon() const {
    return refusjon;
}
PPakningByttegruppe PLegemiddelpakning::GetPakningByttegruppe() const {
    return pakningByttegruppe;
}
PPreparatomtaleavsnitt PLegemiddelpakning::GetPreparatomtaleavsnitt() const {
    return preparatomtaleavsnitt;
}
bool PLegemiddelpakning::GetIkkeKonservering() const {
    return ikkeKonservering;
}
