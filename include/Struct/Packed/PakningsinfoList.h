//
// Created by sigsegv on 1/19/23.
//

#ifndef LEGEMFEST_PAKNINGSINFOLIST_H
#define LEGEMFEST_PAKNINGSINFOLIST_H

#include "GenericListStorage.h"
#include "PPakningsinfo.h"

class FestDeserializerPreloader;

class PakningsinfoList : private GenericListStorage32<PPakningsinfo> {
    friend FestDeserializerPreloader;
public:
    GenericListItems32 StoreList(const std::vector<PPakningsinfo> &);
    [[nodiscard]] std::vector<PPakningsinfo> GetStorageList() const;
    [[nodiscard]] size_t size() const;
};


#endif //LEGEMFEST_PAKNINGSINFOLIST_H
