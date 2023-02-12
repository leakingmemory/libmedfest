//
// Created by sigsegv on 2/11/23.
//

#ifndef LEGEMFEST_SUBSTANSLIST_H
#define LEGEMFEST_SUBSTANSLIST_H

#include "GenericListStorage.h"
#include "PSubstans.h"

class SubstansList : private GenericListStorage<PSubstans> {
public:
    GenericListItems StoreList(const std::vector<PSubstans> &list);
    std::vector<PSubstans> GetStorageList() const;
    size_t size() const;
};


#endif //LEGEMFEST_SUBSTANSLIST_H
