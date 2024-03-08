//
// Created by sigsegv on 2/1/23.
//

#include <Struct/Packed/PakningskomponentInfoList.h>

GenericListItems PakningskomponentInfoList::StoreList(const std::vector<PPakningskomponentInfo> &list) {
    return GenericListStorage<PPakningskomponentInfo>::StoreList(list);
}

std::vector<PPakningskomponentInfo> PakningskomponentInfoList::GetStorageList() const {
    return GetList();
}

size_t PakningskomponentInfoList::size() const {
    return GetSize();
}
