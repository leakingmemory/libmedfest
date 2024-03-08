//
// Created by sigsegv on 1/11/23.
//

#include <Struct/Packed/ValueWithDistinguishedNameList.h>

GenericListItems ValueWithDistinguishedNameList::StoreList(const std::vector<PValueWithDistinguishedName> &list) {
    return GenericListStorage<PValueWithDistinguishedName>::StoreList(list);
}