//
// Created by sigsegv on 1/15/23.
//

#include "cppmain.h"
#include "FestDeserializer.h"
#include "Struct/Decoded/OppfLegemiddelMerkevare.h"
#include "Struct/Decoded/OppfLegemiddelpakning.h"
#include "Struct/Decoded/OppfLegemiddelVirkestoff.h"
#include "Struct/Decoded/OppfHandelsvare.h"
#include "Struct/Decoded/OppfLegemiddeldose.h"
#include "Struct/Decoded/OppfVirkestoffMedStyrke.h"
#include "Struct/Decoded/OppfVirkestoff.h"
#include "Struct/Decoded/OppfKodeverk.h"
#include "Struct/Decoded/OppfRefusjon.h"
#include "Struct/Decoded/OppfVilkar.h"

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
    std::cout << "Pakningskomponent info lists storage dump:\n";
    for (const auto &pp : festDeserializer.GetPakningskomponentInfo()) {
        auto p = festDeserializer.Unpack(pp);
        auto mengde = p.GetMengde();
        std::cout << " " << mengde.GetValue() << " " << mengde.GetUnit() << " " << p.GetPakningstype().GetValue() << "\n";
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
    std::cout << "Kodeverk element list storage dump:\n";
    for (const auto &pelement : festDeserializer.GetElement()) {
        auto element = festDeserializer.Unpack(pelement);
        auto term = element.GetTerm();
        auto sprak = term.GetSprak();
        std::cout << " " << element.GetId() << " " << element.GetKode() << " " << sprak.GetDistinguishedName()
                  << " " << term.GetTerm() << " " << term.GetBeskrivelseTerm() << "\n";
    }
    std::cout << "Ref refusjonsvilkar list storage dump:\n";
    for (const auto &pref : festDeserializer.GetRefRefusjonsvilkar()) {
        auto refRefusjonsvilkar = festDeserializer.Unpack(pref);
        std::cout << " " << refRefusjonsvilkar.GetId() << " " << refRefusjonsvilkar.GetFraDato() << "\n";
    }
    std::cout << "Refusjonskode list storage dump:\n";
    for (const auto &pref : festDeserializer.GetRefusjonskode()) {
        auto refusjonskode = festDeserializer.Unpack(pref);
        std::cout << " " << refusjonskode.GetGyldigFraDato() << " " << refusjonskode.GetForskrivesTilDato() << " "
                  << refusjonskode.GetRefusjonskode().GetDistinguishedName() << "\n";
        for (const auto &term : refusjonskode.GetUnderterm()) {
            std::cout << "   - " << term << "\n";
        }
        for (const auto &refRefusjonsvilkar : refusjonskode.GetRefusjonsvilkar()) {
            std::cout << "  - " << refRefusjonsvilkar.GetId() << " " << refRefusjonsvilkar.GetFraDato() << "\n";
        }
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
    std::cout << "Naringsmiddel:\n";
    festDeserializer.ForEachNaringsmiddel([&festDeserializer] (const POppfNaringsmiddel &poppf) {
        auto oppf = festDeserializer.Unpack(poppf);
        auto handelsvare = oppf.GetNaringsmiddel();
        std::cout << oppf.GetId() << " " << oppf.GetTidspunkt() << " " << oppf.GetStatus().GetValue() << ": "
                  << handelsvare.GetNr() << " " << handelsvare.GetNavn() << "\n";
        for (const auto &refId : handelsvare.GetRefusjon().GetRefRefusjonsgruppe()) {
            std::cout << " - " << refId << "\n";
        }
    });
    std::cout << "Brystprotese:\n";
    festDeserializer.ForEachBrystprotese([&festDeserializer] (const POppfBrystprotese &poppf) {
        auto oppf = festDeserializer.Unpack(poppf);
        auto handelsvare = oppf.GetBrystprotese();
        std::cout << oppf.GetId() << " " << oppf.GetTidspunkt() << " " << oppf.GetStatus().GetValue() << ": "
                  << handelsvare.GetNr() << " " << handelsvare.GetNavn() << "\n";
        for (const auto &refId : handelsvare.GetRefusjon().GetRefRefusjonsgruppe()) {
            std::cout << " - " << refId << "\n";
        }
    });
    std::cout << "Legemiddeldose:\n";
    festDeserializer.ForEachLegemiddeldose([&festDeserializer] (const POppfLegemiddeldose &poppf) {
        auto oppf = festDeserializer.Unpack(poppf);
        auto legemiddeldose = oppf.GetLegemiddeldose();
        std::cout << oppf.GetId() << " " << oppf.GetTidspunkt() << " " << oppf.GetStatus().GetValue() << ": "
                  << legemiddeldose.GetId() << " " << legemiddeldose.GetLmrLopenr() << " "
                  << legemiddeldose.GetMengde().GetValue() << legemiddeldose.GetMengde().GetUnit()
                  << "\n - Merkevare:";
        for (const auto &merkevareId : legemiddeldose.GetRefLegemiddelMerkevare()) {
            std::cout << " " << merkevareId;
        }
        std::cout << "\n - Pakning:";
        for (const auto &pakningId : legemiddeldose.GetRefPakning()) {
            std::cout << " " << pakningId;
        }
        std::cout << "\n - Pakningskomponent:";
        for (const auto &pakningskomponent : legemiddeldose.GetPakningskomponent()) {
            std::cout << " <" << pakningskomponent.GetMengde().GetValue() << " " << pakningskomponent.GetMengde().GetUnit()
                      << " " << pakningskomponent.GetPakningstype().GetDistinguishedName() << ">";
        }
        std::cout << "\n";
    });
    std::cout << "Virkestoff med styrke:\n";
    festDeserializer.ForEachVirkestoffMedStyrke([&festDeserializer] (const POppfVirkestoffMedStyrke &poppf) {
        auto oppf = festDeserializer.Unpack(poppf);
        auto virkestoffMedStyrke = oppf.GetVirkestoffMedStyrke();
        auto styrke = virkestoffMedStyrke.GetStyrke();
        auto styrkenevner = virkestoffMedStyrke.GetStyrkenevner();
        std::cout << oppf.GetId() << " " << oppf.GetTidspunkt() << " " << oppf.GetStatus().GetValue() << ": "
                  << virkestoffMedStyrke.GetId() << " ref " << virkestoffMedStyrke.GetRefVirkestoff() << ": "
                  << styrke.GetValue() << " " << styrke.GetUnit() << " / "  << styrkenevner.GetValue()
                  << styrkenevner.GetUnit() << " " << virkestoffMedStyrke.GetStyrkeoperator().GetDistinguishedName()
                  << " " << virkestoffMedStyrke.GetStyrkeOvreVerdi() << "\n";
    });
    std::cout << "Virkestoff:\n";
    festDeserializer.ForEachVirkestoff([&festDeserializer] (const POppfVirkestoff &poppf) {
        auto oppf = festDeserializer.Unpack(poppf);
        auto virkestoff = oppf.GetVirkestoff();
        std::cout << oppf.GetId() << " " << oppf.GetTidspunkt() << " " << oppf.GetStatus().GetValue() << ": "
                  << virkestoff.GetId() << " " << virkestoff.GetNavn() << " " << virkestoff.GetNavnEngelsk() << "\n";
        for (const auto &v : virkestoff.GetRefVirkestoff()) {
            std::cout << " - " << v << "\n";
        }
    });
    std::cout << "Kodeverk:\n";
    festDeserializer.ForEachKodeverk([&festDeserializer] (const POppfKodeverk &poppf) {
        auto oppf = festDeserializer.Unpack(poppf);
        auto info = oppf.GetInfo();
        std::cout << " " << oppf.GetId() << " " << oppf.GetTidspunkt() << " " << oppf.GetStatus().GetValue() << ": "
                  << info.GetId() << " " << info.GetKortnavn() << " " << info.GetBetegnelse() << " "
                  << info.GetAnsvarligUtgiver() << "\n";
        for (const auto &element : oppf.GetElement()) {
            auto term = element.GetTerm();
            auto sprak = term.GetSprak();
            std::cout << "  - " << element.GetId() << " " << element.GetKode() << " " << sprak.GetDistinguishedName()
                      << " " << term.GetTerm() << " " << term.GetBeskrivelseTerm() << "\n";
        }
    });
    std::cout << "Refusjon:\n";
    festDeserializer.ForEachRefusjon([&festDeserializer] (const POppfRefusjon &poppf) {
        auto oppf = festDeserializer.Unpack(poppf);
        auto refusjonshjemmel = oppf.GetRefusjonshjemmel();
        std::cout << " " << oppf.GetId() << " " << oppf.GetTidspunkt() << " " << oppf.GetStatus().GetValue() << ": "
                  << (refusjonshjemmel.GetKreverVedtak() ? " krever vedtak: " : "")
                  << (refusjonshjemmel.GetKreverVarekobling() ? "krever varekobling: " : "")
                  << refusjonshjemmel.GetRefusjonshjemmel().GetDistinguishedName() << "\n";
        auto refusjonsgruppe = refusjonshjemmel.GetRefusjonsgruppe();
        std::cout << "  " << refusjonsgruppe.GetAtc().GetValue() << " " << refusjonsgruppe.GetId() << " "
                  << refusjonsgruppe.GetGruppeNr().GetValue() << ": " << refusjonsgruppe.GetRefusjonsberettigetBruk()
                  << "\n";
        for (const auto &refVilkar : refusjonsgruppe.GetRefVilkar()) {
            std::cout << "    - " << refVilkar << "\n";
        }
        for (const auto &refusjonskode : refusjonsgruppe.GetRefusjonskode()) {
            std::cout << "  * " << refusjonskode.GetGyldigFraDato() << " " << refusjonskode.GetForskrivesTilDato() << " "
                      << refusjonskode.GetRefusjonskode().GetDistinguishedName() << "\n";
            for (const auto &term : refusjonskode.GetUnderterm()) {
                std::cout << "    - " << term << "\n";
            }
            for (const auto &refRefusjonsvilkar : refusjonskode.GetRefusjonsvilkar()) {
                std::cout << "   - " << refRefusjonsvilkar.GetId() << " " << refRefusjonsvilkar.GetFraDato() << "\n";
            }
        }
    });
    std::cout << "Vilkar:\n";
    festDeserializer.ForEachVilkar([&festDeserializer] (const POppfVilkar &poppf) {
        auto oppf = festDeserializer.Unpack(poppf);
        auto vilkar = oppf.GetVilkar();
        std::cout << " " << oppf.GetId() << " " << oppf.GetTidspunkt() << " " << oppf.GetStatus().GetValue() << ": "
                  << vilkar.GetId() << " " << vilkar.GetVilkarNr() << " " << vilkar.GetGyldigFraDato() << " "
                  << vilkar.GetGjelderFor().GetDistinguishedName() << " " << vilkar.GetGruppe().GetDistinguishedName()
                  << " " << vilkar.GetTekst() << "\n  ";
        auto strukturertVilkar = vilkar.GetStrukturertVilkar();
        std::cout << strukturertVilkar.GetType().GetDistinguishedName() << " "
                  << strukturertVilkar.GetVerdiKodet().GetDistinguishedName() << " "
                  << strukturertVilkar.GetVerdiTekst() << "\n";
    });
    return 0;
}
