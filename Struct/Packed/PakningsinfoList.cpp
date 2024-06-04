//
// Created by sigsegv on 1/19/23.
//

#include <Struct/Packed/PakningsinfoList.h>

GenericListItems32 PakningsinfoList::StoreList(const std::vector<PPakningsinfo> &list) {
    return GenericListStorage32<PPakningsinfo>::StoreList(list);
}

std::vector<PPakningsinfo> PakningsinfoList::GetStorageList() const {
    return GetList();
}

size_t PakningsinfoList::size() const {
    return GetSize();
}
