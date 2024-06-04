//
// Created by sigsegv on 1/11/23.
//

#include <Struct/Packed/ValueWithDistinguishedNameList.h>

GenericListItems32 ValueWithDistinguishedNameList::StoreList(const std::vector<PValueWithDistinguishedName> &list) {
    return GenericListStorage32<PValueWithDistinguishedName>::StoreList(list);
}