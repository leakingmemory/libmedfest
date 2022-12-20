//
// Created by sigsegv on 12/19/22.
//

#include "XmlMedForbrMatr.h"
#include "KatHandelsvare.h"

std::string XmlMedForbrMatr::GetName() const {
    return "MedForbMatr";
}

void XmlMedForbrMatr::SetNr(const std::string &nr) {
    this->nr = nr;
}

void XmlMedForbrMatr::SetProduktInfoVare(const ProduktInfoVare &produktInfoVare) {
    this->produktInfoVare = produktInfoVare;
}

bool XmlMedForbrMatr::Merge() {
    oppf->SetMedForbrMatr({nr, GetNavn(), produktInfoVare});
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

bool XmlNrHandler::Merge(std::shared_ptr<XmlMedForbrMatr> parent, const std::string &content) {
    parent->SetNr(content);
    return true;
}