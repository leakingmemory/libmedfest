//
// Created by sigsegv on 2/15/23.
//

#include "PKortdose.h"
#include "PLegemiddelforbruk.h"
#include "LegemiddelforbrukList.h"
#include "../Decoded/Kortdose.h"

PKortdose::PKortdose(const Kortdose &kortdose, LegemiddelforbrukList &legemiddelforbrukList, DoseringList &doseringList,
                     DoseFastTidspunktList &doseFastTidspunktList, std::string &strblock,
                     std::map<std::string, uint32_t> &cache) :
        kortdose(kortdose.kortdose, strblock, cache),
        beskrivelseTerm(kortdose.beskrivelseTerm, strblock, cache),
        legemiddelforbruk()
{
    std::vector<PLegemiddelforbruk> legemiddelforbruk{};
    for (const auto &item : kortdose.legemiddelforbruk) {
        legemiddelforbruk.emplace_back(item, doseringList, doseFastTidspunktList, strblock, cache);
    }
    this->legemiddelforbruk = legemiddelforbrukList.StoreList(legemiddelforbruk);
}

bool PKortdose::operator==(const PKortdose &other) const {
    return kortdose == other.kortdose &&
           beskrivelseTerm == other.beskrivelseTerm &&
           legemiddelforbruk == other.legemiddelforbruk;
}
