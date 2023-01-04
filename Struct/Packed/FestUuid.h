//
// Created by sigsegv on 1/3/23.
//

#ifndef LEGEMFEST_FESTUUID_H
#define LEGEMFEST_FESTUUID_H

#include <cstdint>
#include <string>

constexpr auto uuid_size = 16;

class FestUuid {
private:
    typedef uint8_t raw_type[uuid_size];
    raw_type id;
public:
    FestUuid() : id() {}
    FestUuid(const std::string &id);
    [[nodiscard]] std::string ToString() const;
    constexpr void ToBytes(raw_type &dst) const {
        static_assert(sizeof(dst) == sizeof(raw_type));
        static_assert(sizeof(id) == sizeof(raw_type));
        static_assert(sizeof(dst) == (uuid_size * sizeof(uint8_t)));
        for (int i = 0; i < uuid_size; i++) {
            dst[i] = id[i];
        }
    }
    constexpr bool operator == (const raw_type &raw) const {
        for (int i = 0; i < uuid_size; i++) {
            if (id[i] != raw[i]) {
                return false;
            }
        }
        return true;
    }
    constexpr bool operator == (const FestUuid &other) const {
        return *this == other.id;
    }
};

static_assert(uuid_size == sizeof(FestUuid));


#endif //LEGEMFEST_FESTUUID_H
