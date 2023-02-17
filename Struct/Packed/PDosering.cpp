//
// Created by sigsegv on 2/14/23.
//

#include "PDosering.h"
#include "DoseFastTidspunktList.h"
#include "../Decoded/Dosering.h"

static GenericListItems CreateDoseFastTidspunktList(const std::vector<DoseFastTidspunkt> &items,
                                                    DoseFastTidspunktList &doseFastTidspunktList, std::string &strblock,
                                                    std::map<std::string,uint32_t> &cache) {
    std::vector<PDoseFastTidspunkt> list{};
    for (const auto &item : items) {
        list.emplace_back(item, strblock, cache);
    }
    return doseFastTidspunktList.StoreList(list);
}

PDosering::PDosering(const Dosering &dosering, DoseFastTidspunktList &doseFastTidspunktList, std::string &strblock,
                     std::map<std::string, uint32_t> &cache) :
        GenericListItems(CreateDoseFastTidspunktList(dosering.doseFastTidspunkt, doseFastTidspunktList, strblock, cache))
{
}

bool PDosering::operator==(const PDosering &other) const {
    return static_cast<const GenericListItems>(*this) == static_cast<const GenericListItems>(other);
}
