//
// Created by sigsegv on 1/24/23.
//

#ifndef LEGEMFEST_REFUSJONLIST_H
#define LEGEMFEST_REFUSJONLIST_H

#include "PRefusjon.h"
#include "GenericListStorage.h"

class FestDeserializerPreloader;

class RefusjonList : private GenericListStorage32<PRefusjon> {
    friend FestDeserializerPreloader;
public:
    GenericListItems32 StoreList(const std::vector<PRefusjon> &);
    [[nodiscard]] std::vector<PRefusjon> GetStorageList() const;
    [[nodiscard]] size_t size() const;
};


#endif //LEGEMFEST_REFUSJONLIST_H
