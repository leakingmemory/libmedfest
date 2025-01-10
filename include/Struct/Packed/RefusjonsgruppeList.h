//
// Created by sigsegv on 1/7/25.
//

#ifndef LIBMEDFEST_REFUSJONSGRUPPELIST_H
#define LIBMEDFEST_REFUSJONSGRUPPELIST_H

#include "PRefusjonsgruppe.h"
#include "GenericListStorage.h"

class RefusjonsgruppeList : GenericListStorage64<PRefusjonsgruppe> {
    friend FestDeserializerPreloader;
public:
    GenericListItems64 StoreList(const std::vector<PRefusjonsgruppe> &);
    [[nodiscard]] std::vector<PRefusjonsgruppe> GetStorageList() const;
    [[nodiscard]] size_t size() const;
};


#endif //LIBMEDFEST_REFUSJONSGRUPPELIST_H
