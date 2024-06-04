//
// Created by sigsegv on 1/29/23.
//

#include <Struct/Packed/StringList.h>

GenericListItems32 StringList::StoreList(const std::vector<PString> &list) {
    return GenericListStorage32<PString>::StoreList(list);
}

GenericListItems32 StringList::StoreList(const std::vector<std::string> &strings, std::string &strblock,
                                       std::map<std::string,uint32_t> &cache){
    std::vector<PString> strs{};
    for (const auto &str : strings) {
        strs.emplace_back(str, strblock, cache);
    }
    return StoreList(strs);
}

std::vector<PString> StringList::GetStorageList() const {
    return GetList();
}

size_t StringList::size() const {
    return GetSize();
}
