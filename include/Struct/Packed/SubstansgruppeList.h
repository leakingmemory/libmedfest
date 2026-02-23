//
// Created by sigsegv on 2/11/23.
//

#ifndef LEGEMFEST_SUBSTANSGRUPPELIST_H
#define LEGEMFEST_SUBSTANSGRUPPELIST_H

#include "GenericListStorage.h"
#include "PSubstansgruppe.h"

class FestDeserializerPreloader_0;
class FestDeserializerPreloader_1;

class SubstansgruppeList : private GenericListStorage32<PSubstansgruppe> {
    friend FestDeserializerPreloader_0;
    friend FestDeserializerPreloader_1;
public:
    GenericListItems32 StoreList(const std::vector<PSubstansgruppe> &list);
    std::vector<PSubstansgruppe> GetStorageList() const;
    size_t size() const;
};


#endif //LEGEMFEST_SUBSTANSGRUPPELIST_H
