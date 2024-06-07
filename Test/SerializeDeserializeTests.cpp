//
// Created by sigsegv on 6/7/24.
//

#include "FestSerializer.h"
#include <sstream>
#include <iostream>
#include <functional>

static std::string WriteFest(const std::function<void (FestSerializer &)> &func) {
    std::shared_ptr<std::stringstream> sstr = std::make_shared<std::stringstream>();
    FestSerializer festSerializer{sstr};
    func(festSerializer);
    if (!festSerializer.Write()) {
        std::cerr << "Write FEST failed\n";
        throw std::exception();
    }
    return sstr->str();
}

static std::string WriteFestVersion(const std::function<void (FestSerializer &)> &func, uint8_t major, uint8_t minor, uint8_t patch) {
    std::shared_ptr<std::stringstream> sstr = std::make_shared<std::stringstream>();
    FestSerializer festSerializer{sstr};
    func(festSerializer);
    if (!festSerializer.WriteVersion(major, minor, patch)) {
        std::cerr << "Write FEST failed\n";
        throw std::exception();
    }
    return sstr->str();
}

int main() {
    std::string emptyDb = WriteFest([] (auto &) {});
    std::cout << "Empty DB size " << emptyDb.size() << "\n";
    std::string emptyDb_0_2_0 = WriteFestVersion([] (auto &) {}, 0, 2, 0);
    std::cout << "Empty DB v0.2.0 size " << emptyDb_0_2_0.size() << "\n";
    std::string emptyDb_0_1_0 = WriteFestVersion([] (auto &) {}, 0, 1, 0);
    std::cout << "Empty DB v0.1.0 size " << emptyDb_0_1_0.size() << "\n";
    std::string emptyDb_0_0_0 = WriteFestVersion([] (auto &) {}, 0, 0, 0);
    std::cout << "Empty DB v0.0.0 size " << emptyDb_0_0_0.size() << "\n";
}