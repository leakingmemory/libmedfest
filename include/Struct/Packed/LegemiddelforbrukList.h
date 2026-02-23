//
// Created by sigsegv on 2/14/23.
//

#ifndef LEGEMFEST_LEGEMIDDELFORBRUKLIST_H
#define LEGEMFEST_LEGEMIDDELFORBRUKLIST_H

#include "GenericListStorage.h"
#include "PLegemiddelforbruk.h"

class FestDeserializerPreloader_0;
class FestDeserializerPreloader_1;

class LegemiddelforbrukList : private GenericListStorage32<PLegemiddelforbruk> {
    friend FestDeserializerPreloader_0;
    friend FestDeserializerPreloader_1;
public:
    typedef PLegemiddelforbruk ListItemType;
    [[nodiscard]] GenericListItems32 StoreList(const std::vector<PLegemiddelforbruk> &);
    [[nodiscard]] std::vector<PLegemiddelforbruk> GetStorageList() const;
    size_t size() const;
};


#endif //LEGEMFEST_LEGEMIDDELFORBRUKLIST_H
