//
// Created by sigsegv on 2/14/23.
//

#include <Struct/Packed/LegemiddelforbrukList.h>

GenericListItems32 LegemiddelforbrukList::StoreList(std::vector<PLegemiddelforbruk> &list) {
    return GenericListStorage32<PLegemiddelforbruk>::StoreList(list);
}

std::vector<PLegemiddelforbruk> LegemiddelforbrukList::GetStorageList() const {
    return GetList();
}

size_t LegemiddelforbrukList::size() const {
    return GetSize();
}
