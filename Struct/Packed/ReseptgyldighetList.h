//
// Created by sigsegv on 1/10/23.
//

#ifndef LEGEMFEST_RESEPTGYLDIGHETLIST_H
#define LEGEMFEST_RESEPTGYLDIGHETLIST_H

#include "PReseptgyldighet.h"
#include "GenericListStorage.h"
#include <vector>

class FestDeserializerPreloader;

class ReseptgyldighetList : private GenericListStorage<PReseptgyldighet> {
    friend FestDeserializerPreloader;
public:
    GenericListItems StoreList(const std::vector<PReseptgyldighet> &);
    [[nodiscard]] std::vector<PReseptgyldighet> GetStorageList() const;
    [[nodiscard]] size_t size() const;
};


#endif //LEGEMFEST_RESEPTGYLDIGHETLIST_H
