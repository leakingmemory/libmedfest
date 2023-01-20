//
// Created by sigsegv on 1/18/23.
//

#include "PakningskomponentList.h"

GenericListItems PakningskomponentList::StoreList(const std::vector<PPakningskomponent> &list) {
    return GenericListStorage<PPakningskomponent>::StoreList(list);
}

std::vector<PPakningskomponent> PakningskomponentList::GetStorageList() const {
    return GetList();
}

size_t PakningskomponentList::size() const {
    return GetSize();
}