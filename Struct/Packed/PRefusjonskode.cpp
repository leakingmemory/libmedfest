//
// Created by sigsegv on 2/6/23.
//

#include "PRefusjonskode.h"
#include "StringList.h"
#include "PRefRefusjonsvilkar.h"
#include "RefRefusjonsvilkarList.h"
#include "../Decoded/Refusjonskode.h"

PRefusjonskode::PRefusjonskode(const Refusjonskode &refusjonskode, RefRefusjonsvilkarList &refRefusjonsvilkarList,
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

bool PRefusjonskode::operator==(const PRefusjonskode &other) const {
    return refusjonskode == other.refusjonskode &&
            gyldigFraDato == other.gyldigFraDato &&
            forskrivesTilDato == other.forskrivesTilDato &&
            underterm == other.underterm &&
            refusjonsvilkar  == other.refusjonsvilkar;
}