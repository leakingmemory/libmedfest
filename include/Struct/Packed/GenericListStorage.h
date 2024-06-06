//
// Created by sigsegv on 1/4/23.
//

#ifndef LEGEMFEST_GENERICLISTSTORAGE_H
#define LEGEMFEST_GENERICLISTSTORAGE_H

#include <concepts>
#include <cstdint>
#include <vector>
#include <iostream>
#include <limits>

template <typename T> concept GenericListStorageObject = requires (T tp) {
    {tp == std::declval<T>()} -> std::convertible_to<bool>;
};

template <typename T> concept GenericListItemType = requires (T tp) {
    { T::max_size } -> std::convertible_to<int>;
    { T::max_address } -> std::convertible_to<int>;
    { tp.start } -> std::convertible_to<int>;
    { tp.size } -> std::convertible_to<int>;
    { tp == std::declval<T>() } -> std::convertible_to<bool>;
    { std::declval<typename T::int_type>() } -> std::convertible_to<int>;
};

template <typename T, int sizeBits> struct GenericListItems {
    typedef T int_type;
    constexpr static int total_bits = sizeof(int_type) * 8;
    constexpr static int size_bits = sizeBits;
    constexpr static int addr_bits = total_bits - size_bits;
    constexpr static int_type max_address = (((int_type) 1) << addr_bits) - 1;
    constexpr static int_type max_size = (((int_type) 1) << size_bits) - 1;
    int_type start : addr_bits;
    int_type size : size_bits;

    template <GenericListItemType TL> constexpr TL CastToWider() const {
        static_assert(TL::max_address >= max_address);
        static_assert(TL::max_size >= max_size);
        return {.start = start, .size = size};
    }

    bool operator == (const GenericListItems &other) const {
        return  start == other.start &&
                size == other.size;
    }
} __attribute__((__packed__));

typedef GenericListItems<uint32_t,14> GenericListItems32;

static_assert(sizeof(GenericListItems32) == sizeof(GenericListItems32::int_type));
static_assert(sizeof(GenericListItems32) == sizeof(uint32_t));

typedef GenericListItems<uint64_t,32> GenericListItems64;

static_assert(sizeof(GenericListItems64) == sizeof(GenericListItems64::int_type));
static_assert(sizeof(GenericListItems64) == sizeof(uint64_t));
static_assert(GenericListItems64::max_address == std::numeric_limits<uint32_t>::max());

class FestDeserializerPreloader;

template <GenericListStorageObject T, GenericListItemType ItemType> class GenericListStorage {
    friend FestDeserializerPreloader;
private:
    std::vector<T> list;
public:
    typedef T ListItemType;
    GenericListStorage() : list() {}
    ItemType StoreList(const std::vector<T> &list) {
        {
            auto check_iter = list.begin();
            if (check_iter == list.end()) {
                return {.start = 0, .size = 0};
            }
            size_t index = 0;
            auto iter = this->list.begin();
            while (iter != this->list.end()) {
                if (*iter == *check_iter) {
                    auto size = 1;
                    auto c_iter = iter;
                    ++c_iter;
                    ++check_iter;
                    while (c_iter != this->list.end() && check_iter != list.end() && *c_iter == *check_iter) {
                        ++c_iter;
                        ++check_iter;
                        ++size;
                    }
                    if (check_iter == list.end()) {
                        if (size > ItemType::max_size) {
                            std::cerr << "Error: List item max_size overshoot: " << size << "\n";
                            return {.start = 0, .size = 0};
                        }
                        return {.start = (typename ItemType::int_type) index, .size = (typename ItemType::int_type) size};
                    } else if (c_iter == this->list.end()) {
                        do {
                            this->list.push_back(*check_iter);
                            ++check_iter;
                            ++size;
                        } while (check_iter != list.end());
                        if (size > ItemType::max_size) {
                            std::cerr << "Error: List item max_size overshoot: " << size << "\n";
                            return {.start = 0, .size = 0};
                        }
                        if (index > ItemType::max_address) {
                            std::cerr << "Error: List total size overshoot: " << index << "\n";
                        }
                        return {.start = (typename ItemType::int_type) index, .size = (typename ItemType::int_type) size};
                    }
                    check_iter = list.begin();
                }
                ++iter;
                ++index;
            }
        }
        auto start = this->list.size();
        if (start > ItemType::max_address) {
            std::cerr << "Error: Lists max count overshoot: " << start << "\n";
            return {.start = 0, .size = 0};
        }
        size_t size = 0;
        for (const auto &item : list) {
            this->list.emplace_back(item);
            ++size;
        }
        if (size > ItemType::max_size) {
            std::cerr << "Error: List item max_size overshoot: " << size << "\n";
            return {.start = 0, .size = 0};
        }
        return {.start = (uint32_t) start, .size = (uint32_t) size};
    }
    ItemType StoreList(const std::vector<T> &list, uint32_t startHint) {
        {
            auto check_iter = list.begin();
            if (check_iter == list.end()) {
                return {.start = 0, .size = 0};
            }
            size_t index = 0;
            auto iter = this->list.begin();
            while (iter != this->list.end()) {
                if (*iter == *check_iter) {
                    auto size = 1;
                    auto c_iter = iter;
                    ++c_iter;
                    ++check_iter;
                    while (c_iter != this->list.end() && check_iter != list.end() && *c_iter == *check_iter) {
                        ++c_iter;
                        ++check_iter;
                        ++size;
                    }
                    if (check_iter == list.end() && index == startHint) {
                        if (size > ItemType::max_size) {
                            std::cerr << "Error: List item max_size overshoot: " << size << "\n";
                            return {.start = 0, .size = 0};
                        }
                        return {.start = (typename ItemType::int_type) index, .size = (typename ItemType::int_type) size};
                    } else if (c_iter == this->list.end() && index == startHint) {
                        do {
                            this->list.push_back(*check_iter);
                            ++check_iter;
                            ++size;
                        } while (check_iter != list.end());
                        if (size > ItemType::max_size) {
                            std::cerr << "Error: List item max_size overshoot: " << size << "\n";
                            return {.start = 0, .size = 0};
                        }
                        if (index > ItemType::max_address) {
                            std::cerr << "Error: List total size overshoot: " << index << "\n";
                        }
                        return {.start = (typename ItemType::int_type) index, .size = (typename ItemType::int_type) size};
                    }
                    check_iter = list.begin();
                }
                ++iter;
                ++index;
            }
        }
        auto start = this->list.size();
        if (start > ItemType::max_address) {
            std::cerr << "Error: Lists max count overshoot: " << start << "\n";
            return {.start = 0, .size = 0};
        }
        size_t size = 0;
        for (const auto &item : list) {
            this->list.emplace_back(item);
            ++size;
        }
        if (size > ItemType::max_size) {
            std::cerr << "Error: List item max_size overshoot: " << size << "\n";
            return {.start = 0, .size = 0};
        }
        return {.start = (typename ItemType::int_type) start, .size = (typename ItemType::int_type) size};
    }
    [[nodiscard]] std::vector<T> RetrieveList(const ItemType &litems) const {
        size_t size = litems.size;
        if (size <= 0) {
            return {};
        }
        size_t index = litems.start;
        if (index < 0 || index >= list.size()) {
            std::cerr << "Error: Index out of bounds: " << index << "\n";
            return {};
        }
        auto end_index = index + size;
        if (end_index > list.size()) {
            std::cerr << "Error: Index range out of bounds: " << index << " - " << end_index << " (<-culprit)\n";
            end_index = list.size();
        }
        std::vector<T> result;
        for (auto i = index; i < end_index; i++) {
            result.push_back(list[i]);
        }
        return result;
    }
    [[nodiscard]] std::vector<T> GetList() const {
        return list;
    }
    [[nodiscard]] size_t GetSize() const {
        return list.size();
    }
};

template <GenericListStorageObject T> class GenericListStorage32 : public GenericListStorage<T,GenericListItems32> {};
template <GenericListStorageObject T> class GenericListStorage64 : public GenericListStorage<T,GenericListItems64> {};

template <class T> concept GenericListStorage32Type = requires (T list) {
    { list.StoreList(std::declval<std::vector<typename T::ListItemType>>()) }
    -> std::convertible_to<GenericListItems32>;
};
template <class T> concept GenericListStorage64Type = requires (T list) {
    { list.StoreList(std::declval<std::vector<typename T::ListItemType>>()) }
    -> std::convertible_to<GenericListItems64>;
};

#endif //LEGEMFEST_GENERICLISTSTORAGE_H
