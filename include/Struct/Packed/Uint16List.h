//
// Created by sigsegv on 2/19/23.
//

#ifndef LEGEMFEST_UINT16LIST_H
#define LEGEMFEST_UINT16LIST_H

#include "GenericListStorage.h"

class FestDeserializer;
class FestDeserializerPreloader;

class Uint16List_V_0_0_0 : private GenericListStorage32<uint16_t> {
    friend FestDeserializerPreloader;
    friend FestDeserializer;
public:
    typedef uint16_t ListItemType;
    GenericListItems32 StoreList(const std::vector<uint16_t> &);
    std::vector<uint16_t> GetStorageList() const;
    size_t size() const;
};

class Uint16List : private GenericListStorage64<uint16_t> {
    friend FestDeserializerPreloader;
public:
    typedef uint16_t ListItemType;
    GenericListItems64 StoreList(const std::vector<uint16_t> &);
    std::vector<uint16_t> GetStorageList() const;
    size_t size() const;
};

#endif //LEGEMFEST_UINT16LIST_H
