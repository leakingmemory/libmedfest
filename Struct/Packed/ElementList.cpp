//
// Created by sigsegv on 2/5/23.
//

#include <Struct/Packed/ElementList.h>

GenericListItems32 ElementList_0_0_0::StoreList(const std::vector<PElement_0_0_0> &elements) {
    return GenericListStorage32<PElement_0_0_0>::StoreList(elements);
}

std::vector<PElement_0_0_0> ElementList_0_0_0::GetStorageList() const {
    return GenericListStorage32<PElement_0_0_0>::GetList();
}

size_t ElementList_0_0_0::size() const {
    return GetSize();
}

GenericListItems64 ElementList_0_3_0::StoreList(const std::vector<PElement_0_3_0> &elements) {
    return GenericListStorage64<PElement_0_3_0>::StoreList(elements);
}

std::vector<PElement_0_3_0> ElementList_0_3_0::GetStorageList() const {
    return GenericListStorage64<PElement_0_3_0>::GetList();
}

size_t ElementList_0_3_0::size() const {
    return GetSize();
}
