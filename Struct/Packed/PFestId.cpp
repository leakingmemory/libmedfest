//
// Created by sigsegv on 1/2/23.
//

#include "PFestId.h"

PFestId::PFestId(const std::string &id, std::vector<FestUuid> &uuidblock, bool caseSensitive) {
    if (id.empty()) {
        this->id = 0;
        return;
    }
    FestUuid festId{id, caseSensitive};
    for (typeof(uuidblock.size()) i = 0; i < uuidblock.size(); i++) {
        if (festId == uuidblock[i]) {
            this->id = i + 1;
            return;
        }
    }
    this->id = uuidblock.size() + 1;
    uuidblock.push_back(festId);
}

bool PFestId::IsEmpty() const {
    return id == 0;
}

FestUuid PFestId::GetFestId(const std::vector<FestUuid> &uuidblock) const {
    FestUuid uuid{};
    if (id > 0 && id <= uuidblock.size()) {
        uuid = uuidblock[id - 1];
    }
    return uuid;
}

std::string PFestId::ToString(const std::vector<FestUuid> &uuidblock) const {
    if (IsEmpty()) {
        return "";
    }
    return GetFestId(uuidblock).ToString();
}