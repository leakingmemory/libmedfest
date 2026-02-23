//
// Created by sigsegv on 2/11/23.
//

#ifndef LEGEMFEST_SUBSTANSLIST_H
#define LEGEMFEST_SUBSTANSLIST_H

#include "GenericListStorage.h"
#include "PSubstans.h"

class FestDeserializerPreloader_0;
class FestDeserializerPreloader_1;

class SubstansList : private GenericListStorage32<PSubstans> {
    friend FestDeserializerPreloader_0;
    friend FestDeserializerPreloader_1;
public:
    GenericListItems32 StoreList(const std::vector<PSubstans> &list);
    std::vector<PSubstans> GetStorageList() const;
    size_t size() const;
};


#endif //LEGEMFEST_SUBSTANSLIST_H
