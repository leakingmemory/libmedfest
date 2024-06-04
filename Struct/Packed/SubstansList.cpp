//
// Created by sigsegv on 2/11/23.
//

#include <Struct/Packed/SubstansList.h>

GenericListItems32 SubstansList::StoreList(const std::vector<PSubstans> &list) {
    return GenericListStorage32<PSubstans>::StoreList(list);
}

std::vector<PSubstans> SubstansList::GetStorageList() const {
    return GetList();
}

size_t SubstansList::size() const {
    return GetSize();
}
