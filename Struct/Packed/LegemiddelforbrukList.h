//
// Created by sigsegv on 2/14/23.
//

#ifndef LEGEMFEST_LEGEMIDDELFORBRUKLIST_H
#define LEGEMFEST_LEGEMIDDELFORBRUKLIST_H

#include "GenericListStorage.h"
#include "PLegemiddelforbruk.h"

class LegemiddelforbrukList : private GenericListStorage<PLegemiddelforbruk> {
public:
    [[nodiscard]] GenericListItems StoreList(std::vector<PLegemiddelforbruk> &);
    [[nodiscard]] std::vector<PLegemiddelforbruk> GetStorageList() const;
    size_t size() const;
};


#endif //LEGEMFEST_LEGEMIDDELFORBRUKLIST_H
