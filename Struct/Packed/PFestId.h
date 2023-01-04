//
// Created by sigsegv on 1/2/23.
//

#ifndef LEGEMFEST_PFESTID_H
#define LEGEMFEST_PFESTID_H

#include "FestUuid.h"
#include <vector>

class PFestId {
    uint32_t id;
public:
    PFestId(const std::string &id, std::vector<FestUuid> &uuidblock);
    [[nodiscard]] FestUuid GetFestId(const std::vector<FestUuid> &uuidblock) const;
};

static_assert(sizeof(PFestId) == sizeof(uint32_t));

#endif //LEGEMFEST_PFESTID_H
