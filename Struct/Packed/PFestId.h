//
// Created by sigsegv on 1/2/23.
//

#ifndef LEGEMFEST_PFESTID_H
#define LEGEMFEST_PFESTID_H

#include "FestUuid.h"
#include <vector>

class FestDeserializer;

class PFestId {
    friend FestDeserializer;
private:
    uint32_t id;
public:
    PFestId(const std::string &id, std::vector<FestUuid> &uuidblock);
    [[nodiscard]] bool IsEmpty() const;
    [[nodiscard]] FestUuid GetFestId(const std::vector<FestUuid> &uuidblock) const;
    [[nodiscard]] std::string ToString(const std::vector<FestUuid> &uuidblock) const;
    constexpr bool operator == (const PFestId &other) const {
        return this->id == other.id;
    }
};

static_assert(sizeof(PFestId) == sizeof(uint32_t));

#endif //LEGEMFEST_PFESTID_H
