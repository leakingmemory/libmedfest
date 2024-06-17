//
// Created by sigsegv on 6/16/24.
//

#include <Struct/Packed/Uint32List.h>

GenericListItems64 Uint32List::StoreList(const std::vector<uint32_t> &list) {
    return GenericListStorage64<uint32_t>::StoreList(list);
}

std::vector<uint32_t> Uint32List::GetStorageList() const {
    return GetList();
}

size_t Uint32List::size() const {
    return GetSize();
}
