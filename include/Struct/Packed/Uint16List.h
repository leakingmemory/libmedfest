//
// Created by sigsegv on 2/19/23.
//

#ifndef LEGEMFEST_UINT16LIST_H
#define LEGEMFEST_UINT16LIST_H

#include "GenericListStorage.h"

class FestDeserializerPreloader;

class Uint16List : private GenericListStorage32<uint16_t> {
    friend FestDeserializerPreloader;
public:
    GenericListItems32 StoreList(const std::vector<uint16_t> &);
    std::vector<uint16_t> GetStorageList() const;
    size_t size() const;
};


#endif //LEGEMFEST_UINT16LIST_H
