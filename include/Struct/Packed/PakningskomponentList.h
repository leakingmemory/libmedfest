//
// Created by sigsegv on 1/18/23.
//

#ifndef LEGEMFEST_PAKNINGSKOMPONENTLIST_H
#define LEGEMFEST_PAKNINGSKOMPONENTLIST_H

#include "GenericListStorage.h"
#include "PPakningskomponent.h"

class FestDeserializerPreloader_0;
class FestDeserializerPreloader_1;

class PakningskomponentList : private GenericListStorage32<PPakningskomponent> {
    friend FestDeserializerPreloader_0;
    friend FestDeserializerPreloader_1;
public:
    GenericListItems32 StoreList(const std::vector<PPakningskomponent> &);
    [[nodiscard]] std::vector<PPakningskomponent> GetStorageList() const;
    [[nodiscard]] size_t size() const;
};


#endif //LEGEMFEST_PAKNINGSKOMPONENTLIST_H
