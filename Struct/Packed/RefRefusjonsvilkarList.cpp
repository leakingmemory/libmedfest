//
// Created by sigsegv on 2/5/23.
//

#include <Struct/Packed/RefRefusjonsvilkarList.h>

GenericListItems32 RefRefusjonsvilkarList_0_0_0::StoreList(const std::vector<PRefRefusjonsvilkar_0_0_0> &list) {
    return GenericListStorage32<PRefRefusjonsvilkar_0_0_0>::StoreList(list);
}

std::vector<PRefRefusjonsvilkar_0_0_0> RefRefusjonsvilkarList_0_0_0::GetStorageList() const {
    return GetList();
}

size_t RefRefusjonsvilkarList_0_0_0::size() const {
    return GetSize();
}

GenericListItems32 RefRefusjonsvilkarList_1_2_0::StoreList(const std::vector<PRefRefusjonsvilkar_1_2_0> &list) {
    return GenericListStorage32<PRefRefusjonsvilkar_1_2_0>::StoreList(list);
}

std::vector<PRefRefusjonsvilkar_1_2_0> RefRefusjonsvilkarList_1_2_0::GetStorageList() const {
    return GetList();
}

size_t RefRefusjonsvilkarList_1_2_0::size() const {
    return GetSize();
}
