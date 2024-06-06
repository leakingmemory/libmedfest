//
// Created by sigsegv on 2/14/23.
//

#ifndef LEGEMFEST_DOSERINGLIST_H
#define LEGEMFEST_DOSERINGLIST_H

#include "GenericListStorage.h"
#include "PDosering.h"

class FestDeserializerPreloader;

class DoseringList : private GenericListStorage32<PDosering> {
    friend FestDeserializerPreloader;
public:
    typedef PDosering ListItemType;
    [[nodiscard]] GenericListItems32 StoreList(const std::vector<PDosering> &);
    [[nodiscard]] std::vector<PDosering> GetStorageList() const;
    size_t size() const;
};


#endif //LEGEMFEST_DOSERINGLIST_H
