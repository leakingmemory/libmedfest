//
// Created by sigsegv on 2/6/23.
//

#include <Struct/Packed/RefusjonskodeList.h>

GenericListItems RefusjonskodeList_0_0_0::StoreList(const std::vector<PRefusjonskode_0_0_0> &list, uint32_t start) {
    return GenericListStorage<PRefusjonskode_0_0_0>::StoreList(list, start);
}

std::vector<PRefusjonskode_0_0_0> RefusjonskodeList_0_0_0::GetStorageList() const {
    return GetList();
}

size_t RefusjonskodeList_0_0_0::size() const {
    return GetSize();
}

GenericListItems RefusjonskodeList::StoreList(const std::vector<PRefusjonskode> &list) {
    return GenericListStorage<PRefusjonskode>::StoreList(list);
}

std::vector<PRefusjonskode> RefusjonskodeList::GetStorageList() const {
    return GetList();
}

size_t RefusjonskodeList::size() const {
    return GetSize();
}