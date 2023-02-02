//
// Created by sigsegv on 2/1/23.
//

#ifndef LEGEMFEST_PAKNINGSKOMPONENTINFOLIST_H
#define LEGEMFEST_PAKNINGSKOMPONENTINFOLIST_H

#include "GenericListStorage.h"
#include "PPakningskomponentInfo.h"

class PakningskomponentInfoList : private GenericListStorage<PPakningskomponentInfo> {
public:
    GenericListItems StoreList(const std::vector<PPakningskomponentInfo> &);
    [[nodiscard]] std::vector<PPakningskomponentInfo> GetStorageList() const;
    [[nodiscard]] size_t size() const;
};


#endif //LEGEMFEST_PAKNINGSKOMPONENTINFOLIST_H
