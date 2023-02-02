//
// Created by sigsegv on 1/3/23.
//

#include "../../../Struct/Packed/PString.h"
#include <iostream>

int main() {
    std::string block{};
    std::map<std::string,uint32_t> cache{};
    auto s0 = block.size();
    PString n1{"Hello world!", block, cache};
    if (n1.ToString(block) != "Hello world!") {
        std::cerr << "First read back 1\n";
        return 127;
    }
    auto s1 = block.size();
    PString n2{"test", block, cache};
    if (n2.ToString(block) != "test") {
        std::cerr << "First read back 2\n";
        return 127;
    }
    auto s2 = block.size();
    PString n3{"test", block, cache};
    if (n3.ToString(block) != "test") {
        std::cerr << "First read back 3\n";
        return 127;
    }
    auto s3 = block.size();
    PString n4{"world!", block, cache};
    if (n4.ToString(block) != "world!") {
        std::cerr << "First read back 4\n";
        return 127;
    }
    auto s4 = block.size();
    PString n5{"another text", block, cache};
    if (n5.ToString(block) != "another text") {
        std::cerr << "First read back 5\n";
        return 127;
    }
    cache.clear();
    auto s5 = block.size();
    if (s0 != 0) {
        std::cerr << "Ref value: s0\n";
        return 127;
    }
    if (s1 <= s0) {
        std::cerr << "s1<=s0\n";
        return 127;
    }
    if (s2 <= s1) {
        std::cerr << "s2<=s1\n";
        return 127;
    }
    if (s3 != s2) {
        std::cerr << "s3<>s2\n";
        return 127;
    }
    if (s4 != s3) {
        std::cerr << "s4<>s3\n";
        return 127;
    }
    if (s5 <= s4) {
        std::cerr << "s5<=s4\n";
        return 127;
    }
    if (n1.ToString(block) != "Hello world!") {
        std::cerr << "Second read back 1\n";
        return 127;
    }
    if (n2.ToString(block) != "test") {
        std::cerr << "Second read back 2\n";
        return 127;
    }
    if (n3.ToString(block) != "test") {
        std::cerr << "Second read back 3\n";
        return 127;
    }
    if (n4.ToString(block) != "world!") {
        std::cerr << "Second read back 4\n";
        return 127;
    }
    if (n5.ToString(block) != "another text") {
        std::cerr << "Second read back 5\n";
        return 127;
    }
    return 0;
}
