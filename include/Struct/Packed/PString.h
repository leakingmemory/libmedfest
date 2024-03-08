//
// Created by sigsegv on 1/2/23.
//

#ifndef LEGEMFEST_PSTRING_H
#define LEGEMFEST_PSTRING_H

#include <cstdint>
#include <string>
#include <map>

class FestDeserializer;

class PString {
    friend FestDeserializer;
private:
    uint32_t offset;
public:
    PString() : offset(0) {}
    PString(const std::string &str, std::string &textblock, std::map<std::string,uint32_t> &cache);
    explicit PString(uint32_t offset) : offset(offset) {}
    [[nodiscard]] std::string ToString(const char *textblock, size_t size) const;
    [[nodiscard]] std::string ToString(const std::string &textblock) const;
    bool operator == (const PString other) const {
        return offset == other.offset;
    }
};


#endif //LEGEMFEST_PSTRING_H
