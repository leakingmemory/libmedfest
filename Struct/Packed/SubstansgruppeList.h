//
// Created by sigsegv on 2/11/23.
//

#ifndef LEGEMFEST_SUBSTANSGRUPPELIST_H
#define LEGEMFEST_SUBSTANSGRUPPELIST_H

#include "GenericListStorage.h"
#include "PSubstansgruppe.h"

class SubstansgruppeList : private GenericListStorage<PSubstansgruppe> {
public:
    GenericListItems StoreList(const std::vector<PSubstansgruppe> &list);
    std::vector<PSubstansgruppe> GetStorageList() const;
    size_t size() const;
};


#endif //LEGEMFEST_SUBSTANSGRUPPELIST_H
