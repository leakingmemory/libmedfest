//
// Created by sigsegv on 1/18/23.
//

#include <Struct/Packed/PLegemiddelpakning.h>
#include <Struct/Packed/PPakningsinfo.h>
#include <Struct/Packed/PPrisVare.h>
#include <Struct/Packed/PakningsinfoList.h>
#include <Struct/Packed/PrisVareList.h>
#include <Struct/Packed/RefusjonList.h>
#include <Struct/Decoded/Legemiddelpakning.h>

template <class T> static T Last(const std::vector<T> &v) {
    return v.empty() ? T{} : v.back();
}

PLegemiddelpakning_0_0_0::PLegemiddelpakning_0_0_0(const Legemiddelpakning &legemiddelpakning,
                                       PakningskomponentList &pakningskomponentList, PakningsinfoList &pakningsinfoList,
                                       PrisVareList &prisVareList, StringList &stringList, FestUuidList_0_0_0 &festUuidList,
                                       std::vector<FestUuid> &uuidblock, std::string &strblock,
                                       std::map<std::string,uint32_t> &cache) :
        PLegemiddelCore_0_0_0(legemiddelpakning, strblock, cache, festUuidList),
        id(legemiddelpakning.GetId(), uuidblock),
        varenr(legemiddelpakning.GetVarenr(), strblock, cache),
        ean(legemiddelpakning.GetEan(), strblock, cache),
        oppbevaring(legemiddelpakning.GetOppbevaring(), strblock, cache),
        pakningsinfo(),
        prisVare(),
        markedsforingsinfo(legemiddelpakning.GetMarkedsforingsinfo(), strblock, cache),
        refusjon(Last(legemiddelpakning.GetRefusjonList()), stringList, strblock, cache),
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

bool PLegemiddelpakning_0_0_0::operator==(const PLegemiddelpakning_0_0_0 &other) const {
    return id == other.id &&
        static_cast<PLegemiddelCore_0_0_0>(*this) == static_cast<PLegemiddelCore_0_0_0>(other) &&
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

PValueWithDistinguishedName PLegemiddelpakning_0_0_0::GetPreparattype() const {
    return preparattype;
}
PFestId PLegemiddelpakning_0_0_0::GetId() const {
    return id;
}
PString PLegemiddelpakning_0_0_0::GetVarenr() const {
    return varenr;
}
PString PLegemiddelpakning_0_0_0::GetEan() const {
    return ean;
}
PValueWithDistinguishedName PLegemiddelpakning_0_0_0::GetOppbevaring() const {
    return oppbevaring;
}
GenericListItems32 PLegemiddelpakning_0_0_0::GetPakningsinfo() const {
    return pakningsinfo;
}
GenericListItems32 PLegemiddelpakning_0_0_0::GetPrisVare() const {
    return prisVare;
}
PMarkedsforingsinfo PLegemiddelpakning_0_0_0::GetMarkedsforingsinfo() const {
    return markedsforingsinfo;
}
PRefusjon PLegemiddelpakning_0_0_0::GetRefusjon() const {
    return refusjon;
}
PPakningByttegruppe PLegemiddelpakning_0_0_0::GetPakningByttegruppe() const {
    return pakningByttegruppe;
}
PPreparatomtaleavsnitt PLegemiddelpakning_0_0_0::GetPreparatomtaleavsnitt() const {
    return preparatomtaleavsnitt;
}
bool PLegemiddelpakning_0_0_0::GetIkkeKonservering() const {
    return ikkeKonservering;
}

PLegemiddelpakning_0_4_0::PLegemiddelpakning_0_4_0(const Legemiddelpakning &legemiddelpakning,
                                       PakningskomponentList &pakningskomponentList, PakningsinfoList &pakningsinfoList,
                                       PrisVareList &prisVareList, StringList &stringList, FestUuidList_0_4_0 &festUuidList,
                                       std::vector<FestUuid> &uuidblock, std::string &strblock,
                                       std::map<std::string,uint32_t> &cache) :
        PLegemiddelCore_0_4_0(legemiddelpakning, strblock, cache, festUuidList),
        id(legemiddelpakning.GetId(), uuidblock),
        varenr(legemiddelpakning.GetVarenr(), strblock, cache),
        ean(legemiddelpakning.GetEan(), strblock, cache),
        oppbevaring(legemiddelpakning.GetOppbevaring(), strblock, cache),
        pakningsinfo(),
        prisVare(),
        markedsforingsinfo(legemiddelpakning.GetMarkedsforingsinfo(), strblock, cache),
        refusjon(Last(legemiddelpakning.GetRefusjonList()), stringList, strblock, cache),
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

PLegemiddelpakning_0_4_0::PLegemiddelpakning_0_4_0(const PLegemiddelpakning_0_0_0 &pakning) :
        PLegemiddelCore_0_4_0(pakning),
        id(pakning.id),
        varenr(pakning.varenr),
        ean(pakning.ean),
        oppbevaring(pakning.oppbevaring),
        pakningsinfo(pakning.pakningsinfo),
        prisVare(pakning.prisVare),
        markedsforingsinfo(pakning.markedsforingsinfo),
        refusjon(pakning.refusjon),
        pakningByttegruppe(pakning.pakningByttegruppe),
        preparatomtaleavsnitt(pakning.preparatomtaleavsnitt),
        ikkeKonservering(pakning.ikkeKonservering) {}

bool PLegemiddelpakning_0_4_0::operator==(const PLegemiddelpakning_0_4_0 &other) const {
    return id == other.id &&
           static_cast<PLegemiddelCore_0_4_0>(*this) == static_cast<PLegemiddelCore_0_4_0>(other) &&
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

PValueWithDistinguishedName PLegemiddelpakning_0_4_0::GetPreparattype() const {
    return preparattype;
}
PFestId PLegemiddelpakning_0_4_0::GetId() const {
    return id;
}
PString PLegemiddelpakning_0_4_0::GetVarenr() const {
    return varenr;
}
PString PLegemiddelpakning_0_4_0::GetEan() const {
    return ean;
}
PValueWithDistinguishedName PLegemiddelpakning_0_4_0::GetOppbevaring() const {
    return oppbevaring;
}
GenericListItems32 PLegemiddelpakning_0_4_0::GetPakningsinfo() const {
    return pakningsinfo;
}
GenericListItems32 PLegemiddelpakning_0_4_0::GetPrisVare() const {
    return prisVare;
}
PMarkedsforingsinfo PLegemiddelpakning_0_4_0::GetMarkedsforingsinfo() const {
    return markedsforingsinfo;
}
PRefusjon PLegemiddelpakning_0_4_0::GetRefusjon() const {
    return refusjon;
}
PPakningByttegruppe PLegemiddelpakning_0_4_0::GetPakningByttegruppe() const {
    return pakningByttegruppe;
}
PPreparatomtaleavsnitt PLegemiddelpakning_0_4_0::GetPreparatomtaleavsnitt() const {
    return preparatomtaleavsnitt;
}
bool PLegemiddelpakning_0_4_0::GetIkkeKonservering() const {
    return ikkeKonservering;
}

PLegemiddelpakning_1_3_0::PLegemiddelpakning_1_3_0(const Legemiddelpakning &legemiddelpakning,
                                                   PakningskomponentList &pakningskomponentList, PakningsinfoList &pakningsinfoList,
                                                   PrisVareList &prisVareList, StringList &stringList, FestUuidList_0_4_0 &festUuidList,
                                                   std::vector<FestUuid> &uuidblock, std::string &strblock,
                                                   std::map<std::string,uint32_t> &cache, RefusjonList &refusjonList) :
        PLegemiddelCore_0_4_0(legemiddelpakning, strblock, cache, festUuidList),
        id(legemiddelpakning.GetId(), uuidblock),
        varenr(legemiddelpakning.GetVarenr(), strblock, cache),
        ean(legemiddelpakning.GetEan(), strblock, cache),
        oppbevaring(legemiddelpakning.GetOppbevaring(), strblock, cache),
        pakningsinfo(),
        prisVare(),
        markedsforingsinfo(legemiddelpakning.GetMarkedsforingsinfo(), strblock, cache),
        refusjon(),
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
    {
        std::vector<PRefusjon> list{};
        for (const auto &p : legemiddelpakning.GetRefusjonList()) {
            list.emplace_back(p, stringList, strblock, cache);
        }
        refusjon = refusjonList.StoreList(list);
    }
}

PLegemiddelpakning_1_3_0::PLegemiddelpakning_1_3_0(const PLegemiddelpakning_0_4_0 &pakning, RefusjonList &refusjonList) :
        PLegemiddelCore_0_4_0(pakning),
        id(pakning.id),
        varenr(pakning.varenr),
        ean(pakning.ean),
        oppbevaring(pakning.oppbevaring),
        pakningsinfo(pakning.pakningsinfo),
        prisVare(pakning.prisVare),
        markedsforingsinfo(pakning.markedsforingsinfo),
        refusjon(),
        pakningByttegruppe(pakning.pakningByttegruppe),
        preparatomtaleavsnitt(pakning.preparatomtaleavsnitt),
        ikkeKonservering(pakning.ikkeKonservering) {
    {
        std::vector<PRefusjon> list{};
        list.emplace_back(pakning.refusjon);
        refusjon = refusjonList.StoreList(list);
    }
}

PLegemiddelpakning_1_3_0::PLegemiddelpakning_1_3_0(const PLegemiddelpakning_0_0_0 &pakning, RefusjonList &refusjonList) :
        PLegemiddelCore_0_4_0(pakning),
        id(pakning.id),
        varenr(pakning.varenr),
        ean(pakning.ean),
        oppbevaring(pakning.oppbevaring),
        pakningsinfo(pakning.pakningsinfo),
        prisVare(pakning.prisVare),
        markedsforingsinfo(pakning.markedsforingsinfo),
        refusjon(),
        pakningByttegruppe(pakning.pakningByttegruppe),
        preparatomtaleavsnitt(pakning.preparatomtaleavsnitt),
        ikkeKonservering(pakning.ikkeKonservering) {
    {
        std::vector<PRefusjon> list{};
        list.emplace_back(pakning.refusjon);
        refusjon = refusjonList.StoreList(list);
    }
}

bool PLegemiddelpakning_1_3_0::operator==(const PLegemiddelpakning_1_3_0 &other) const {
    return id == other.id &&
           static_cast<PLegemiddelCore_0_4_0>(*this) == static_cast<PLegemiddelCore_0_4_0>(other) &&
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

PValueWithDistinguishedName PLegemiddelpakning_1_3_0::GetPreparattype() const {
    return preparattype;
}
PFestId PLegemiddelpakning_1_3_0::GetId() const {
    return id;
}
PString PLegemiddelpakning_1_3_0::GetVarenr() const {
    return varenr;
}
PString PLegemiddelpakning_1_3_0::GetEan() const {
    return ean;
}
PValueWithDistinguishedName PLegemiddelpakning_1_3_0::GetOppbevaring() const {
    return oppbevaring;
}
GenericListItems32 PLegemiddelpakning_1_3_0::GetPakningsinfo() const {
    return pakningsinfo;
}
GenericListItems32 PLegemiddelpakning_1_3_0::GetPrisVare() const {
    return prisVare;
}
PMarkedsforingsinfo PLegemiddelpakning_1_3_0::GetMarkedsforingsinfo() const {
    return markedsforingsinfo;
}
GenericListItems32 PLegemiddelpakning_1_3_0::GetRefusjon() const {
    return refusjon;
}
PPakningByttegruppe PLegemiddelpakning_1_3_0::GetPakningByttegruppe() const {
    return pakningByttegruppe;
}
PPreparatomtaleavsnitt PLegemiddelpakning_1_3_0::GetPreparatomtaleavsnitt() const {
    return preparatomtaleavsnitt;
}
bool PLegemiddelpakning_1_3_0::GetIkkeKonservering() const {
    return ikkeKonservering;
}

PLegemiddelpakning::PLegemiddelpakning(const PLegemiddelpakning_0_0_0 &p) : PLegemiddelCore(p), std::variant<PLegemiddelpakning_0_0_0,PLegemiddelpakning_0_4_0,PLegemiddelpakning_1_3_0>(p) {}
PLegemiddelpakning::PLegemiddelpakning(const PLegemiddelpakning_0_4_0 &p) : PLegemiddelCore(p), std::variant<PLegemiddelpakning_0_0_0,PLegemiddelpakning_0_4_0,PLegemiddelpakning_1_3_0>(p) {}
PLegemiddelpakning::PLegemiddelpakning(const PLegemiddelpakning_1_3_0 &p) : PLegemiddelCore(p), std::variant<PLegemiddelpakning_0_0_0,PLegemiddelpakning_0_4_0,PLegemiddelpakning_1_3_0>(p) {}

PValueWithDistinguishedName PLegemiddelpakning::GetPreparattype() const {
    const std::variant<PLegemiddelpakning_0_0_0,PLegemiddelpakning_0_4_0,PLegemiddelpakning_1_3_0> &p = *this;
    if (std::holds_alternative<PLegemiddelpakning_1_3_0>(p)) {
        return std::get<PLegemiddelpakning_1_3_0>(p).GetPreparattype();
    } else if (std::holds_alternative<PLegemiddelpakning_0_4_0>(p)) {
        return std::get<PLegemiddelpakning_0_4_0>(p).GetPreparattype();
    } else {
        return std::get<PLegemiddelpakning_0_0_0>(p).GetPreparattype();
    }
}

PFestId PLegemiddelpakning::GetId() const {
    const std::variant<PLegemiddelpakning_0_0_0,PLegemiddelpakning_0_4_0,PLegemiddelpakning_1_3_0> &p = *this;
    if (std::holds_alternative<PLegemiddelpakning_1_3_0>(p)) {
        return std::get<PLegemiddelpakning_1_3_0>(p).GetId();
    } else if (std::holds_alternative<PLegemiddelpakning_0_4_0>(p)) {
        return std::get<PLegemiddelpakning_0_4_0>(p).GetId();
    } else {
        return std::get<PLegemiddelpakning_0_0_0>(p).GetId();
    }
}

PString PLegemiddelpakning::GetVarenr() const {
    const std::variant<PLegemiddelpakning_0_0_0,PLegemiddelpakning_0_4_0,PLegemiddelpakning_1_3_0> &p = *this;
    if (std::holds_alternative<PLegemiddelpakning_1_3_0>(p)) {
        return std::get<PLegemiddelpakning_1_3_0>(p).GetVarenr();
    } else if (std::holds_alternative<PLegemiddelpakning_0_4_0>(p)) {
        return std::get<PLegemiddelpakning_0_4_0>(p).GetVarenr();
    } else {
        return std::get<PLegemiddelpakning_0_0_0>(p).GetVarenr();
    }
}

PString PLegemiddelpakning::GetEan() const {
    const std::variant<PLegemiddelpakning_0_0_0,PLegemiddelpakning_0_4_0,PLegemiddelpakning_1_3_0> &p = *this;
    if (std::holds_alternative<PLegemiddelpakning_1_3_0>(p)) {
        return std::get<PLegemiddelpakning_1_3_0>(p).GetEan();
    } else if (std::holds_alternative<PLegemiddelpakning_0_4_0>(p)) {
        return std::get<PLegemiddelpakning_0_4_0>(p).GetEan();
    } else {
        return std::get<PLegemiddelpakning_0_0_0>(p).GetEan();
    }
}

PValueWithDistinguishedName PLegemiddelpakning::GetOppbevaring() const {
    const std::variant<PLegemiddelpakning_0_0_0,PLegemiddelpakning_0_4_0,PLegemiddelpakning_1_3_0> &p = *this;
    if (std::holds_alternative<PLegemiddelpakning_1_3_0>(p)) {
        return std::get<PLegemiddelpakning_1_3_0>(p).GetOppbevaring();
    } else if (std::holds_alternative<PLegemiddelpakning_0_4_0>(p)) {
        return std::get<PLegemiddelpakning_0_4_0>(p).GetOppbevaring();
    } else {
        return std::get<PLegemiddelpakning_0_0_0>(p).GetOppbevaring();
    }
}

GenericListItems32 PLegemiddelpakning::GetPakningsinfo() const {
    const std::variant<PLegemiddelpakning_0_0_0,PLegemiddelpakning_0_4_0,PLegemiddelpakning_1_3_0> &p = *this;
    if (std::holds_alternative<PLegemiddelpakning_1_3_0>(p)) {
        return std::get<PLegemiddelpakning_1_3_0>(p).GetPakningsinfo();
    } else if (std::holds_alternative<PLegemiddelpakning_0_4_0>(p)) {
        return std::get<PLegemiddelpakning_0_4_0>(p).GetPakningsinfo();
    } else {
        return std::get<PLegemiddelpakning_0_0_0>(p).GetPakningsinfo();
    }
}

GenericListItems32 PLegemiddelpakning::GetPrisVare() const {
    const std::variant<PLegemiddelpakning_0_0_0,PLegemiddelpakning_0_4_0,PLegemiddelpakning_1_3_0> &p = *this;
    if (std::holds_alternative<PLegemiddelpakning_1_3_0>(p)) {
        return std::get<PLegemiddelpakning_1_3_0>(p).GetPrisVare();
    } else if (std::holds_alternative<PLegemiddelpakning_0_4_0>(p)) {
        return std::get<PLegemiddelpakning_0_4_0>(p).GetPrisVare();
    } else {
        return std::get<PLegemiddelpakning_0_0_0>(p).GetPrisVare();
    }
}

PMarkedsforingsinfo PLegemiddelpakning::GetMarkedsforingsinfo() const {
    const std::variant<PLegemiddelpakning_0_0_0,PLegemiddelpakning_0_4_0,PLegemiddelpakning_1_3_0> &p = *this;
    if (std::holds_alternative<PLegemiddelpakning_1_3_0>(p)) {
        return std::get<PLegemiddelpakning_1_3_0>(p).GetMarkedsforingsinfo();
    } else if (std::holds_alternative<PLegemiddelpakning_0_4_0>(p)) {
        return std::get<PLegemiddelpakning_0_4_0>(p).GetMarkedsforingsinfo();
    } else {
        return std::get<PLegemiddelpakning_0_0_0>(p).GetMarkedsforingsinfo();
    }
}

PPakningByttegruppe PLegemiddelpakning::GetPakningByttegruppe() const {
    const std::variant<PLegemiddelpakning_0_0_0,PLegemiddelpakning_0_4_0,PLegemiddelpakning_1_3_0> &p = *this;
    if (std::holds_alternative<PLegemiddelpakning_1_3_0>(p)) {
        return std::get<PLegemiddelpakning_1_3_0>(p).GetPakningByttegruppe();
    } else if (std::holds_alternative<PLegemiddelpakning_0_4_0>(p)) {
        return std::get<PLegemiddelpakning_0_4_0>(p).GetPakningByttegruppe();
    } else {
        return std::get<PLegemiddelpakning_0_0_0>(p).GetPakningByttegruppe();
    }
}

PPreparatomtaleavsnitt PLegemiddelpakning::GetPreparatomtaleavsnitt() const {
    const std::variant<PLegemiddelpakning_0_0_0,PLegemiddelpakning_0_4_0,PLegemiddelpakning_1_3_0> &p = *this;
    if (std::holds_alternative<PLegemiddelpakning_1_3_0>(p)) {
        return std::get<PLegemiddelpakning_1_3_0>(p).GetPreparatomtaleavsnitt();
    } else if (std::holds_alternative<PLegemiddelpakning_0_4_0>(p)) {
        return std::get<PLegemiddelpakning_0_4_0>(p).GetPreparatomtaleavsnitt();
    } else {
        return std::get<PLegemiddelpakning_0_0_0>(p).GetPreparatomtaleavsnitt();
    }
}

bool PLegemiddelpakning::GetIkkeKonservering() const {
    const std::variant<PLegemiddelpakning_0_0_0,PLegemiddelpakning_0_4_0,PLegemiddelpakning_1_3_0> &p = *this;
    if (std::holds_alternative<PLegemiddelpakning_1_3_0>(p)) {
        return std::get<PLegemiddelpakning_1_3_0>(p).GetIkkeKonservering();
    } else if (std::holds_alternative<PLegemiddelpakning_0_4_0>(p)) {
        return std::get<PLegemiddelpakning_0_4_0>(p).GetIkkeKonservering();
    } else {
        return std::get<PLegemiddelpakning_0_0_0>(p).GetIkkeKonservering();
    }
}
