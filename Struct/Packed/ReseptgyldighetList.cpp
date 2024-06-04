//
// Created by sigsegv on 1/10/23.
//

#include <Struct/Packed/ReseptgyldighetList.h>

GenericListItems32 ReseptgyldighetList::StoreList(const std::vector<PReseptgyldighet> &list) {
    return GenericListStorage32<PReseptgyldighet>::StoreList(list);
}

std::vector<PReseptgyldighet> ReseptgyldighetList::GetStorageList() const {
    return GetList();
}

size_t ReseptgyldighetList::size() const {
    return GetSize();
}
