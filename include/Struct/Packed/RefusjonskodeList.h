//
// Created by sigsegv on 2/6/23.
//

#ifndef LEGEMFEST_REFUSJONSKODELIST_H
#define LEGEMFEST_REFUSJONSKODELIST_H

#include "PRefusjonskode.h"
#include "GenericListStorage.h"

class FestDeserializerPreloader_0;
class FestDeserializerPreloader_1;
class FestDeserializer_1;

class RefusjonskodeList_0_0_0 : private GenericListStorage32<PRefusjonskode_0_0_0> {
    friend FestDeserializerPreloader_0;
    friend FestDeserializerPreloader_1;
    friend FestDeserializer_0;
    friend FestDeserializer_1;
public:
    GenericListItems32 StoreList(const std::vector<PRefusjonskode_0_0_0> &list, uint32_t start);
    std::vector<PRefusjonskode_0_0_0> GetStorageList() const;
    size_t size() const;
};

class RefusjonskodeList_0_1_0 : private GenericListStorage32<PRefusjonskode_0_1_0> {
    friend FestDeserializerPreloader_0;
    friend FestDeserializerPreloader_1;
public:
    GenericListItems32 StoreList(const std::vector<PRefusjonskode_0_1_0> &list, uint32_t start);
    GenericListItems32 StoreList(const std::vector<PRefusjonskode_0_1_0> &list);
    std::vector<PRefusjonskode_0_1_0> GetStorageList() const;
    size_t size() const;
};

class RefusjonskodeList_1_2_0 : private GenericListStorage32<PRefusjonskode_1_2_0> {
    friend FestDeserializerPreloader_0;
    friend FestDeserializerPreloader_1;
public:
    GenericListItems32 StoreList(const std::vector<PRefusjonskode_1_2_0> &list);
    std::vector<PRefusjonskode_1_2_0> GetStorageList() const;
    size_t size() const;
};

#endif //LEGEMFEST_REFUSJONSKODELIST_H
