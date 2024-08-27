//
// Created by sigsegv on 2/6/23.
//

#include <Struct/Packed/RefusjonskodeList.h>

GenericListItems32 RefusjonskodeList_0_0_0::StoreList(const std::vector<PRefusjonskode_0_0_0> &list, uint32_t start) {
    return GenericListStorage32<PRefusjonskode_0_0_0>::StoreList(list, start);
}

std::vector<PRefusjonskode_0_0_0> RefusjonskodeList_0_0_0::GetStorageList() const {
    return GetList();
}

size_t RefusjonskodeList_0_0_0::size() const {
    return GetSize();
}

GenericListItems32 RefusjonskodeList_0_1_0::StoreList(const std::vector<PRefusjonskode_0_1_0> &list, uint32_t start) {
    return GenericListStorage32<PRefusjonskode_0_1_0>::StoreList(list, start);
}

GenericListItems32 RefusjonskodeList_0_1_0::StoreList(const std::vector<PRefusjonskode_0_1_0> &list) {
    return GenericListStorage32<PRefusjonskode_0_1_0>::StoreList(list);
}

std::vector<PRefusjonskode_0_1_0> RefusjonskodeList_0_1_0::GetStorageList() const {
    return GetList();
}

size_t RefusjonskodeList_0_1_0::size() const {
    return GetSize();
}

GenericListItems32 RefusjonskodeList_1_2_0::StoreList(const std::vector<PRefusjonskode_1_2_0> &list) {
    return GenericListStorage32<PRefusjonskode_1_2_0>::StoreList(list);
}

std::vector<PRefusjonskode_1_2_0> RefusjonskodeList_1_2_0::GetStorageList() const {
    return GetList();
}

size_t RefusjonskodeList_1_2_0::size() const {
    return GetSize();
}