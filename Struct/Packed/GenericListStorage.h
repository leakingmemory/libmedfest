//
// Created by sigsegv on 1/4/23.
//

#ifndef LEGEMFEST_GENERICLISTSTORAGE_H
#define LEGEMFEST_GENERICLISTSTORAGE_H

#include <concepts>
#include <cstdint>
#include <vector>
#include <iostream>

template <typename T> concept GenericListStorageObject = requires (T tp) {
    {tp == std::declval<T>()} -> std::convertible_to<bool>;
};

struct GenericListItems {
    typedef uint32_t int_type;
    constexpr static int total_bits = sizeof(int_type) * 8;
    constexpr static int size_bits = 8;
    constexpr static int addr_bits = total_bits - size_bits;
    constexpr static int_type max_address = (1 << addr_bits) - 1;
    constexpr static int_type max_size = (1 << size_bits) - 1;
    int_type start : addr_bits;
    int_type size : size_bits;
} __attribute__((__packed__));
static_assert(sizeof(GenericListItems) == sizeof(GenericListItems::int_type));

template <GenericListStorageObject T> class GenericListStorage {
private:
    std::vector<T> list;
public:
    GenericListStorage() : list() {}
    GenericListItems StoreList(const std::vector<T> &list) {
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
                        if (size > GenericListItems::max_size) {
                            std::cerr << "Error: List item max_size overshoot: " << size << "\n";
                            return {.start = 0, .size = 0};
                        }
                        return {.start = (uint32_t) index, .size = (uint32_t) size};
                    } else if (c_iter == this->list.end()) {
                        do {
                            this->list.push_back(*check_iter);
                            ++check_iter;
                            ++size;
                        } while (check_iter != list.end());
                        if (size > GenericListItems::max_size) {
                            std::cerr << "Error: List item max_size overshoot: " << size << "\n";
                            return {.start = 0, .size = 0};
                        }
                        return {.start = (uint32_t) index, .size = (uint32_t) size};
                    }
                    check_iter = list.begin();
                }
                ++iter;
                ++index;
            }
        }
        auto start = this->list.size();
        if (start > GenericListItems::max_address) {
            std::cerr << "Error: Lists max count overshoot: " << start << "\n";
            return {.start = 0, .size = 0};
        }
        size_t size = 0;
        for (const auto &item : list) {
            this->list.emplace_back(item);
            ++size;
        }
        if (size > GenericListItems::max_size) {
            std::cerr << "Error: List item max_size overshoot: " << size << "\n";
            return {.start = 0, .size = 0};
        }
        return {.start = (uint32_t) start, .size = (uint32_t) size};
    }
    [[nodiscard]] std::vector<T> RetrieveList(const GenericListItems &litems) const {
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

#endif //LEGEMFEST_GENERICLISTSTORAGE_H
