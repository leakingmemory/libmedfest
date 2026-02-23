//
// Created by sigsegv on 2/1/23.
//

#ifndef LEGEMFEST_PAKNINGSKOMPONENTINFOLIST_H
#define LEGEMFEST_PAKNINGSKOMPONENTINFOLIST_H

#include "GenericListStorage.h"
#include "PPakningskomponentInfo.h"

class FestDeserializerPreloader_0;
class FestDeserializerPreloader_1;

class PakningskomponentInfoList : private GenericListStorage32<PPakningskomponentInfo> {
    friend FestDeserializerPreloader_0;
    friend FestDeserializerPreloader_1;
public:
    GenericListItems32 StoreList(const std::vector<PPakningskomponentInfo> &);
    [[nodiscard]] std::vector<PPakningskomponentInfo> GetStorageList() const;
    [[nodiscard]] size_t size() const;
};


#endif //LEGEMFEST_PAKNINGSKOMPONENTINFOLIST_H
