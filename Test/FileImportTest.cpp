//
// Created by sigsegv on 8/20/24.
//

#include <cstdlib>
#include <string>
#include <iostream>
#include <memory>
#include <sstream>
#include "FestZip.h"
#include "FestSerializer.h"
#include "FestDeserializer.h"
#include "FestVectors.h"

int main() {
    std::string festFileName{};
    {
        const char *festFileCstr = getenv("FEST_FILE");
        if (festFileCstr != nullptr) {
            festFileName.append(festFileCstr);
        }
    }
    if (festFileName.empty()) {
        std::cout << "Import from file test disabled (set env FEST_FILE)\n";
        return 0;
    }
    FestZip festZip{festFileName};
    auto decoded = festZip.Decode();
    if (!decoded) {
        std::cerr << "Error: Decoding failed\n";
        return 1;
    }
    std::string db{};
    {
        std::shared_ptr<std::stringstream> sstr = std::make_shared<std::stringstream>();
        FestSerializer festSerializer{sstr};
        festSerializer.Serialize(*decoded);
        if (!festSerializer.Write()) {
            std::cerr << "Write FEST failed\n";
            throw std::exception();
        }
        db = sstr->str();
    }
    std::cout << "Imported DB " << db.length() << " bytes\n";
    FestDeserializer festDeserializer{db.data(), db.length()};
    festDeserializer.ForEachFests([&festDeserializer] (const auto &pfest) {
        auto fest = festDeserializer.Unpack(pfest);
        std::cout << fest.GetDato() << "\n";
    });
}