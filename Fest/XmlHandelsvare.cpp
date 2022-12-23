//
// Created by sigsegv on 12/19/22.
//

#include "XmlHandelsvare.h"
#include "KatHandelsvare.h"

void XmlHandelsvare::SetNr(const std::string &nr) {
    this->nr = nr;
}

void XmlHandelsvare::SetProduktInfoVare(const ProduktInfoVare &produktInfoVare) {
    this->produktInfoVare = produktInfoVare;
}

void XmlHandelsvare::SetLeverandor(const Leverandor &leverandor) {
    this->leverandor = leverandor;
}

std::string XmlMedForbrMatr::GetName() const {
    return "MedForbMatr";
}

bool XmlMedForbrMatr::Merge() {
    oppf->SetMedForbrMatr({{nr, GetNavn(), produktInfoVare, leverandor, GetPrisVare(), GetRefusjon()}});
    return true;
}

std::string XmlNaringsmiddel::GetName() const {
    return "Naringsmiddel";
}

bool XmlNaringsmiddel::Merge() {
    oppf->SetNaringsmiddel({{nr, GetNavn(), produktInfoVare, leverandor, GetPrisVare(), GetRefusjon()}});
    return true;
}

std::string XmlBrystprotese::GetName() const {
    return "Brystprotese";
}

bool XmlBrystprotese::Merge() {
    oppf->SetBrystprotese({{nr, GetNavn(), produktInfoVare, leverandor, GetPrisVare(), GetRefusjon()}});
    return true;
}

std::shared_ptr<XMLObject> XmlMedForbrMatrHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlOppfHandelsvare> oppf = std::dynamic_pointer_cast<XmlOppfHandelsvare>(parent);
    if (!oppf) {
        std::cerr << "Error: MedForbMatr not expected here\n";
        return {};
    }
    return std::make_shared<XmlMedForbrMatr>(oppf);
}

bool XmlMedForbrMatrHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *oppf = dynamic_cast<XmlMedForbrMatr*>(&(*obj));
    if (oppf == nullptr) {
        std::cerr << "Error: End of MedForbMatr, but not currently a L..\n";
        return false;
    }
    oppf->Merge();
    return true;
}

std::shared_ptr<XMLObject> XmlNaringsmiddelHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                               const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlOppfHandelsvare> oppf = std::dynamic_pointer_cast<XmlOppfHandelsvare>(parent);
    if (!oppf) {
        std::cerr << "Error: Naringsmiddel not expected here\n";
        return {};
    }
    return std::make_shared<XmlNaringsmiddel>(oppf);
}

bool XmlNaringsmiddelHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *oppf = dynamic_cast<XmlHandelsvare*>(&(*obj));
    if (oppf == nullptr) {
        std::cerr << "Error: End of Naringsmiddel, but not currently a N..\n";
        return false;
    }
    oppf->Merge();
    return true;
}

std::shared_ptr<XMLObject> XmlBrystproteseHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlOppfHandelsvare> oppf = std::dynamic_pointer_cast<XmlOppfHandelsvare>(parent);
    if (!oppf) {
        std::cerr << "Error: Brystprotese not expected here\n";
        return {};
    }
    return std::make_shared<XmlBrystprotese>(oppf);
}

bool XmlBrystproteseHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *oppf = dynamic_cast<XmlHandelsvare*>(&(*obj));
    if (oppf == nullptr) {
        std::cerr << "Error: End of Brystprotese, but not currently a B..\n";
        return false;
    }
    oppf->Merge();
    return true;
}

bool XmlNrHandler::Merge(std::shared_ptr<XmlHandelsvare> parent, const std::string &content) {
    parent->SetNr(content);
    return true;
}