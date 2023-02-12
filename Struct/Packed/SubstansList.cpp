//
// Created by sigsegv on 2/11/23.
//

#include "SubstansList.h"

GenericListItems SubstansList::StoreList(const std::vector<PSubstans> &list) {
    return GenericListStorage<PSubstans>::StoreList(list);
}

std::vector<PSubstans> SubstansList::GetStorageList() const {
    return GetList();
}

size_t SubstansList::size() const {
    return GetSize();
}
