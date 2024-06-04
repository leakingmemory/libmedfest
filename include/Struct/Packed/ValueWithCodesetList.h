//
// Created by sigsegv on 1/10/23.
//

#ifndef LEGEMFEST_VALUEWITHCODESETLIST_H
#define LEGEMFEST_VALUEWITHCODESETLIST_H

#include "GenericListStorage.h"
#include "PValueWithCodeset.h"

class FestDeserializerPreloader;

class ValueWithCodesetList : private GenericListStorage32<PValueWithCodeset> {
    friend FestDeserializerPreloader;
public:
    GenericListItems32 StoreList(const std::vector<PValueWithCodeset> &);
    [[nodiscard]] std::vector<PValueWithCodeset> GetStorageBlock() const;
    [[nodiscard]] size_t size() const;
};


#endif //LEGEMFEST_VALUEWITHCODESETLIST_H
