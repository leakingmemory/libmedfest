//
// Created by sigsegv on 2/5/23.
//

#include "ElementList.h"

GenericListItems ElementList::StoreList(const std::vector<PElement> &elements) {
    return GenericListStorage<PElement>::StoreList(elements);
}

std::vector<PElement> ElementList::GetStorageList() const {
    return GenericListStorage<PElement>::GetList();
}

size_t ElementList::size() const {
    return GetSize();
}
