//
// Created by sigsegv on 2/19/23.
//

#include <Struct/Packed/Uint16List.h>

GenericListItems Uint16List::StoreList(const std::vector<uint16_t> &list) {
    return GenericListStorage<uint16_t>::StoreList(list);
}

std::vector<uint16_t> Uint16List::GetStorageList() const {
    return GetList();
}

size_t Uint16List::size() const {
    return GetSize();
}
