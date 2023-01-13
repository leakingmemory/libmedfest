//
// Created by sigsegv on 1/10/23.
//

#include "ValueWithCodesetList.h"

GenericListItems ValueWithCodesetList::StoreList(const std::vector<PValueWithCodeset> &valueWithCodesetList) {
    return GenericListStorage<PValueWithCodeset>::StoreList(valueWithCodesetList);
}

std::vector<PValueWithCodeset> ValueWithCodesetList::GetStorageBlock() const {
    return GetList();
}

size_t ValueWithCodesetList::size() const {
    return GetSize();
}
