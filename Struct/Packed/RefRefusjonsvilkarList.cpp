//
// Created by sigsegv on 2/5/23.
//

#include <Struct/Packed/RefRefusjonsvilkarList.h>

GenericListItems RefRefusjonsvilkarList::StoreList(std::vector<PRefRefusjonsvilkar> &list) {
    return GenericListStorage<PRefRefusjonsvilkar>::StoreList(list);
}

std::vector<PRefRefusjonsvilkar> RefRefusjonsvilkarList::GetStorageList() const {
    return GetList();
}

size_t RefRefusjonsvilkarList::size() const {
    return GetSize();
}
