//
// Created by sigsegv on 1/19/23.
//

#include "PakningsinfoList.h"

GenericListItems PakningsinfoList::StoreList(const std::vector<PPakningsinfo> &list) {
    return GenericListStorage<PPakningsinfo>::StoreList(list);
}

std::vector<PPakningsinfo> PakningsinfoList::GetStorageList() const {
    return GetList();
}

size_t PakningsinfoList::size() const {
    return GetSize();
}
