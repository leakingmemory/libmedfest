//
// Created by sigsegv on 1/2/23.
//

#include <Struct/Packed/PString.h>

constexpr int endMatchSizeLim = 48;

PString::PString(const std::string &str, std::string &textblock, std::map<std::string,uint32_t> &cache) {
    {
        auto iterator = cache.find(str);
        if (iterator != cache.end()) {
            this->offset = iterator->second;
            return;
        }
    }
    if constexpr(endMatchSizeLim > 0) {
        if (endMatchSizeLim <= str.size()) {
            bool found{false};
            int pos{0};
            for (auto [s, p] : cache) {
                if (s.size() > str.size()) {
                    auto off = s.size() - str.size();
                    auto endstr = s.substr(off);
                    if (endstr == str) {
                        auto fpos = p + off;
                        if (found) {
                            if (fpos < pos) {
                                pos = fpos;
                            }
                        } else {
                            found = true;
                            pos = fpos;
                        }
                    }
                }
            }
            if (found) {
                this->offset = pos;
                cache.insert_or_assign(str, this->offset);
                return;
            } else {
                if (textblock.size() > 0) {
                    textblock.append(1, '\0');
                }
                this->offset = textblock.size();
                cache.insert_or_assign(str, this->offset);
                textblock.append(str);
                return;
            }
        }
    }

    if (textblock.size() > 0) {
        if (str.size() == 0) {
            int pos = textblock.find('\0');
            if (pos < textblock.size()) {
                this->offset = pos;
                cache.insert_or_assign(str, pos);
                return;
            } else {
                this->offset = textblock.size();
                cache.insert_or_assign(str, this->offset);
                return;
            }
        }
        int pos = 0;
        int posOfFirst = 1;
        {
            auto first = str[0];
            auto pos = str.find(first, 1);
            while (pos < str.size()) {
                auto end = str.substr(pos, str.size() - pos);
                if (str.starts_with(end)) {
                    break;
                }
                pos = str.find(first, pos + 1);
            }
            if (pos < str.size()) {
                posOfFirst = pos;
            } else {
                posOfFirst = str.size();
            }
        }
        while (pos < textblock.size()) {
            pos = textblock.find(str, pos);
            if (pos < textblock.size()) {
                if (textblock[pos + str.size()] == '\0') {
                    this->offset = pos;
                    cache.insert_or_assign(str, pos);
                    return;
                } else {
                    pos += posOfFirst;
                }
            }
        }
        textblock.append(1, '\0');
    } else if (str.size() == 0) {
        this->offset = textblock.size();
        cache.insert_or_assign(str, this->offset);
        textblock.append(1, '\0');
        return;
    }
    this->offset = textblock.size();
    cache.insert_or_assign(str, this->offset);
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