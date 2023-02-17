//
// Created by sigsegv on 2/14/23.
//

#include "PLegemiddelforbruk.h"
#include "DoseringList.h"
#include "../Decoded/Legemiddelforbruk.h"
#include <math.h>

PLegemiddelforbruk::PLegemiddelforbruk(const Legemiddelforbruk &legemiddelforbruk, DoseringList &doseringList,
                                       DoseFastTidspunktList &doseFastTidspunktList, std::string &strblock,
                                       std::map<std::string, uint32_t> &cache) :
        dosering(),
        periode(legemiddelforbruk.periode, strblock, cache),
        mengde(legemiddelforbruk.mengde),
        lopenr(legemiddelforbruk.lopenr),
        iterasjoner(legemiddelforbruk.iterasjoner)
{
    std::vector<PDosering> list{};
    for (const auto &item : legemiddelforbruk.dosering) {
        list.emplace_back(item, doseFastTidspunktList, strblock, cache);
    }
    dosering = doseringList.StoreList(list);
}

bool PLegemiddelforbruk::operator==(const PLegemiddelforbruk &other) const {
    return dosering == other.dosering &&
            periode == other.periode &&
            abs(mengde - other.mengde) < 0.00001 &&
            lopenr == other.lopenr &&
            iterasjoner == other.iterasjoner;
}