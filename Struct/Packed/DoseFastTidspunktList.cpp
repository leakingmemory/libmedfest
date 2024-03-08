//
// Created by sigsegv on 2/14/23.
//

#include <Struct/Packed/DoseFastTidspunktList.h>

GenericListItems DoseFastTidspunktList::StoreList(const std::vector<PDoseFastTidspunkt> &list) {
    return GenericListStorage<PDoseFastTidspunkt>::StoreList(list);
}

std::vector<PDoseFastTidspunkt> DoseFastTidspunktList::GetStorageList() const {
    return GetList();
}

size_t DoseFastTidspunktList::size() const {
    return GetSize();
}
