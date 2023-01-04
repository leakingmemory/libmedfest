//
// Created by sigsegv on 1/2/23.
//

#include "PFestId.h"

PFestId::PFestId(const std::string &id, std::vector<FestUuid> &uuidblock) {
    FestUuid festId{id};
    for (typeof(uuidblock.size()) i = 0; i < uuidblock.size(); i++) {
        if (festId == uuidblock[i]) {
            this->id = i;
            return;
        }
    }
    this->id = uuidblock.size();
    uuidblock.push_back(festId);
}

FestUuid PFestId::GetFestId(const std::vector<FestUuid> &uuidblock) const {
    FestUuid uuid{};
    if (id < uuidblock.size()) {
        uuid = uuidblock[id];
    }
    return uuid;
}