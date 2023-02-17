//
// Created by sigsegv on 2/14/23.
//

#include "DoseringList.h"

GenericListItems DoseringList::StoreList(std::vector<PDosering> &list) {
    return GenericListStorage<PDosering>::StoreList(list);
}

std::vector<PDosering> DoseringList::GetStorageList() const {
    return GetList();
}

size_t DoseringList::size() const {
    return GetSize();
}
