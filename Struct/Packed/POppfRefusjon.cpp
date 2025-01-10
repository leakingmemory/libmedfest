//
// Created by sigsegv on 2/6/23.
//

#include <Struct/Packed/POppfRefusjon.h>
#include <Struct/Decoded/OppfRefusjon.h>

POppfRefusjon_0_0_0::POppfRefusjon_0_0_0(const OppfRefusjon &oppf, RefusjonskodeList_0_0_0 &refusjonskodeList_0_0_0, RefusjonskodeList_0_1_0 &refusjonskodeList_0_1_0, RefusjonskodeList_1_2_0 &refusjonskodeList_1_2_0,
                             RefRefusjonsvilkarList_0_0_0 &refRefusjonsvilkarList_0_0_0, RefRefusjonsvilkarList_1_2_0 &refRefusjonsvilkarList_1_2_0, StringList &stringList,
                             std::vector<FestUuid> &idblock, std::string &strblock,
                             std::map<std::string, uint32_t> &cache) :
        POppf(oppf, idblock, strblock, cache),
        PRefusjonshjemmel_0_0_0(oppf.refusjonshjemmel, refusjonskodeList_0_0_0, refusjonskodeList_0_1_0, refusjonskodeList_1_2_0, refRefusjonsvilkarList_0_0_0, refRefusjonsvilkarList_1_2_0, stringList, idblock, strblock, cache)
{
}

POppfRefusjon_0_0_0::POppfRefusjon_0_0_0(const OppfRefusjon &oppf, RefusjonskodeList_0_1_0 &refusjonskodeList_0_1_0, RefusjonskodeList_1_2_0 &refusjonskodeList_1_2_0,
                             RefRefusjonsvilkarList_0_0_0 &refRefusjonsvilkarList_0_0_0, RefRefusjonsvilkarList_1_2_0 &refRefusjonsvilkarList_1_2_0, StringList &stringList,
                             std::vector<FestUuid> &idblock, std::string &strblock,
                             std::map<std::string, uint32_t> &cache) :
        POppf(oppf, idblock, strblock, cache),
        PRefusjonshjemmel_0_0_0(oppf.refusjonshjemmel, refusjonskodeList_0_1_0, refusjonskodeList_1_2_0, refRefusjonsvilkarList_0_0_0, refRefusjonsvilkarList_1_2_0, stringList, idblock, strblock, cache)
{
}

bool POppfRefusjon_0_0_0::operator==(const POppfRefusjon_0_0_0 &other) const {
    return POppf::operator==(other) &&
           PRefusjonshjemmel_0_0_0::operator==(other);
}

POppfRefusjon_1_4_0::POppfRefusjon_1_4_0(const OppfRefusjon &oppf, RefusjonskodeList_0_0_0 &refusjonskodeList_0_0_0, RefusjonskodeList_0_1_0 &refusjonskodeList_0_1_0, RefusjonskodeList_1_2_0 &refusjonskodeList_1_2_0,
                             RefRefusjonsvilkarList_0_0_0 &refRefusjonsvilkarList_0_0_0, RefRefusjonsvilkarList_1_2_0 &refRefusjonsvilkarList_1_2_0, RefusjonsgruppeList &refusjonsgruppeList, StringList &stringList,
                             std::vector<FestUuid> &idblock, std::string &strblock,
                             std::map<std::string, uint32_t> &cache) :
        POppf(oppf, idblock, strblock, cache),
        PRefusjonshjemmel_1_4_0(oppf.refusjonshjemmel, refusjonskodeList_0_0_0, refusjonskodeList_0_1_0, refusjonskodeList_1_2_0, refRefusjonsvilkarList_0_0_0, refRefusjonsvilkarList_1_2_0, refusjonsgruppeList, stringList, idblock, strblock, cache)
{
}

POppfRefusjon_1_4_0::POppfRefusjon_1_4_0(const OppfRefusjon &oppf, RefusjonskodeList_0_1_0 &refusjonskodeList_0_1_0, RefusjonskodeList_1_2_0 &refusjonskodeList_1_2_0,
                             RefRefusjonsvilkarList_0_0_0 &refRefusjonsvilkarList_0_0_0, RefRefusjonsvilkarList_1_2_0 &refRefusjonsvilkarList_1_2_0, RefusjonsgruppeList &refusjonsgruppeList, StringList &stringList,
                             std::vector<FestUuid> &idblock, std::string &strblock,
                             std::map<std::string, uint32_t> &cache) :
        POppf(oppf, idblock, strblock, cache),
        PRefusjonshjemmel_1_4_0(oppf.refusjonshjemmel, refusjonskodeList_0_1_0, refusjonskodeList_1_2_0, refRefusjonsvilkarList_0_0_0, refRefusjonsvilkarList_1_2_0, refusjonsgruppeList, stringList, idblock, strblock, cache)
{
}

POppfRefusjon_1_4_0::POppfRefusjon_1_4_0(const POppfRefusjon_0_0_0 &src, RefusjonsgruppeList &refusjonsgruppeList) :
        POppf(static_cast<const POppf &>(src)),
        PRefusjonshjemmel_1_4_0(static_cast<const PRefusjonshjemmel_0_0_0 &>(src), refusjonsgruppeList) {}

bool POppfRefusjon_1_4_0::operator==(const POppfRefusjon_1_4_0 &other) const {
    return POppf::operator==(other) &&
           PRefusjonshjemmel_1_4_0::operator==(other);
}

POppfRefusjon::POppfRefusjon(const POppfRefusjon_0_0_0 &obj) :
    std::variant<POppfRefusjon_0_0_0,POppfRefusjon_1_4_0>(obj),
    POppf(static_cast<const POppf &>(obj)),
    PRefusjonshjemmel(static_cast<const PRefusjonshjemmel_0_0_0 &>(obj)){}
POppfRefusjon::POppfRefusjon(POppfRefusjon_0_0_0 &&obj) :
    std::variant<POppfRefusjon_0_0_0,POppfRefusjon_1_4_0>(std::move(obj)),
    POppf(static_cast<const POppf &>(obj)),
    PRefusjonshjemmel(static_cast<const PRefusjonshjemmel_0_0_0 &>(obj)){}
POppfRefusjon::POppfRefusjon(const POppfRefusjon_1_4_0 &obj) :
    std::variant<POppfRefusjon_0_0_0,POppfRefusjon_1_4_0>(obj),
    POppf(static_cast<const POppf &>(obj)),
    PRefusjonshjemmel(static_cast<const PRefusjonshjemmel_1_4_0 &>(obj)){}
POppfRefusjon::POppfRefusjon(POppfRefusjon_1_4_0 &&obj) :
    std::variant<POppfRefusjon_0_0_0,POppfRefusjon_1_4_0>(std::move(obj)),
    POppf(static_cast<const POppf &>(obj)),
    PRefusjonshjemmel(static_cast<const PRefusjonshjemmel_1_4_0 &>(obj)){}
bool POppfRefusjon::operator==(const POppfRefusjon &other) const {
    if (std::holds_alternative<POppfRefusjon_1_4_0>(static_cast<const std::variant<POppfRefusjon_0_0_0,POppfRefusjon_1_4_0> &>(*this))) {
        if (std::holds_alternative<POppfRefusjon_1_4_0>(static_cast<const std::variant<POppfRefusjon_0_0_0,POppfRefusjon_1_4_0> &>(other))) {
            return std::get<POppfRefusjon_1_4_0>(static_cast<const std::variant<POppfRefusjon_0_0_0,POppfRefusjon_1_4_0> &>(*this)).operator ==(std::get<POppfRefusjon_1_4_0>(static_cast<const std::variant<POppfRefusjon_0_0_0,POppfRefusjon_1_4_0> &>(other)));
        }
    } else {
        if (std::holds_alternative<POppfRefusjon_0_0_0>(static_cast<const std::variant<POppfRefusjon_0_0_0,POppfRefusjon_1_4_0> &>(other))) {
            return std::get<POppfRefusjon_0_0_0>(static_cast<const std::variant<POppfRefusjon_0_0_0,POppfRefusjon_1_4_0> &>(*this)).operator ==(std::get<POppfRefusjon_0_0_0>(static_cast<const std::variant<POppfRefusjon_0_0_0,POppfRefusjon_1_4_0> &>(other)));
        }
    }
    return false;
}

