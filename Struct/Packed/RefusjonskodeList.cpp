//
// Created by sigsegv on 2/6/23.
//

#include "RefusjonskodeList.h"

GenericListItems RefusjonskodeList::StoreList(const std::vector<PRefusjonskode> &list) {
    return GenericListStorage<PRefusjonskode>::StoreList(list);
}

std::vector<PRefusjonskode> RefusjonskodeList::GetStorageList() const {
    return GetList();
}

size_t RefusjonskodeList::size() const {
    return GetSize();
}