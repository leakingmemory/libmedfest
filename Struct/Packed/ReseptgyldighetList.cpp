//
// Created by sigsegv on 1/10/23.
//

#include "ReseptgyldighetList.h"

GenericListItems ReseptgyldighetList::StoreList(const std::vector<PReseptgyldighet> &list) {
    return GenericListStorage<PReseptgyldighet>::StoreList(list);
}

std::vector<PReseptgyldighet> ReseptgyldighetList::GetStorageList() const {
    return GetList();
}

size_t ReseptgyldighetList::size() const {
    return GetSize();
}
