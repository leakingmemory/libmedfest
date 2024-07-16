//
// Created by sigsegv on 1/6/23.
//

#include <Struct/Packed/FestUuidList.h>

GenericListItems32 FestUuidList_0_0_0::StoreList(const std::vector<std::string> &ids) {
    if (ids.size() <= 0) {
        return {.start = 0, .size = 0};
    }
    std::vector<PFestId> packed{};
    for (const auto &id : ids) {
        packed.emplace_back(id, uuidblock);
    }
    return GenericListStorage32<PFestId>::StoreList(packed);
}

std::vector<std::string> FestUuidList_0_0_0::RetrieveList(const GenericListItems32 &litems) const {
    if (litems.size <= 0) {
        return {};
    }
    std::vector<std::string> result{};
    {
        auto packed = GenericListStorage32<PFestId>::RetrieveList(litems);
        for (const auto &p : packed) {
            auto id = p.ToString(uuidblock);
            result.emplace_back(id);
        }
    }
    return result;
}

std::vector<PFestId> FestUuidList_0_0_0::GetStorageBlock() const {
    return GetList();
}

size_t FestUuidList_0_0_0::size() const {
    return GetSize();
}

GenericListItems64 FestUuidList_0_4_0::StoreList(const std::vector<std::string> &ids) {
    if (ids.size() <= 0) {
        return {.start = 0, .size = 0};
    }
    std::vector<PFestId> packed{};
    for (const auto &id : ids) {
        packed.emplace_back(id, uuidblock);
    }
    return GenericListStorage64<PFestId>::StoreList(packed);
}

std::vector<std::string> FestUuidList_0_4_0::RetrieveList(const GenericListItems64 &litems) const {
    if (litems.size <= 0) {
        return {};
    }
    std::vector<std::string> result{};
    {
        auto packed = GenericListStorage64<PFestId>::RetrieveList(litems);
        for (const auto &p : packed) {
            auto id = p.ToString(uuidblock);
            result.emplace_back(id);
        }
    }
    return result;
}

std::vector<PFestId> FestUuidList_0_4_0::GetStorageBlock() const {
    return GetList();
}

size_t FestUuidList_0_4_0::size() const {
    return GetSize();
}