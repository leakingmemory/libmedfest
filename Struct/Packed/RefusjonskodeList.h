//
// Created by sigsegv on 2/6/23.
//

#ifndef LEGEMFEST_REFUSJONSKODELIST_H
#define LEGEMFEST_REFUSJONSKODELIST_H

#include "PRefusjonskode.h"
#include "GenericListStorage.h"

class FestDeserializerPreloader;

class RefusjonskodeList : private GenericListStorage<PRefusjonskode> {
    friend FestDeserializerPreloader;
public:
    GenericListItems StoreList(const std::vector<PRefusjonskode> &list);
    std::vector<PRefusjonskode> GetStorageList() const;
    size_t size() const;
};


#endif //LEGEMFEST_REFUSJONSKODELIST_H
