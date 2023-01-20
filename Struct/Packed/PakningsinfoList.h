//
// Created by sigsegv on 1/19/23.
//

#ifndef LEGEMFEST_PAKNINGSINFOLIST_H
#define LEGEMFEST_PAKNINGSINFOLIST_H

#include "GenericListStorage.h"
#include "PPakningsinfo.h"

class PakningsinfoList : private GenericListStorage<PPakningsinfo> {
public:
    GenericListItems StoreList(const std::vector<PPakningsinfo> &);
    [[nodiscard]] std::vector<PPakningsinfo> GetStorageList() const;
    [[nodiscard]] size_t size() const;
};


#endif //LEGEMFEST_PAKNINGSINFOLIST_H
