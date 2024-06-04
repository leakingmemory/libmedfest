//
// Created by sigsegv on 2/14/23.
//

#include <Struct/Packed/PDosering.h>
#include <Struct/Packed/DoseFastTidspunktList.h>
#include <Struct/Decoded/Dosering.h>

static GenericListItems32 CreateDoseFastTidspunktList(const std::vector<DoseFastTidspunkt> &items,
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
