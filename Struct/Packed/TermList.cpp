//
// Created by sigsegv on 6/15/24.
//

#include <Struct/Packed/TermList.h>

GenericListItems64 TermList::StoreList(const std::vector<PTerm> &elements) {
    return GenericListStorage64<PTerm>::StoreList(elements);
}

std::vector<PTerm> TermList::GetStorageList() const {
    return GenericListStorage64<PTerm>::GetList();
}

size_t TermList::size() const {
    return GetSize();
}
