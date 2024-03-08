//
// Created by sigsegv on 1/24/23.
//

#include <Struct/Packed/RefusjonList.h>

GenericListItems RefusjonList::StoreList(const std::vector<PRefusjon> &list) {
    return GenericListStorage<PRefusjon>::StoreList(list);
}

std::vector<PRefusjon> RefusjonList::GetStorageList() const {
    return GenericListStorage<PRefusjon>::GetList();
}

size_t RefusjonList::size() const {
    return GenericListStorage<PRefusjon>::GetSize();
}
