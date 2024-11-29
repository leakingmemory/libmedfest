//
// Created by sigsegv on 1/2/23.
//

#ifndef LEGEMFEST_PSTRING_H
#define LEGEMFEST_PSTRING_H

#include <cstdint>
#include <string>
#include <map>
#include <limits>

class FestDeserializer;

class PString {
    friend FestDeserializer;
public:
    typedef uint32_t Type;
    static constexpr Type Max = std::numeric_limits<Type>::max();
private:
    Type offset;
public:
    constexpr PString() : offset(Max) {}
    PString(const std::string &str, std::string &textblock, std::map<std::string,uint32_t> &cache);
    constexpr explicit PString(uint32_t offset) : offset(offset) {}
    constexpr PString(const PString &cp) : offset(cp.offset) {}
    constexpr PString(PString &&mv) : offset(mv.offset) {}
    constexpr PString & operator = (const PString &cp) {
        offset = cp.offset;
        return *this;
    }
    constexpr PString & operator = (PString &&mv) {
        offset = mv.offset;
        return *this;
    }
    [[nodiscard]] std::string ToString(const char *textblock, size_t size) const;
    [[nodiscard]] std::string ToString(const std::string &textblock) const;
    constexpr bool operator == (const PString other) const {
        return offset == other.offset;
    }
};


#endif //LEGEMFEST_PSTRING_H
