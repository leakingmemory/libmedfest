//
// Created by sigsegv on 2/11/23.
//

#include <Struct/Packed/ReferanseList.h>

GenericListItems32 ReferanseList::StoreList(const std::vector<PReferanse> &list) {
    return GenericListStorage32<PReferanse>::StoreList(list);
}

std::vector<PReferanse> ReferanseList::GetStorageList() const {
    return GetList();
}

size_t ReferanseList::size() const {
    return GetSize();
}
