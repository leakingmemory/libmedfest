//
// Created by sigsegv on 1/24/23.
//

#ifndef LEGEMFEST_REFUSJONLIST_H
#define LEGEMFEST_REFUSJONLIST_H

#include "PRefusjon.h"
#include "GenericListStorage.h"

class RefusjonList : private GenericListStorage<PRefusjon> {
public:
    GenericListItems StoreList(const std::vector<PRefusjon> &);
    [[nodiscard]] std::vector<PRefusjon> GetStorageList() const;
    [[nodiscard]] size_t size() const;
};


#endif //LEGEMFEST_REFUSJONLIST_H
