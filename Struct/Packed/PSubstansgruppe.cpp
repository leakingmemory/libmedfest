//
// Created by sigsegv on 2/11/23.
//

#include "PSubstansgruppe.h"
#include "SubstansList.h"
#include "../Decoded/Substansgruppe.h"

PSubstansgruppe::PSubstansgruppe(const Substansgruppe &substansgruppe, SubstansList &substansList, std::vector<FestUuid> &idblock,
                                 std::string &strblock, std::map<std::string, uint32_t> &cache) :
        substans(),
        navn(substansgruppe.navn, strblock, cache)
{
    std::vector<PSubstans> substans{};
    for (const auto &s : substansgruppe.substans) {
        substans.emplace_back(s, idblock, strblock, cache);
    }
    this->substans = substansList.StoreList(substans);
}

bool PSubstansgruppe::operator==(const PSubstansgruppe &other) const {
    return substans == other.substans && navn == other.navn;
}