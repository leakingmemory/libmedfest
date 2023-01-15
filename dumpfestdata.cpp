//
// Created by sigsegv on 1/15/23.
//

#include "cppmain.h"
#include "FestDeserializer.h"

int usage(const std::string &cmd) {
    std::cerr << "Usage:\n " << cmd << " <fest.bin>\n";
    return 2;
}

int cppmain(const std::string &cmd, const std::vector<std::string> &args) {
    if (args.size() != 1) {
        return usage(cmd);
    }
    auto filename = args[0];
    FestDeserializer festDeserializer{filename};
    std::cout << "Strings:\n";
    for (const auto &str : festDeserializer.GetStrings()) {
        std::cout << festDeserializer.Unpack(str) << "\n";
    }
    std::cout << "Reseptgyldighet lister:\n";
    for (const auto &rg : festDeserializer.GetReseptgyldighet()) {
        auto rgv = festDeserializer.Unpack(rg);
        std::cout << rgv.GetVarighet() << " " << rgv.GetKjonn().GetValue() << " " << rgv.GetKjonn().GetDistinguishedName() << "\n";
    }
    return 0;
}
