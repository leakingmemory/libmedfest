//
// Created by sigsegv on 1/10/23.
//

#include <Struct/Packed/ValueWithCodesetList.h>

GenericListItems32 ValueWithCodesetList::StoreList(const std::vector<PValueWithCodeset> &valueWithCodesetList) {
    return GenericListStorage32<PValueWithCodeset>::StoreList(valueWithCodesetList);
}

std::vector<PValueWithCodeset> ValueWithCodesetList::GetStorageBlock() const {
    return GetList();
}

size_t ValueWithCodesetList::size() const {
    return GetSize();
}
