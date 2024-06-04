//
// Created by sigsegv on 1/24/23.
//

#include <Struct/Packed/RefusjonList.h>

GenericListItems32 RefusjonList::StoreList(const std::vector<PRefusjon> &list) {
    return GenericListStorage32<PRefusjon>::StoreList(list);
}

std::vector<PRefusjon> RefusjonList::GetStorageList() const {
    return GenericListStorage32<PRefusjon>::GetList();
}

size_t RefusjonList::size() const {
    return GenericListStorage32<PRefusjon>::GetSize();
}
