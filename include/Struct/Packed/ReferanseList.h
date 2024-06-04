//
// Created by sigsegv on 2/11/23.
//

#ifndef LEGEMFEST_REFERANSELIST_H
#define LEGEMFEST_REFERANSELIST_H

#include "GenericListStorage.h"
#include "PReferanse.h"

class FestDeserializerPreloader;

class ReferanseList : private GenericListStorage32<PReferanse> {
    friend FestDeserializerPreloader;
public:
    GenericListItems32 StoreList(const std::vector<PReferanse> &list);
    std::vector<PReferanse> GetStorageList() const;
    size_t size() const;
};


#endif //LEGEMFEST_REFERANSELIST_H
