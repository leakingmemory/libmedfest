//
// Created by sigsegv on 2/5/23.
//

#ifndef LEGEMFEST_REFREFUSJONSVILKARLIST_H
#define LEGEMFEST_REFREFUSJONSVILKARLIST_H

#include "PRefRefusjonsvilkar.h"
#include "GenericListStorage.h"

class FestDeserializerPreloader;

class RefRefusjonsvilkarList_0_0_0 : private GenericListStorage32<PRefRefusjonsvilkar_0_0_0> {
    friend FestDeserializerPreloader;
public:
    typedef PRefRefusjonsvilkar_0_0_0 ListItemType;
    GenericListItems32 StoreList(const std::vector<PRefRefusjonsvilkar_0_0_0> &list);
    std::vector<PRefRefusjonsvilkar_0_0_0> GetStorageList() const;
    size_t size() const;
};

class RefRefusjonsvilkarList_1_2_0 : private GenericListStorage32<PRefRefusjonsvilkar_1_2_0> {
    friend FestDeserializerPreloader;
public:
    typedef PRefRefusjonsvilkar_1_2_0 ListItemType;
    GenericListItems32 StoreList(const std::vector<PRefRefusjonsvilkar_1_2_0> &list);
    std::vector<PRefRefusjonsvilkar_1_2_0> GetStorageList() const;
    size_t size() const;
};

#endif //LEGEMFEST_REFREFUSJONSVILKARLIST_H
