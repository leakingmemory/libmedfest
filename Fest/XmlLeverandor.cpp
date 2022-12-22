//
// Created by sigsegv on 12/20/22.
//

#include "XmlLeverandor.h"
#include "XmlHandelsvare.h"

std::string XmlLeverandor::GetName() const {
    return "Leverandor";
}

void XmlLeverandor::SetAdresse(const std::string &adresse) {
    this->adresse = adresse;
}

void XmlLeverandor::SetTelefon(const std::string &telefon) {
    this->telefon = telefon;
}

bool XmlLeverandor::Merge() {
    parent->SetLeverandor({GetNavn(), adresse, telefon});
    return true;
}

std::shared_ptr<XMLObject> XmlLeverandorHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                              const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlHandelsvare> typedParent = std::dynamic_pointer_cast<XmlHandelsvare>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected Leverandor\n";
        return {};
    }
    return std::make_shared<XmlLeverandor>(typedParent);
}

bool XmlLeverandorHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *l = dynamic_cast<XmlLeverandor*>(&(*obj));
    if (l == nullptr) {
        std::cerr << "Error: Not ending Leverandor\n";
        return false;
    }
    return l->Merge();
}

bool XmlAdresseHandler::Merge(std::shared_ptr<XmlLeverandor> parent, const std::string &content) {
    parent->SetAdresse(content);
    return true;
}

bool XmlTelefonHandler::Merge(std::shared_ptr<XmlLeverandor> parent, const std::string &content) {
    parent->SetTelefon(content);
    return true;
}