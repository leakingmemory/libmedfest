//
// Created by sigsegv on 12/8/22.
//

#include "Fest.h"
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

void Fest::Add(const XmlOppfLegemiddelMerkevare &xmlOppf) {
    oppfLegemiddelMerkevare.emplace_back(xmlOppf.GetId(), xmlOppf.GetTidspunkt(), xmlOppf.GetStatus(), xmlOppf.GetLegemiddelMerkevare());
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

void Fest::Add(const XmlOppfKodeverk &oppf) {
    oppfKodeverk.emplace_back(oppf.GetId(), oppf.GetTidspunkt(), oppf.GetStatus(), oppf.GetInfo(), oppf.GetElement());
}

void Fest::Add(const XmlOppfByttegruppe &oppf) {
    oppfByttegruppe.emplace_back(oppf.GetId(), oppf.GetTidspunkt(), oppf.GetStatus(), oppf.GetByttegruppe());
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
            + oppfVirkestoffMedStyrke.size();
    typeof(total) done = 0;
    for (const auto &merkevare : oppfLegemiddelMerkevare) {
        if (!visitor.Visit(merkevare)) {
            return false;
        }
        visitor.Progress(++done, total);
    }
    for (const auto &pakning : oppfLegemiddelpakning) {
        if (!visitor.Visit(pakning)) {
            return false;
        }
        visitor.Progress(++done, total);
    }
    for (const auto &virkestoff : oppfLegemiddelVirkestoff) {
        if (!visitor.Visit(virkestoff)) {
            return false;
        }
        visitor.Progress(++done, total);
    }
    for (const auto &medForbrMatr : oppfMedForbrVare) {
        if (!visitor.Visit(medForbrMatr)) {
            return false;
        }
        visitor.Progress(++done, total);
    }
    for (const auto &naringsmiddel : oppfNaringsmiddel) {
        if (!visitor.Visit(naringsmiddel)) {
            return false;
        }
        visitor.Progress(++done, total);
    }
    for (const auto &brystprotese : oppfBrystprotese) {
        if (!visitor.Visit(brystprotese)) {
            return false;
        }
        visitor.Progress(++done, total);
    }
    for (const auto &legemiddeldose : oppfLegemiddeldose) {
        if (!visitor.Visit(legemiddeldose)) {
            return false;
        }
        visitor.Progress(++done, total);
    }
    for (const auto &virkestoffMedStyrke : oppfVirkestoffMedStyrke) {
        if (!visitor.Visit(virkestoffMedStyrke)) {
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