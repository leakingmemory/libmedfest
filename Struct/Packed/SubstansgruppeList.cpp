//
// Created by sigsegv on 2/11/23.
//

#include "SubstansgruppeList.h"

GenericListItems SubstansgruppeList::StoreList(const std::vector<PSubstansgruppe> &list) {
    return GenericListStorage<PSubstansgruppe>::StoreList(list);
}

std::vector<PSubstansgruppe> SubstansgruppeList::GetStorageList() const {
    return GetList();
}

size_t SubstansgruppeList::size() const {
    return GetSize();
}
