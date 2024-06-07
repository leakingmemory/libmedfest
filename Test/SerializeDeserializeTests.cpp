//
// Created by sigsegv on 6/7/24.
//

#include "FestSerializer.h"
#include "FestDeserializer.h"
#include "FestVectors.h"
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

std::vector<FestVectors> GetFestVectors(const FestDeserializer &festDeserializer) {
    std::vector<FestVectors> festVectors{};
    festDeserializer.ForEachFests([&festDeserializer, &festVectors] (const PFest &pFest) {
        auto fest = festDeserializer.Unpack(pFest);
        festVectors.emplace_back(fest);
    });
    return festVectors;
}

void AssertVersion(const FestDeserializer &deserializer, int major, int minor , int patch) {
    if (deserializer.GetVersionMajor() != major) {
        std::cerr << "Expected major version " << major << ", but found " << deserializer.GetVersionMajor() << "\n";
        exit(1);
    }
    if (deserializer.GetVersionMinor() != minor) {
        std::cerr << "Expected minor version " << minor << ", but found " << deserializer.GetVersionMinor() << "\n";
        exit(1);
    }
    if (deserializer.GetVersionPatch() != patch) {
        std::cerr << "Expected patch version " << patch << ", but found " << deserializer.GetVersionPatch() << "\n";
        exit(1);
    }
}

template <class T> void AssertSize(const std::vector<T> &vec, size_t size) {
    if (vec.size() != size) {
        std::cerr << "Size mismatch, expected " << size << ", found " << vec.size() << "\n";
        exit(1);
    }
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

    FestDeserializer festDeserializer{emptyDb.data(), emptyDb.size()};
    {
        AssertVersion(festDeserializer, 0, 2, 0);
        auto festVectors = GetFestVectors(festDeserializer);
        AssertSize(festVectors, 0);
    }
    FestDeserializer festDeserializer_0_2_0{emptyDb_0_2_0.data(), emptyDb_0_2_0.size()};
    {
        AssertVersion(festDeserializer_0_2_0, 0, 2, 0);
        auto festVectors = GetFestVectors(festDeserializer);
        AssertSize(festVectors, 0);
    }
    FestDeserializer festDeserializer_0_1_0{emptyDb_0_1_0.data(), emptyDb_0_1_0.size()};
    {
        AssertVersion(festDeserializer_0_1_0, 0, 1, 0);
        auto festVectors = GetFestVectors(festDeserializer);
        AssertSize(festVectors, 0);
    }
    FestDeserializer festDeserializer_0_0_0{emptyDb_0_0_0.data(), emptyDb_0_0_0.size()};
    {
        AssertVersion(festDeserializer_0_0_0, 0, 0, 0);
        auto festVectors = GetFestVectors(festDeserializer);
        AssertSize(festVectors, 0);
    }
}