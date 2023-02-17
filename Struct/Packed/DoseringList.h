//
// Created by sigsegv on 2/14/23.
//

#ifndef LEGEMFEST_DOSERINGLIST_H
#define LEGEMFEST_DOSERINGLIST_H

#include "GenericListStorage.h"
#include "PDosering.h"

class DoseringList : private GenericListStorage<PDosering> {
public:
    [[nodiscard]] GenericListItems StoreList(std::vector<PDosering> &);
    [[nodiscard]] std::vector<PDosering> GetStorageList() const;
    size_t size() const;
};


#endif //LEGEMFEST_DOSERINGLIST_H
