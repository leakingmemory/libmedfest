//
// Created by sigsegv on 2/5/23.
//

#ifndef LEGEMFEST_ELEMENTLIST_H
#define LEGEMFEST_ELEMENTLIST_H

#include "GenericListStorage.h"
#include "PElement.h"

class FestDeserializerPreloader;

class ElementList_0_0_0 : private GenericListStorage32<PElement_0_0_0> {
    friend FestDeserializerPreloader;
public:
    GenericListItems32 StoreList(const std::vector<PElement_0_0_0> &elements);
    std::vector<PElement_0_0_0> GetStorageList() const;
    size_t size() const;
};

class ElementList_0_3_0 : private GenericListStorage64<PElement_0_3_0> {
    friend FestDeserializerPreloader;
public:
    GenericListItems64 StoreList(const std::vector<PElement_0_3_0> &elements);
    std::vector<PElement_0_3_0> GetStorageList() const;
    size_t size() const;
};

#endif //LEGEMFEST_ELEMENTLIST_H
