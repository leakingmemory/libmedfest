//
// Created by sigsegv on 2/6/23.
//

#include <Struct/Packed/PRefusjonshjemmel.h>
#include <Struct/Decoded/Refusjonshjemmel.h>
#include <Struct/Packed/RefusjonsgruppeList.h>

static Refusjonsgruppe LastOrDefault(const std::vector<Refusjonsgruppe> &refusjonsgruppe) {
    if (!refusjonsgruppe.empty()) {
        return refusjonsgruppe.back();
    } else {
        return {};
    }
}

PRefusjonshjemmel_0_0_0::PRefusjonshjemmel_0_0_0(const Refusjonshjemmel &refusjonshjemmel, RefusjonskodeList_0_0_0 &refusjonskodeList_0_0_0, RefusjonskodeList_0_1_0 &refusjonskodeList_0_1_0, RefusjonskodeList_1_2_0 &refusjonskodeList_1_2_0,
                                     RefRefusjonsvilkarList_0_0_0 &refRefusjonsvilkarList_0_0_0, RefRefusjonsvilkarList_1_2_0 &refRefusjonsvilkarList_1_2_0, StringList &stringList,
                                     std::vector<FestUuid> &idblock, std::string &strblock,
                                     std::map<std::string, uint32_t> &cache) :
        PRefusjonsgruppe(LastOrDefault(refusjonshjemmel.refusjonsgruppe), refusjonskodeList_0_0_0, refusjonskodeList_0_1_0, refusjonskodeList_1_2_0, refRefusjonsvilkarList_0_0_0, refRefusjonsvilkarList_1_2_0, stringList, idblock, strblock, cache),
        refusjonshjemmel(refusjonshjemmel.refusjonshjemmel, strblock, cache),
        kreverVarekobling(refusjonshjemmel.kreverVarekobling),
        kreverVedtak(refusjonshjemmel.kreverVedtak)
{}

PRefusjonshjemmel_0_0_0::PRefusjonshjemmel_0_0_0(const Refusjonshjemmel &refusjonshjemmel, RefusjonskodeList_0_1_0 &refusjonskodeList_0_1_0, RefusjonskodeList_1_2_0 &refusjonskodeList_1_2_0,
                                     RefRefusjonsvilkarList_0_0_0 &refRefusjonsvilkarList_0_0_0, RefRefusjonsvilkarList_1_2_0 &refRefusjonsvilkarList_1_2_0, StringList &stringList,
                                     std::vector<FestUuid> &idblock, std::string &strblock,
                                     std::map<std::string, uint32_t> &cache) :
        PRefusjonsgruppe(LastOrDefault(refusjonshjemmel.refusjonsgruppe), refusjonskodeList_0_1_0, refusjonskodeList_1_2_0, refRefusjonsvilkarList_0_0_0, refRefusjonsvilkarList_1_2_0, stringList, idblock, strblock, cache),
        refusjonshjemmel(refusjonshjemmel.refusjonshjemmel, strblock, cache),
        kreverVarekobling(refusjonshjemmel.kreverVarekobling),
        kreverVedtak(refusjonshjemmel.kreverVedtak)
{}

bool PRefusjonshjemmel_0_0_0::operator==(const PRefusjonshjemmel_0_0_0 &other) const {
    return PRefusjonsgruppe::operator==(other) &&
           refusjonshjemmel == other.refusjonshjemmel &&
           kreverVarekobling == other.kreverVarekobling &&
           kreverVedtak == other.kreverVedtak;
}

PRefusjonshjemmel_1_4_0::PRefusjonshjemmel_1_4_0(const Refusjonshjemmel &refusjonshjemmel, RefusjonskodeList_0_0_0 &refusjonskodeList_0_0_0, RefusjonskodeList_0_1_0 &refusjonskodeList_0_1_0, RefusjonskodeList_1_2_0 &refusjonskodeList_1_2_0,
                                                 RefRefusjonsvilkarList_0_0_0 &refRefusjonsvilkarList_0_0_0, RefRefusjonsvilkarList_1_2_0 &refRefusjonsvilkarList_1_2_0, RefusjonsgruppeList &refusjonsgruppeList, StringList &stringList,
                                                 std::vector<FestUuid> &idblock, std::string &strblock,
                                                 std::map<std::string, uint32_t> &cache) :
        refusjonshjemmel(refusjonshjemmel.refusjonshjemmel, strblock, cache),
        refusjonsgruppe(),
        kreverVarekobling(refusjonshjemmel.kreverVarekobling),
        kreverVedtak(refusjonshjemmel.kreverVedtak)
{
    std::vector<PRefusjonsgruppe> refusjonsgruppeVector{};
    for (const auto &refusjonsgruppe : refusjonshjemmel.refusjonsgruppe) {
        refusjonsgruppeVector.emplace_back(refusjonsgruppe, refusjonskodeList_0_0_0, refusjonskodeList_0_1_0, refusjonskodeList_1_2_0, refRefusjonsvilkarList_0_0_0, refRefusjonsvilkarList_1_2_0, stringList, idblock, strblock, cache);
    }
    refusjonsgruppe = refusjonsgruppeList.StoreList(refusjonsgruppeVector);
}

PRefusjonshjemmel_1_4_0::PRefusjonshjemmel_1_4_0(const Refusjonshjemmel &refusjonshjemmel, RefusjonskodeList_0_1_0 &refusjonskodeList_0_1_0, RefusjonskodeList_1_2_0 &refusjonskodeList_1_2_0,
                                                 RefRefusjonsvilkarList_0_0_0 &refRefusjonsvilkarList_0_0_0, RefRefusjonsvilkarList_1_2_0 &refRefusjonsvilkarList_1_2_0, RefusjonsgruppeList &refusjonsgruppeList, StringList &stringList,
                                                 std::vector<FestUuid> &idblock, std::string &strblock,
                                                 std::map<std::string, uint32_t> &cache) :
        refusjonshjemmel(refusjonshjemmel.refusjonshjemmel, strblock, cache),
        refusjonsgruppe(),
        kreverVarekobling(refusjonshjemmel.kreverVarekobling),
        kreverVedtak(refusjonshjemmel.kreverVedtak)
{
    std::vector<PRefusjonsgruppe> refusjonsgruppeVector{};
    for (const auto &refusjonsgruppe : refusjonshjemmel.refusjonsgruppe) {
        refusjonsgruppeVector.emplace_back(refusjonsgruppe, refusjonskodeList_0_1_0, refusjonskodeList_1_2_0, refRefusjonsvilkarList_0_0_0, refRefusjonsvilkarList_1_2_0, stringList, idblock, strblock, cache);
    }
    refusjonsgruppe = refusjonsgruppeList.StoreList(refusjonsgruppeVector);
}

PRefusjonshjemmel_1_4_0::PRefusjonshjemmel_1_4_0(const PRefusjonshjemmel_0_0_0 &src, RefusjonsgruppeList &refusjonsgruppeList) :
        refusjonshjemmel(src.refusjonshjemmel),
        refusjonsgruppe(refusjonsgruppeList.StoreList({static_cast<const PRefusjonsgruppe &>(src)})),
        kreverVarekobling(src.kreverVarekobling),
        kreverVedtak(src.kreverVedtak) {}

bool PRefusjonshjemmel_1_4_0::operator==(const PRefusjonshjemmel_1_4_0 &other) const {
    return refusjonsgruppe == other.refusjonsgruppe &&
           refusjonshjemmel == other.refusjonshjemmel &&
           kreverVarekobling == other.kreverVarekobling &&
           kreverVedtak == other.kreverVedtak;
}

PRefusjonshjemmel::PRefusjonshjemmel(const PRefusjonshjemmel_0_0_0 &pref) :
    std::variant<PRefusjonshjemmel_0_0_0,PRefusjonshjemmel_1_4_0>(pref) {
}

PRefusjonshjemmel::PRefusjonshjemmel(const PRefusjonshjemmel_1_4_0 &pref) :
        std::variant<PRefusjonshjemmel_0_0_0,PRefusjonshjemmel_1_4_0>(pref) {
}

bool PRefusjonshjemmel::operator==(const PRefusjonshjemmel &other) const {
    if (std::holds_alternative<PRefusjonshjemmel_1_4_0>(*this)) {
        if (std::holds_alternative<PRefusjonshjemmel_1_4_0>(other)) {
            return std::get<PRefusjonshjemmel_1_4_0>(*this).operator ==(std::get<PRefusjonshjemmel_1_4_0>(other));
        }
    } else {
        if (std::holds_alternative<PRefusjonshjemmel_0_0_0>(other)) {
            return std::get<PRefusjonshjemmel_0_0_0>(*this).operator ==(std::get<PRefusjonshjemmel_0_0_0>(other));
        }
    }
    return false;
}