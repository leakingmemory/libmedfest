//
// Created by sigsegv on 2/11/23.
//

#include <Struct/Packed/SubstansgruppeList.h>

GenericListItems32 SubstansgruppeList::StoreList(const std::vector<PSubstansgruppe> &list) {
    return GenericListStorage32<PSubstansgruppe>::StoreList(list);
}

std::vector<PSubstansgruppe> SubstansgruppeList::GetStorageList() const {
    return GetList();
}

size_t SubstansgruppeList::size() const {
    return GetSize();
}
