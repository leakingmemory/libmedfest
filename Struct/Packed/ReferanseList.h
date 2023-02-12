//
// Created by sigsegv on 2/11/23.
//

#ifndef LEGEMFEST_REFERANSELIST_H
#define LEGEMFEST_REFERANSELIST_H

#include "GenericListStorage.h"
#include "PReferanse.h"

class ReferanseList : private GenericListStorage<PReferanse> {
public:
    GenericListItems StoreList(const std::vector<PReferanse> &list);
    std::vector<PReferanse> GetStorageList() const;
    size_t size() const;
};


#endif //LEGEMFEST_REFERANSELIST_H
