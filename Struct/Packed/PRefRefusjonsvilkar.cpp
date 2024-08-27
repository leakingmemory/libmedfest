//
// Created by sigsegv on 2/5/23.
//

#include <Struct/Packed/PRefRefusjonsvilkar.h>
#include <Struct/Decoded/RefRefusjonsvilkar.h>

PRefRefusjonsvilkar_0_0_0::PRefRefusjonsvilkar_0_0_0(const RefRefusjonsvilkar &refRefusjonsvilkar, std::vector<FestUuid> &idblock,
                                         std::string &strblock, std::map<std::string, uint32_t> &cache) :
        id(refRefusjonsvilkar.GetId(), idblock),
        fraDato(refRefusjonsvilkar.GetFraDato(), strblock, cache)
{
}

bool PRefRefusjonsvilkar_0_0_0::operator==(const PRefRefusjonsvilkar_0_0_0 &other) const {
    return id == other.id && fraDato == other.fraDato;
}

PRefRefusjonsvilkar_1_2_0::PRefRefusjonsvilkar_1_2_0(const RefRefusjonsvilkar &refRefusjonsvilkar, std::vector<FestUuid> &idblock,
                                                     std::string &strblock, std::map<std::string, uint32_t> &cache) :
        id(refRefusjonsvilkar.GetId(), idblock),
        fraDato(refRefusjonsvilkar.GetFraDato(), strblock, cache),
        tilDato(refRefusjonsvilkar.GetTilDato(), strblock, cache)
{
}

PRefRefusjonsvilkar_1_2_0::PRefRefusjonsvilkar_1_2_0(const PRefRefusjonsvilkar_0_0_0 &refRefusjonsvilkar) :
        id(refRefusjonsvilkar.id),
        fraDato(refRefusjonsvilkar.fraDato),
        tilDato() {}

bool PRefRefusjonsvilkar_1_2_0::operator==(const PRefRefusjonsvilkar_1_2_0 &other) const {
    return id == other.id && fraDato == other.fraDato && tilDato == other.tilDato;
}

PRefRefusjonsvilkar::PRefRefusjonsvilkar(const PRefRefusjonsvilkar_0_0_0 &pref) : std::variant<PRefRefusjonsvilkar_0_0_0,PRefRefusjonsvilkar_1_2_0>(pref) {}
PRefRefusjonsvilkar::PRefRefusjonsvilkar(const PRefRefusjonsvilkar_1_2_0 &pref) : std::variant<PRefRefusjonsvilkar_0_0_0,PRefRefusjonsvilkar_1_2_0>(pref) {}

bool PRefRefusjonsvilkar::operator==(const PRefRefusjonsvilkar &other) const {
    if (std::holds_alternative<PRefRefusjonsvilkar_1_2_0>(*this)) {
        if (std::holds_alternative<PRefRefusjonsvilkar_1_2_0>(other)) {
            return std::get<PRefRefusjonsvilkar_1_2_0>(*this) == std::get<PRefRefusjonsvilkar_1_2_0>(other);
        } else {
            PRefRefusjonsvilkar_1_2_0 o{std::get<PRefRefusjonsvilkar_0_0_0>(other)};
            return std::get<PRefRefusjonsvilkar_1_2_0>(*this) == o;
        }
    } else {
        if (std::holds_alternative<PRefRefusjonsvilkar_1_2_0>(other)) {
            PRefRefusjonsvilkar_1_2_0 t{std::get<PRefRefusjonsvilkar_0_0_0>(*this)};
            return t == std::get<PRefRefusjonsvilkar_1_2_0>(other);
        } else {
            return std::get<PRefRefusjonsvilkar_0_0_0>(*this) == std::get<PRefRefusjonsvilkar_0_0_0>(other);
        }
    }
}