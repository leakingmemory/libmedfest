//
// Created by sigsegv on 1/6/23.
//

#include "FestUuidList.h"

GenericListItems FestUuidList::StoreList(const std::vector<std::string> &ids) {
    if (ids.size() <= 0) {
        return {.start = 0, .size = 0};
    }
    std::vector<PFestId> packed{};
    for (const auto &id : ids) {
        packed.emplace_back(id, uuidblock);
    }
    return GenericListStorage<PFestId>::StoreList(packed);
}

std::vector<std::string> FestUuidList::RetrieveList(const GenericListItems &litems) const {
    if (litems.size <= 0) {
        return {};
    }
    std::vector<std::string> result{};
    {
        auto packed = GenericListStorage<PFestId>::RetrieveList(litems);
        for (const auto &p : packed) {
            auto id = p.GetFestId(uuidblock).ToString();
            result.emplace_back(id);
        }
    }
    return result;
}

std::vector<PFestId> FestUuidList::GetStorageBlock() const {
    return GetList();
}

size_t FestUuidList::size() const {
    return GetSize();
}