//
// Created by sigsegv on 6/16/24.
//

#ifndef LIBMEDFEST_UINT32LIST_H
#define LIBMEDFEST_UINT32LIST_H

#include "GenericListStorage.h"

class FestDeserializer;
class FestDeserializerPreloader;

class Uint32List : private GenericListStorage64<uint32_t> {
    friend FestDeserializerPreloader;
public:
    typedef uint32_t ListItemType;
    GenericListItems64 StoreList(const std::vector<uint32_t> &);
    std::vector<uint32_t> GetStorageList() const;
    size_t size() const;
};

#endif //LIBMEDFEST_UINT32LIST_H
