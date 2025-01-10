//
// Created by sigsegv on 1/7/25.
//

#include <Struct/Packed/RefusjonsgruppeList.h>

GenericListItems64 RefusjonsgruppeList::StoreList(const std::vector<PRefusjonsgruppe> &list) {
    return GenericListStorage64<PRefusjonsgruppe>::StoreList(list);
}

std::vector<PRefusjonsgruppe> RefusjonsgruppeList::GetStorageList() const {
    return GenericListStorage64<PRefusjonsgruppe>::GetList();
}

size_t RefusjonsgruppeList::size() const {
    return GenericListStorage64<PRefusjonsgruppe>::GetSize();
}
