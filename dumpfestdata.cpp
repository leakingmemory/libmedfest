//
// Created by sigsegv on 1/15/23.
//

#include "cppmain.h"
#include "FestDeserializer.h"
#include "Struct/Decoded/OppfLegemiddelMerkevare.h"
#include "Struct/Decoded/OppfLegemiddelpakning.h"
#include "Struct/Decoded/OppfLegemiddelVirkestoff.h"
#include "Struct/Decoded/OppfHandelsvare.h"

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
    std::cout << "Pakningskomponenter lists storage dump:\n";
    for (const auto &pp : festDeserializer.GetPakningskomponent()) {
        auto p = festDeserializer.Unpack(pp);
        auto antall = p.GetAntall();
        std::cout << " ";
        if (antall != 0) {
            std::cout << antall << " X ";
        }
        auto mengde = p.GetMengde();
        std::cout << mengde.GetValue() << " " << mengde.GetUnit() << " " << p.GetPakningstype().GetValue() << "\n";
    }
    std::cout << "Pakningsinfo lists storage dump:\n";
    for (const auto &ppi : festDeserializer.GetPakningsinfo()) {
        auto pi = festDeserializer.Unpack(ppi);
        std::cout << " " << pi.GetMerkevareId() << " " << pi.GetPakningsstr() << " " << pi.GetEnhetPakning().GetValue()
                  << " " << pi.GetPakningstype().GetValue() << "/" << pi.GetPakningstype().GetDistinguishedName()
                  << " " << pi.GetMengde()<< " " << pi.GetDDD().GetValue() << " " << pi.GetStatistikkfaktor()
                  << " " << pi.GetAntall() << " " << pi.GetMultippel() << " (";
        for (const auto &p : pi.GetPakningskomponent()) {
            auto antall = p.GetAntall();
            std::cout << " ";
            if (antall != 0) {
                std::cout << antall << " X ";
            }
            auto mengde = p.GetMengde();
            std::cout << mengde.GetValue() << " " << mengde.GetUnit() << " " << p.GetPakningstype().GetValue() << ", ";
        }
        std::cout << " end)\n";
    }
    std::cout << "Refusjon list storage dump:\n";
    for (const auto &r : festDeserializer.GetRefusjon()) {
        auto refusjon = festDeserializer.Unpack(r);
        std::cout << "Ref:";
        for (const auto &id : refusjon.GetRefRefusjonsgruppe()) {
            std::cout << " " << id;
        }
        std::cout << ": " << refusjon.GetGyldigFraDato() << " " << refusjon.GetForskrivesTilDato() << " "
                  << refusjon.GetUtleveresTilDato() << "\n";
    }
    std::cout << "String list storage dump:\n";
    for (const auto &ps : festDeserializer.GetStringList()) {
        auto str = festDeserializer.Unpack(ps);
        std::cout << " " << str << "\n";
    }
    std::cout << "Pris vare list storage dump:\n";
    for (const auto &ppv : festDeserializer.GetPrisVare()) {
        auto pv = festDeserializer.Unpack(ppv);
        std::cout << " " << pv.GetType().GetDistinguishedName() << ": " << pv.GetPris().GetValue() << " "
                  << pv.GetPris().GetUnit() << " " << pv.GetGyldigFraDato() << " " << pv.GetGyldigTilDato() << "\n";
    }
    std::cout << "Merkevarer:\n";
    festDeserializer.ForEachMerkevare([&festDeserializer] (const POppfLegemiddelMerkevare &poppf) {
        auto oppf = festDeserializer.Unpack(poppf);
        auto legemiddel = oppf.GetLegemiddelMerkevare();
        std::cout << oppf.GetId() << " " << oppf.GetTidspunkt() << " " << oppf.GetStatus().GetValue() << ": "
                  << legemiddel.GetId() << "\n";
        std::cout << " " << legemiddel.GetNavnFormStyrke() << " (" << legemiddel.GetReseptgruppe().GetValue() << ")\n";
    });
    std::cout << "Pakninger:\n";
    festDeserializer.ForEachPakning([&festDeserializer] (const POppfLegemiddelpakning &poppf) {
        auto oppf = festDeserializer.Unpack(poppf);
        auto legemiddel = oppf.GetLegemiddelpakning();
        std::cout << oppf.GetId() << " " << oppf.GetTidspunkt() << " " << oppf.GetStatus().GetValue() << ": "
                  << legemiddel.GetId() << "\n";
        std::cout << " " << legemiddel.GetNavnFormStyrke() << " (" << legemiddel.GetReseptgruppe().GetValue() << ")\n";
        for (auto &pi : legemiddel.GetPakningsinfo()) {
            std::cout << "  - " << pi.GetPakningsstr() << "\n";
        }
    });
    std::cout << "Legemiddel virkestoff:\n";
    festDeserializer.ForEachLegemiddelVirkestoff([&festDeserializer] (const POppfLegemiddelVirkestoff &poppf) {
        auto oppf = festDeserializer.Unpack(poppf);
        auto legemiddel = oppf.GetLegemiddelVirkestoff();
        std::cout << oppf.GetId() << " " << oppf.GetTidspunkt() << " " << oppf.GetStatus().GetValue() << ": "
                  << legemiddel.GetId() << "\n";
        std::cout << " " << legemiddel.GetNavnFormStyrke() << " (" << legemiddel.GetReseptgruppe().GetValue() << ")\n";
    });
    std::cout << "Med forbr matr:\n";
    festDeserializer.ForEachMedForbrMatr([&festDeserializer] (const POppfMedForbrMatr &poppf) {
        auto oppf = festDeserializer.Unpack(poppf);
        auto handelsvare = oppf.GetMedForbrMatr();
        std::cout << oppf.GetId() << " " << oppf.GetTidspunkt() << " " << oppf.GetStatus().GetValue() << ": "
                  << handelsvare.GetNr() << " " << handelsvare.GetNavn() << "\n";
        for (const auto &refId : handelsvare.GetRefusjon().GetRefRefusjonsgruppe()) {
            std::cout << " - " << refId << "\n";
        }
    });
    return 0;
}
