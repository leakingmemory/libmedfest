//
// Created by sigsegv on 2/14/23.
//

#include "LegemiddelforbrukList.h"

GenericListItems LegemiddelforbrukList::StoreList(std::vector<PLegemiddelforbruk> &list) {
    return GenericListStorage<PLegemiddelforbruk>::StoreList(list);
}

std::vector<PLegemiddelforbruk> LegemiddelforbrukList::GetStorageList() const {
    return GetList();
}

size_t LegemiddelforbrukList::size() const {
    return GetSize();
}
