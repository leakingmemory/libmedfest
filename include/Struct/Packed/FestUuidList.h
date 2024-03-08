//
// Created by sigsegv on 1/6/23.
//

#ifndef LEGEMFEST_FESTUUIDLIST_H
#define LEGEMFEST_FESTUUIDLIST_H

#include "GenericListStorage.h"
#include "PFestId.h"

class FestDeserializerPreloader;

class FestUuidList : private GenericListStorage<PFestId> {
    friend FestDeserializerPreloader;
private:
    std::vector<FestUuid> &uuidblock;
public:
    FestUuidList(std::vector<FestUuid> &uuidblock) : uuidblock(uuidblock) {}
    GenericListItems StoreList(const std::vector<std::string> &ids);
    [[nodiscard]] std::vector<std::string> RetrieveList(const GenericListItems &litems) const;
    [[nodiscard]] std::vector<PFestId> GetStorageBlock() const;
    [[nodiscard]] size_t size() const;
};


#endif //LEGEMFEST_FESTUUIDLIST_H
