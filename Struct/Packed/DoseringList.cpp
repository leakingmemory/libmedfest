//
// Created by sigsegv on 2/14/23.
//

#include <Struct/Packed/DoseringList.h>

GenericListItems32 DoseringList::StoreList(std::vector<PDosering> &list) {
    return GenericListStorage32<PDosering>::StoreList(list);
}

std::vector<PDosering> DoseringList::GetStorageList() const {
    return GetList();
}

size_t DoseringList::size() const {
    return GetSize();
}
