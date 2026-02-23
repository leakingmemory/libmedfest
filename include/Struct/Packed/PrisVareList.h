//
// Created by sigsegv on 1/19/23.
//

#ifndef LEGEMFEST_PRISVARELIST_H
#define LEGEMFEST_PRISVARELIST_H

#include "GenericListStorage.h"
#include "PPrisVare.h"

class FestDeserializerPreloader_0;
class FestDeserializerPreloader_1;

class PrisVareList : private GenericListStorage32<PPrisVare> {
    friend FestDeserializerPreloader_0;
    friend FestDeserializerPreloader_1;
public:
    GenericListItems32 StoreList(const std::vector<PPrisVare> &);
    [[nodiscard]] std::vector<PPrisVare> GetStorageList() const;
    [[nodiscard]] size_t size() const;
};


#endif //LEGEMFEST_PRISVARELIST_H
