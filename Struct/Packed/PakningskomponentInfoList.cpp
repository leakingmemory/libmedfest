//
// Created by sigsegv on 2/1/23.
//

#include <Struct/Packed/PakningskomponentInfoList.h>

GenericListItems32 PakningskomponentInfoList::StoreList(const std::vector<PPakningskomponentInfo> &list) {
    return GenericListStorage32<PPakningskomponentInfo>::StoreList(list);
}

std::vector<PPakningskomponentInfo> PakningskomponentInfoList::GetStorageList() const {
    return GetList();
}

size_t PakningskomponentInfoList::size() const {
    return GetSize();
}
