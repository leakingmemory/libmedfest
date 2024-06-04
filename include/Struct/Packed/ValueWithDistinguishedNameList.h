//
// Created by sigsegv on 1/11/23.
//

#ifndef LEGEMFEST_VALUEWITHDISTINGUISHEDNAMELIST_H
#define LEGEMFEST_VALUEWITHDISTINGUISHEDNAMELIST_H

#include "GenericListStorage.h"
#include "PValueWithDistinguishedName.h"

class ValueWithDistinguishedNameList : private GenericListStorage32<PValueWithDistinguishedName> {
public:
    [[nodiscard]] GenericListItems32 StoreList(const std::vector<PValueWithDistinguishedName> &list);
};


#endif //LEGEMFEST_VALUEWITHDISTINGUISHEDNAMELIST_H
