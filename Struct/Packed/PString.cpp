//
// Created by sigsegv on 1/2/23.
//

#include "PString.h"

PString::PString(const std::string &str, std::string &textblock) {
    int pos = 0;
    while (pos < textblock.size()) {
        pos = textblock.find(str, pos);
        if (pos < textblock.size()) {
            if (textblock[pos + str.size()] == '\0') {
                this->offset = pos;
                return;
            } else {
                ++pos;
            }
        }
    }
    if (textblock.size() > 0) {
        textblock.append(1, '\0');
    }
    this->offset = textblock.size();
    textblock.append(str);
}

std::string PString::ToString(const char *textblock, size_t size) const {
    auto offset = this->offset;
    if (offset < size) {
        auto end = offset;
        while (end < size && textblock[end] != '\0') {
            ++end;
        }
        std::string result{};
        result.append(textblock + offset, end - offset);
        return result;
    }
    return "";
}

std::string PString::ToString(const std::string &textblock) const {
    return ToString(textblock.c_str(), textblock.size());
}