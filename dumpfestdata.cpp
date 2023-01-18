//
// Created by sigsegv on 1/15/23.
//

#include "cppmain.h"
#include "FestDeserializer.h"
#include "Struct/Decoded/OppfLegemiddelMerkevare.h"

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
    std::cout << "Reseptgyldighet lists storage dump:\n";
    for (const auto &rg : festDeserializer.GetReseptgyldighet()) {
        auto rgv = festDeserializer.Unpack(rg);
        std::cout << rgv.GetVarighet() << " " << rgv.GetKjonn().GetValue() << " " << rgv.GetKjonn().GetDistinguishedName() << "\n";
    }
    std::cout << "Value with code set lists storage dump:\n";
    for (const auto &rv : festDeserializer.GetValueWithCodeset()) {
        auto v = festDeserializer.Unpack(rv);
        std::cout << v.GetValue() << " " << v.GetDistinguishedName() << " " << v.GetCodeSet() << "\n";
    }
    std::cout << "Fest uuids:\n";
    for (const auto &uuid : festDeserializer.GetFestIds()) {
        std::cout << uuid.ToString() << "\n";
    }
    std::cout << "Fest uuid lists storage dump:\n";
    for (const auto &id : festDeserializer.GetFestIdLists()) {
        std::cout << festDeserializer.Unpack(id).ToString() << "\n";
    }
    std::cout << "Merkevarer:\n";
    festDeserializer.ForEachMerkevare([&festDeserializer] (const POppfLegemiddelMerkevare &poppf) {
        auto oppf = festDeserializer.Unpack(poppf);
        auto legemiddel = oppf.GetLegemiddelMerkevare();
        std::cout << oppf.GetId() << " " << oppf.GetTidspunkt() << " " << oppf.GetStatus().GetValue() << ": "
                  << legemiddel.GetId() << "\n";
        std::cout << " " << legemiddel.GetNavnFormStyrke() << " (" << legemiddel.GetReseptgruppe().GetValue() << ")\n";
    });
    return 0;
}
