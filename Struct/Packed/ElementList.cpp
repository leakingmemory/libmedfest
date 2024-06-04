//
// Created by sigsegv on 2/5/23.
//

#include <Struct/Packed/ElementList.h>

GenericListItems32 ElementList::StoreList(const std::vector<PElement> &elements) {
    return GenericListStorage32<PElement>::StoreList(elements);
}

std::vector<PElement> ElementList::GetStorageList() const {
    return GenericListStorage32<PElement>::GetList();
}

size_t ElementList::size() const {
    return GetSize();
}
