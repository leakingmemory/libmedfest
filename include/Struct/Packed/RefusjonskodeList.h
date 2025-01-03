//
// Created by sigsegv on 2/6/23.
//

#ifndef LEGEMFEST_REFUSJONSKODELIST_H
#define LEGEMFEST_REFUSJONSKODELIST_H

#include "PRefusjonskode.h"
#include "GenericListStorage.h"

class FestDeserializerPreloader;

class RefusjonskodeList_0_0_0 : private GenericListStorage32<PRefusjonskode_0_0_0> {
    friend FestDeserializerPreloader;
    friend FestDeserializer;
public:
    GenericListItems32 StoreList(const std::vector<PRefusjonskode_0_0_0> &list, uint32_t start);
    std::vector<PRefusjonskode_0_0_0> GetStorageList() const;
    size_t size() const;
};

class RefusjonskodeList_0_1_0 : private GenericListStorage32<PRefusjonskode_0_1_0> {
    friend FestDeserializerPreloader;
public:
    GenericListItems32 StoreList(const std::vector<PRefusjonskode_0_1_0> &list, uint32_t start);
    GenericListItems32 StoreList(const std::vector<PRefusjonskode_0_1_0> &list);
    std::vector<PRefusjonskode_0_1_0> GetStorageList() const;
    size_t size() const;
};

class RefusjonskodeList_1_2_0 : private GenericListStorage32<PRefusjonskode_1_2_0> {
    friend FestDeserializerPreloader;
public:
    GenericListItems32 StoreList(const std::vector<PRefusjonskode_1_2_0> &list);
    std::vector<PRefusjonskode_1_2_0> GetStorageList() const;
    size_t size() const;
};

#endif //LEGEMFEST_REFUSJONSKODELIST_H
