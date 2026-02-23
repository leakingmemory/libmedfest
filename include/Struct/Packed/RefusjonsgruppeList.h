//
// Created by sigsegv on 1/7/25.
//

#ifndef LIBMEDFEST_REFUSJONSGRUPPELIST_H
#define LIBMEDFEST_REFUSJONSGRUPPELIST_H

#include "PRefusjonsgruppe.h"
#include "GenericListStorage.h"

class FestDeserializerPreloader_0;
class FestDeserializerPreloader_1;

class RefusjonsgruppeList : GenericListStorage64<PRefusjonsgruppe> {
    friend FestDeserializerPreloader_0;
    friend FestDeserializerPreloader_1;
public:
    GenericListItems64 StoreList(const std::vector<PRefusjonsgruppe> &);
    [[nodiscard]] std::vector<PRefusjonsgruppe> GetStorageList() const;
    [[nodiscard]] size_t size() const;
};


#endif //LIBMEDFEST_REFUSJONSGRUPPELIST_H
