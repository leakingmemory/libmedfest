//
// Created by sigsegv on 1/29/23.
//

#include "StringList.h"

GenericListItems StringList::StoreList(const std::vector<PString> &list) {
    return GenericListStorage<PString>::StoreList(list);
}

GenericListItems StringList::StoreList(const std::vector<std::string> &strings, std::string &strblock){
    std::vector<PString> strs{};
    for (const auto &str : strings) {
        strs.emplace_back(str, strblock);
    }
    return StoreList(strs);
}

std::vector<PString> StringList::GetStorageList() const {
    return GetList();
}

size_t StringList::size() const {
    return GetSize();
}
