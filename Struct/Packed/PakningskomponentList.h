//
// Created by sigsegv on 1/18/23.
//

#ifndef LEGEMFEST_PAKNINGSKOMPONENTLIST_H
#define LEGEMFEST_PAKNINGSKOMPONENTLIST_H

#include "GenericListStorage.h"
#include "PPakningskomponent.h"

class PakningskomponentList : private GenericListStorage<PPakningskomponent> {
public:
    GenericListItems StoreList(const std::vector<PPakningskomponent> &);
    [[nodiscard]] std::vector<PPakningskomponent> GetStorageList() const;
    [[nodiscard]] size_t size() const;
};


#endif //LEGEMFEST_PAKNINGSKOMPONENTLIST_H
