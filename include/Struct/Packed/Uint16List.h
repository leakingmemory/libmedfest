//
// Created by sigsegv on 2/19/23.
//

#ifndef LEGEMFEST_UINT16LIST_H
#define LEGEMFEST_UINT16LIST_H

#include "GenericListStorage.h"

class FestDeserializer_0;
class FestDeserializer_1;
class FestDeserializerPreloader_0;
class FestDeserializerPreloader_1;

class Uint16List_V_0_0_0 : private GenericListStorage32<uint16_t> {
    friend FestDeserializerPreloader_0;
    friend FestDeserializerPreloader_1;
    friend FestDeserializer_0;
    friend FestDeserializer_1;
public:
    typedef uint16_t ListItemType;
    GenericListItems32 StoreList(const std::vector<uint16_t> &);
    std::vector<uint16_t> GetStorageList() const;
    size_t size() const;
};

class Uint16List : private GenericListStorage64<uint16_t> {
    friend FestDeserializerPreloader_0;
    friend FestDeserializerPreloader_1;
public:
    typedef uint16_t ListItemType;
    GenericListItems64 StoreList(const std::vector<uint16_t> &);
    std::vector<uint16_t> GetStorageList() const;
    size_t size() const;
};

#endif //LEGEMFEST_UINT16LIST_H
