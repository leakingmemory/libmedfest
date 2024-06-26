//
// Created by sigsegv on 1/18/23.
//

#include <Struct/Packed/PakningskomponentList.h>

GenericListItems32 PakningskomponentList::StoreList(const std::vector<PPakningskomponent> &list) {
    return GenericListStorage32<PPakningskomponent>::StoreList(list);
}

std::vector<PPakningskomponent> PakningskomponentList::GetStorageList() const {
    return GetList();
}

size_t PakningskomponentList::size() const {
    return GetSize();
}