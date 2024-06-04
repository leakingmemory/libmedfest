//
// Created by sigsegv on 1/19/23.
//

#include <Struct/Packed/PrisVareList.h>

GenericListItems32 PrisVareList::StoreList(const std::vector<PPrisVare> &list) {
    return GenericListStorage32<PPrisVare>::StoreList(list);
}

std::vector<PPrisVare> PrisVareList::GetStorageList() const {
    return GetList();
}

size_t PrisVareList::size() const {
    return GetSize();
}