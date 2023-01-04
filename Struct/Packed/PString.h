//
// Created by sigsegv on 1/2/23.
//

#ifndef LEGEMFEST_PSTRING_H
#define LEGEMFEST_PSTRING_H

#include <cstdint>
#include <string>

class PString {
private:
    uint32_t offset;
public:
    PString(const std::string &str, std::string &textblock);
    [[nodiscard]] std::string ToString(const std::string &textblock) const;
};


#endif //LEGEMFEST_PSTRING_H
