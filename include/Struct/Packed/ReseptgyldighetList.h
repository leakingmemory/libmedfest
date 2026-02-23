//
// Created by sigsegv on 1/10/23.
//

#ifndef LEGEMFEST_RESEPTGYLDIGHETLIST_H
#define LEGEMFEST_RESEPTGYLDIGHETLIST_H

#include "PReseptgyldighet.h"
#include "GenericListStorage.h"
#include <vector>

class FestDeserializerPreloader_0;
class FestDeserializerPreloader_1;

class ReseptgyldighetList : private GenericListStorage32<PReseptgyldighet> {
    friend FestDeserializerPreloader_0;
    friend FestDeserializerPreloader_1;
public:
    GenericListItems32 StoreList(const std::vector<PReseptgyldighet> &);
    [[nodiscard]] std::vector<PReseptgyldighet> GetStorageList() const;
    [[nodiscard]] size_t size() const;
};


#endif //LEGEMFEST_RESEPTGYLDIGHETLIST_H
