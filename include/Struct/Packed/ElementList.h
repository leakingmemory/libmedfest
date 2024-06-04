//
// Created by sigsegv on 2/5/23.
//

#ifndef LEGEMFEST_ELEMENTLIST_H
#define LEGEMFEST_ELEMENTLIST_H

#include "GenericListStorage.h"
#include "PElement.h"

class FestDeserializerPreloader;

class ElementList : private GenericListStorage32<PElement> {
    friend FestDeserializerPreloader;
public:
    GenericListItems32 StoreList(const std::vector<PElement> &elements);
    std::vector<PElement> GetStorageList() const;
    size_t size() const;
};


#endif //LEGEMFEST_ELEMENTLIST_H
