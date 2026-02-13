//
// Created by sigsegv on 12/8/22.
//

#include <Fest/Fest.h>
#include <FestDeserializer.h>
#include <FestVectors.h>
#include "KatLegemiddelMerkevare.h"
#include "KatLegemiddelVirkestoff.h"
#include "KatHandelsvare.h"
#include "KatRefusjon.h"
#include "KatVilkar.h"
#include "KatVarselSlv.h"
#include "KatKodeverk.h"
#include "KatByttegruppe.h"
#include "KatLegemiddeldose.h"
#include "KatInteraksjon.h"
#include "KatStrDosering.h"
#include "KatLegemiddelpakning.h"
#include "KatVirkestoff.h"
#include <iostream>
#include <map>

std::string HentetDato::GetName() const {
    return "HentetDato";
}

bool HentetDato::AppendCharacterData(const std::string &charData) {
    date.append(charData);
    return true;
}

void HentetDato::Merge() {
    fest->SetHentetDato(date);
}

std::string Fest::GetName() const {
    return "FEST";
}

void Fest::From(const FestDeserializer &festDeserializer, const FestVectors &festVectors) {
    hentetDato = festVectors.GetDato();
    for (const auto &pmerkevare : festVectors.GetLegemiddelMerkevare(festDeserializer)) {
        auto merkevare = festDeserializer.Unpack(pmerkevare);
        oppfLegemiddelMerkevare.emplace_back(merkevare);
    }
    for (const auto &ppakning : festVectors.GetLegemiddelPakning(festDeserializer)) {
        auto pakning = festDeserializer.Unpack(ppakning);
        oppfLegemiddelpakning.emplace_back(pakning);
    }
    for (const auto &pvirkestoff : festVectors.GetVirkestoff(festDeserializer)) {
        auto virkestoff = festDeserializer.Unpack(pvirkestoff);
        oppfVirkestoff.emplace_back(virkestoff);
    }
    for (const auto &pvirkestoffMedStyrke : festVectors.GetVirkestoffMedStyrke(festDeserializer)) {
        auto virkestoffMedStyrke = festDeserializer.Unpack(pvirkestoffMedStyrke);
        oppfVirkestoffMedStyrke.emplace_back(virkestoffMedStyrke);
    }
    for (const auto &plegemiddelVirkestoff : festVectors.GetLegemiddelVirkestoff(festDeserializer)) {
        auto legemiddelVirkestoff = festDeserializer.Unpack(plegemiddelVirkestoff);
        oppfLegemiddelVirkestoff.emplace_back(legemiddelVirkestoff);
    }
    for (const auto &pmedForbrMatr : festVectors.GetMedForbrMatr(festDeserializer)) {
        auto medForbrMatr = festDeserializer.Unpack(pmedForbrMatr);
        oppfMedForbrVare.emplace_back(medForbrMatr);
    }
    for (const auto &pnaringsmiddel : festVectors.GetNaringsmiddel(festDeserializer)) {
        auto naringsmiddel = festDeserializer.Unpack(pnaringsmiddel);
        oppfNaringsmiddel.emplace_back(naringsmiddel);
    }
    for (const auto &pbrystprotese : festVectors.GetBrystprotese(festDeserializer)) {
        auto brystprotese = festDeserializer.Unpack(pbrystprotese);
        oppfBrystprotese.emplace_back(brystprotese);
    }
    for (const auto &prefusjon : festVectors.GetRefusjon(festDeserializer)) {
        auto refusjon = festDeserializer.Unpack(prefusjon);
        oppfRefusjon.emplace_back(refusjon);
    }
    for (const auto &pvilkar : festVectors.GetVilkar(festDeserializer)) {
        auto vilkar = festDeserializer.Unpack(pvilkar);
        oppfVilkar.emplace_back(vilkar);
    }
    for (const auto &pvarselSlv : festVectors.GetVarselSlv(festDeserializer)) {
        auto varselSlv = festDeserializer.Unpack(pvarselSlv);
        oppfVarselSlv.emplace_back(varselSlv);
    }
    for (const auto &pkodeverk : festVectors.GetKodeverk(festDeserializer)) {
        auto kodeverk = festDeserializer.Unpack(pkodeverk);
        oppfKodeverk.emplace_back(kodeverk);
    }
    for (const auto &pbyttegruppe : festVectors.GetByttegruppe(festDeserializer)) {
        auto byttegruppe = festDeserializer.Unpack(pbyttegruppe);
        oppfByttegruppe.emplace_back(byttegruppe);
    }
    for (const auto &plegemiddeldose : festVectors.GetLegemiddeldose(festDeserializer)) {
        auto legemiddeldose = festDeserializer.Unpack(plegemiddeldose);
        oppfLegemiddeldose.emplace_back(legemiddeldose);
    }
    for (const auto &pinteraksjon : festVectors.GetInteraksjon(festDeserializer)) {
        auto interaksjon = festDeserializer.Unpack(pinteraksjon);
        oppfInteraksjon.emplace_back(interaksjon);
    }
    for (const auto &pinteraksjonIkkeVurdert : festVectors.GetInteraksjonIkkeVurdert(festDeserializer)) {
        auto interaksjonIkkeVurdert = festDeserializer.Unpack(pinteraksjonIkkeVurdert);
        oppfInteraksjonIkkeVurdert.emplace_back(interaksjonIkkeVurdert);
    }
    for (const auto &pstrDosering : festVectors.GetStrDosering(festDeserializer)) {
        auto strDosering = festDeserializer.Unpack(pstrDosering);
        oppfStrDosering.emplace_back(strDosering);
    }
}

void Fest::Add(const OppfLegemiddelMerkevare &oppf) {
    oppfLegemiddelMerkevare.emplace_back(oppf);
}

void Fest::Add(const XmlOppfLegemiddelMerkevare &xmlOppf) {
    oppfLegemiddelMerkevare.emplace_back(xmlOppf.GetId(), xmlOppf.GetTidspunkt(), xmlOppf.GetStatus(), xmlOppf.GetLegemiddelMerkevare());
}

void Fest::Add(const OppfLegemiddelpakning &oppf) {
    oppfLegemiddelpakning.emplace_back(oppf);
}

void Fest::Add(const XmlOppfLegemiddelpakning &xmlOppf) {
    oppfLegemiddelpakning.emplace_back(xmlOppf.GetId(), xmlOppf.GetTidspunkt(), xmlOppf.GetStatus(), xmlOppf.GetLegemiddelpakning());
}

bool Fest::Add(const XmlOppfVirkestoff &xmlOppf) {
    auto virkestoff = xmlOppf.GetVirkestoff();
    auto virkestoffMedStyrke = xmlOppf.GetVirkestoffMedStyrke();
    auto hasVirkestoff = !(virkestoff.GetId().empty());
    auto hasVirkestoffMedStyrke = !(virkestoffMedStyrke.GetId().empty());
    if (hasVirkestoff && hasVirkestoffMedStyrke) {
        std::cerr << "Error: Has both OppfVirkestoff virkestoff and virkestoff med styrke\n";
        return false;
    }
    if (!hasVirkestoff && !hasVirkestoffMedStyrke) {
        std::cerr << "Error: OppfVirkestoff has none of virkestoff and virkestoff med styrke\n";
        return false;
    }
    if (hasVirkestoff) {
        oppfVirkestoff.emplace_back(xmlOppf.GetId(), xmlOppf.GetTidspunkt(), xmlOppf.GetStatus(), virkestoff);
    } else if (hasVirkestoffMedStyrke) {
        oppfVirkestoffMedStyrke.emplace_back(xmlOppf.GetId(), xmlOppf.GetTidspunkt(), xmlOppf.GetStatus(), virkestoffMedStyrke);
    }
    return true;
}

void Fest::Add(const XmlOppfLegemiddelVirkestoff &xmlOppf) {
    oppfLegemiddelVirkestoff.emplace_back(xmlOppf.GetId(), xmlOppf.GetTidspunkt(), xmlOppf.GetStatus(), xmlOppf.GetLegemiddelVirkestoff());
}

bool Fest::Add(const XmlOppfHandelsvare &xmlOppf) {
    auto medForbrVare = xmlOppf.GetMedForbrMatr();
    auto naringsmiddel = xmlOppf.GetNaringsmiddel();
    auto brystprotese = xmlOppf.GetBrystprotese();
    auto hasMedForbrVare = !medForbrVare.GetNavn().empty() || !medForbrVare.GetNr().empty();
    auto hasNaringsmiddel = !naringsmiddel.GetNavn().empty() || !naringsmiddel.GetNr().empty();
    auto hasBrystprotese = !brystprotese.GetNavn().empty() || !brystprotese.GetNr().empty();
    {
        auto count = hasMedForbrVare ? 1 : 0;
        if (hasNaringsmiddel) {
            ++count;
        }
        if (hasBrystprotese) {
            ++count;
        }
        if (count > 1) {
            std::cerr << "Error: OppfHandelsvare: Has more than one of MedForbVare, Naringsmiddel and Brystprotese\n";
            return false;
        }
        if (count < 1) {
            std::cerr << "Error: OppfHandelsvare: Has none of MedForbVare, Naringsmiddel and Brystprotese\n";
            return false;
        }
    }
    if (hasMedForbrVare) {
        oppfMedForbrVare.emplace_back(xmlOppf.GetId(), xmlOppf.GetTidspunkt(), xmlOppf.GetStatus(), medForbrVare);
    } else if (hasNaringsmiddel) {
        oppfNaringsmiddel.emplace_back(xmlOppf.GetId(), xmlOppf.GetTidspunkt(), xmlOppf.GetStatus(), naringsmiddel);
    } else if (hasBrystprotese) {
        oppfBrystprotese.emplace_back(xmlOppf.GetId(), xmlOppf.GetTidspunkt(), xmlOppf.GetStatus(), brystprotese);
    }
    return true;
}

void Fest::Add(const XmlOppfRefusjon &oppf) {
    oppfRefusjon.emplace_back(oppf.GetId(), oppf.GetTidspunkt(), oppf.GetStatus(), oppf.GetRefusjonshjemmel());
}

void Fest::Add(const XmlOppfVilkar &oppf) {
    oppfVilkar.emplace_back(oppf.GetId(), oppf.GetTidspunkt(), oppf.GetStatus(), oppf.GetVilkar());
}

void Fest::Add(const XmlOppfVarselSlv &oppf) {
    oppfVarselSlv.emplace_back(oppf.GetId(), oppf.GetTidspunkt(), oppf.GetStatus(), oppf.GetVarselSlv());
}

void Fest::Add(const OppfKodeverk &oppf) {
    oppfKodeverk.emplace_back(oppf);
}

void Fest::Add(const OppfRefusjon &oppf) {
    oppfRefusjon.emplace_back(oppf);
}

void Fest::Add(const XmlOppfKodeverk &oppf) {
    oppfKodeverk.emplace_back(oppf.GetId(), oppf.GetTidspunkt(), oppf.GetStatus(), oppf.GetInfo(), oppf.GetElement());
}

void Fest::Add(const XmlOppfByttegruppe &oppf) {
    oppfByttegruppe.emplace_back(oppf.GetId(), oppf.GetTidspunkt(), oppf.GetStatus(), oppf.GetByttegruppe());
}

void Fest::Add(const OppfByttegruppe &byttegruppe) {
    oppfByttegruppe.emplace_back(byttegruppe);
}

void Fest::Add(const XmlOppfLegemiddeldose &oppf) {
    oppfLegemiddeldose.emplace_back(oppf.GetId(), oppf.GetTidspunkt(), oppf.GetStatus(), oppf.GetLegemiddeldose());
}

void Fest::Add(const XmlOppfStrDosering &oppf) {
    oppfStrDosering.emplace_back(oppf.GetId(), oppf.GetTidspunkt(), oppf.GetStatus(), oppf.GetKortdose());
}

bool Fest::Add(const XmlOppfInteraksjon &oppf) {
    OppfInteraksjonBase oppfInteraksjon{oppf.GetId(), oppf.GetTidspunkt(), oppf.GetStatus()};
    auto interaksjon = oppf.GetInteraksjon();
    auto interaksjonIkkeVurdert = oppf.GetInteraksjonIkkeVurdert();
    auto hasInteraksjon = !interaksjon.GetId().empty();
    auto hasInteraksjonIkkeVurdert = !interaksjonIkkeVurdert.GetAtc().GetValue().empty();
    if (hasInteraksjon) {
        if (hasInteraksjonIkkeVurdert) {
            std::cerr << "Error: OppfInteraksjon: Both Interaksjon and InteraksjonIkkeVurdert\n";
            return false;
        }
        this->oppfInteraksjon.emplace_back(oppfInteraksjon, interaksjon);
        return true;
    } else if (hasInteraksjonIkkeVurdert) {
        this->oppfInteraksjonIkkeVurdert.emplace_back(oppfInteraksjon, interaksjonIkkeVurdert);
        return true;
    } else {
        std::cerr << "Error: Expected Interaksjon or InteraksjonIkkeVurdert\n";
        return false;
    }
}

bool Fest::Accept(FestVisitor &visitor) const {
    auto total = oppfLegemiddelMerkevare.size()
            + oppfLegemiddelpakning.size()
            + oppfLegemiddelVirkestoff.size()
            + oppfMedForbrVare.size()
            + oppfNaringsmiddel.size()
            + oppfBrystprotese.size()
            + oppfLegemiddeldose.size()
            + oppfVirkestoffMedStyrke.size()
            + oppfVirkestoff.size()
            + oppfKodeverk.size()
            + oppfRefusjon.size()
            + oppfVilkar.size()
            + oppfVarselSlv.size()
            + oppfByttegruppe.size()
            + oppfInteraksjon.size()
            + oppfInteraksjonIkkeVurdert.size()
            + oppfStrDosering.size();
    decltype(total) done = 0;
    for (const auto &merkevare : oppfLegemiddelMerkevare) {
        if (!visitor.Visit(hentetDato, merkevare)) {
            return false;
        }
        visitor.Progress(++done, total);
    }
    for (const auto &pakning : oppfLegemiddelpakning) {
        if (!visitor.Visit(hentetDato, pakning)) {
            return false;
        }
        visitor.Progress(++done, total);
    }
    for (const auto &virkestoff : oppfLegemiddelVirkestoff) {
        if (!visitor.Visit(hentetDato, virkestoff)) {
            return false;
        }
        visitor.Progress(++done, total);
    }
    for (const auto &medForbrMatr : oppfMedForbrVare) {
        if (!visitor.Visit(hentetDato, medForbrMatr)) {
            return false;
        }
        visitor.Progress(++done, total);
    }
    for (const auto &naringsmiddel : oppfNaringsmiddel) {
        if (!visitor.Visit(hentetDato, naringsmiddel)) {
            return false;
        }
        visitor.Progress(++done, total);
    }
    for (const auto &brystprotese : oppfBrystprotese) {
        if (!visitor.Visit(hentetDato, brystprotese)) {
            return false;
        }
        visitor.Progress(++done, total);
    }
    for (const auto &legemiddeldose : oppfLegemiddeldose) {
        if (!visitor.Visit(hentetDato, legemiddeldose)) {
            return false;
        }
        visitor.Progress(++done, total);
    }
    for (const auto &virkestoffMedStyrke : oppfVirkestoffMedStyrke) {
        if (!visitor.Visit(hentetDato, virkestoffMedStyrke)) {
            return false;
        }
        visitor.Progress(++done, total);
    }
    for (const auto &virkestoff : oppfVirkestoff) {
        if (!visitor.Visit(hentetDato, virkestoff)) {
            return false;
        }
        visitor.Progress(++done, total);
    }
    for (const auto &kodeverk : oppfKodeverk) {
        if (!visitor.Visit(hentetDato, kodeverk)) {
            return false;
        }
        visitor.Progress(++done, total);
    }
    for (const auto &refusjon : oppfRefusjon) {
        if (!visitor.Visit(hentetDato, refusjon)) {
            return false;
        }
        visitor.Progress(++done, total);
    }
    for (const auto &vilkar : oppfVilkar) {
        if (!visitor.Visit(hentetDato, vilkar)) {
            return false;
        }
        visitor.Progress(++done, total);
    }
    for (const auto &varselSlv : oppfVarselSlv) {
        if (!visitor.Visit(hentetDato, varselSlv)) {
            return false;
        }
        visitor.Progress(++done, total);
    }
    for (const auto &byttegruppe : oppfByttegruppe) {
        if (!visitor.Visit(hentetDato, byttegruppe)) {
            return false;
        }
        visitor.Progress(++done, total);
    }
    for (const auto &interaksjon : oppfInteraksjon) {
        if (!visitor.Visit(hentetDato, interaksjon)) {
            return false;
        }
        visitor.Progress(++done, total);
    }
    for (const auto &interaksjonIkkeVurdert : oppfInteraksjonIkkeVurdert) {
        if (!visitor.Visit(hentetDato, interaksjonIkkeVurdert)) {
            return false;
        }
        visitor.Progress(++done, total);
    }
    for (const auto &strDosering : oppfStrDosering) {
        if (!visitor.Visit(hentetDato, strDosering)) {
            return false;
        }
        visitor.Progress(++done, total);
    }
    return true;
}

std::shared_ptr<XMLObject> FestHandler::StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes) {
    return std::make_shared<Fest>();
}

bool FestHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    return dynamic_cast<Fest*>(&(*obj)) != nullptr;
}

std::shared_ptr<XMLObject> HentetDatoHandler::StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes) {
    std::shared_ptr<Fest> fest = std::dynamic_pointer_cast<Fest>(parent);
    if (!fest) {
        std::cerr << "Error: HentetDato parent is not Fest\n";
        return {};
    }
    return std::make_shared<HentetDato>(fest);
}

bool HentetDatoHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    std::shared_ptr<HentetDato> hentetDato = std::dynamic_pointer_cast<HentetDato>(obj);
    if (!hentetDato) {
        std::cerr << "Error: HentetDato is wrong type\n";
        return false;
    }
    hentetDato->Merge();
    return true;
}