//
// Created by sigsegv on 2/6/23.
//

#include <Struct/Packed/PRefusjonskode.h>
#include <Struct/Packed/StringList.h>
#include <Struct/Packed/PRefRefusjonsvilkar.h>
#include <Struct/Packed/RefRefusjonsvilkarList.h>
#include <Struct/Decoded/Refusjonskode.h>

PRefusjonskode_0_0_0::PRefusjonskode_0_0_0(const PRefusjonskode &refusjonskode) :
        refusjonskode(refusjonskode.refusjonskode),
        gyldigFraDato(refusjonskode.gyldigFraDato),
        forskrivesTilDato(refusjonskode.forskrivesTilDato),
        underterm(refusjonskode.underterm),
        refusjonsvilkar(refusjonskode.refusjonsvilkar)
{
}

PRefusjonskode_0_0_0::PRefusjonskode_0_0_0(const Refusjonskode &refusjonskode, RefRefusjonsvilkarList &refRefusjonsvilkarList,
                               StringList &stringList, std::vector<FestUuid> &idblock, std::string &strblock,
                               std::map<std::string, uint32_t> &cache) :
        refusjonskode(refusjonskode.refusjonskode, strblock, cache),
        gyldigFraDato(refusjonskode.gyldigFraDato, strblock, cache),
        forskrivesTilDato(refusjonskode.forskrivesTilDato, strblock, cache),
        underterm(),
        refusjonsvilkar()
{
    {
        std::vector<PString> underterm{};
        for (const auto &str : refusjonskode.underterm) {
            underterm.emplace_back(str, strblock, cache);
        }
        this->underterm = stringList.StoreList(underterm);
    }
    {
        std::vector<PRefRefusjonsvilkar> refusjonsvilkar{};
        for (const auto &v: refusjonskode.refusjonsvilkar) {
            refusjonsvilkar.emplace_back(v, idblock, strblock, cache);
        }
        this->refusjonsvilkar = refRefusjonsvilkarList.StoreList(refusjonsvilkar);
    }
}

bool PRefusjonskode_0_0_0::operator==(const PRefusjonskode_0_0_0 &other) const {
    return refusjonskode == other.refusjonskode &&
           gyldigFraDato == other.gyldigFraDato &&
           forskrivesTilDato == other.forskrivesTilDato &&
           underterm == other.underterm &&
           refusjonsvilkar  == other.refusjonsvilkar;
}
PRefusjonskode::PRefusjonskode(const PRefusjonskode_0_0_0 &v0_0_0) :
        refusjonskode(v0_0_0.refusjonskode),
        gyldigFraDato(v0_0_0.gyldigFraDato),
        forskrivesTilDato(v0_0_0.forskrivesTilDato),
        utleveresTilDato(),
        underterm(v0_0_0.underterm),
        refusjonsvilkar(v0_0_0.refusjonsvilkar)
{
}

PRefusjonskode::PRefusjonskode(const Refusjonskode &refusjonskode, RefRefusjonsvilkarList &refRefusjonsvilkarList,
                               StringList &stringList, std::vector<FestUuid> &idblock, std::string &strblock,
                               std::map<std::string, uint32_t> &cache) :
        refusjonskode(refusjonskode.refusjonskode, strblock, cache),
        gyldigFraDato(refusjonskode.gyldigFraDato, strblock, cache),
        forskrivesTilDato(refusjonskode.forskrivesTilDato, strblock, cache),
        utleveresTilDato(refusjonskode.utleveresTilDato, strblock, cache),
        underterm(),
        refusjonsvilkar()
{
    {
        std::vector<PString> underterm{};
        for (const auto &str : refusjonskode.underterm) {
            underterm.emplace_back(str, strblock, cache);
        }
        this->underterm = stringList.StoreList(underterm);
    }
    {
        std::vector<PRefRefusjonsvilkar> refusjonsvilkar{};
        for (const auto &v: refusjonskode.refusjonsvilkar) {
            refusjonsvilkar.emplace_back(v, idblock, strblock, cache);
        }
        this->refusjonsvilkar = refRefusjonsvilkarList.StoreList(refusjonsvilkar);
    }
}

bool PRefusjonskode::operator==(const PRefusjonskode &other) const {
    return refusjonskode == other.refusjonskode &&
            gyldigFraDato == other.gyldigFraDato &&
            forskrivesTilDato == other.forskrivesTilDato &&
            underterm == other.underterm &&
            refusjonsvilkar  == other.refusjonsvilkar;
}