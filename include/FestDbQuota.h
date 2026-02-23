//
// Created by sigsegv on 2/19/26.
//

#ifndef LIBMEDFEST_FESTDBQUOTA_H
#define LIBMEDFEST_FESTDBQUOTA_H

#include <cstdint>
#include <string>

struct FestDbQuota {
    std::string name{};
    uint64_t total{0};
    uint64_t compatMax{0};
    uint64_t hardMax{0};
};

#endif //LIBMEDFEST_FESTDBQUOTA_H