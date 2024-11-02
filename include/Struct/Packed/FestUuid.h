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
    constexpr FestUuid() noexcept : id() {}
    explicit FestUuid(const std::string &id, bool caseSensitive = true);
    constexpr FestUuid(const FestUuid &cp) noexcept {
        for (int i = 0; i < uuid_size; i++) {
            id[i] = cp.id[i];
        }
    }
    constexpr FestUuid(FestUuid &&mv) noexcept {
        for (int i = 0; i < uuid_size; i++) {
            id[i] = mv.id[i];
        }
    }
    constexpr FestUuid &operator =(const FestUuid &cp) noexcept {
        for (int i = 0; i < uuid_size; i++) {
            id[i] = cp.id[i];
        }
        return *this;
    }
    constexpr FestUuid &operator =(FestUuid &&mv) noexcept {
        for (int i = 0; i < uuid_size; i++) {
            id[i] = mv.id[i];
        }
        return *this;
    }
    [[nodiscard]] std::string ToString() const;
    constexpr void ToBytes(raw_type &dst) const noexcept {
        static_assert(sizeof(dst) == sizeof(raw_type));
        static_assert(sizeof(id) == sizeof(raw_type));
        static_assert(sizeof(dst) == (uuid_size * sizeof(uint8_t)));
        for (int i = 0; i < uuid_size; i++) {
            dst[i] = id[i];
        }
    }
    constexpr bool operator == (const raw_type &raw) const noexcept {
        for (int i = 0; i < uuid_size; i++) {
            if (id[i] != raw[i]) {
                return false;
            }
        }
        return true;
    }
    constexpr bool operator == (const FestUuid &other) const noexcept {
        return *this == other.id;
    }
    constexpr bool operator < (const FestUuid &other) const noexcept {
        for (int i = uuid_size - 1; i >= 0; i--) {
            if (id[i] < other.id[i]) {
                return true;
            } else if (id[i] > other.id[i]) {
                return false;
            }
        }
        return false;
    }
    constexpr bool operator > (const FestUuid &other) const noexcept {
        return other < *this;
    }
    constexpr bool operator <= (const FestUuid &other) const noexcept {
        return !(*this > other);
    }
    constexpr bool operator >= (const FestUuid &other) const noexcept {
        return !(*this < other);
    }
};

static_assert(uuid_size == sizeof(FestUuid));


#endif //LEGEMFEST_FESTUUID_H
