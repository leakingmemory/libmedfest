//
// Created by sigsegv on 2/19/23.
//

#include <Struct/Packed/Uint16List.h>

GenericListItems32 Uint16List_V_0_0_0::StoreList(const std::vector<uint16_t> &list) {
    return GenericListStorage32<uint16_t>::StoreList(list);
}

std::vector<uint16_t> Uint16List_V_0_0_0::GetStorageList() const {
    return GetList();
}

size_t Uint16List_V_0_0_0::size() const {
    return GetSize();
}

GenericListItems64 Uint16List::StoreList(const std::vector<uint16_t> &list) {
    return GenericListStorage64<uint16_t>::StoreList(list);
}

std::vector<uint16_t> Uint16List::GetStorageList() const {
    return GetList();
}

size_t Uint16List::size() const {
    return GetSize();
}
