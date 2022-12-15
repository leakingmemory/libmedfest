//
// Created by sigsegv on 12/12/22.
//

#include "XmlPakningskomponent.h"

std::string XmlPakningskomponent::GetName() const {
    return "Pakningskomponent";
}

bool XmlPakningskomponent::Mengde(const ValueUnit &mengde) {
    this->mengde = mengde;
    return true;
}

bool XmlPakningskomponent::Merge() {
    parent->AddPakningskomponent({GetPakningstype(), mengde, GetAntall()});
    return true;
}

std::shared_ptr<XMLObject> XmlPakningskomponentHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                     const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlPakningsinfoObject> typedParent = std::dynamic_pointer_cast<XmlPakningsinfoObject>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected Pakningskomponent\n";
        return {};
    }
    return std::make_shared<XmlPakningskomponent>(typedParent);
}

bool XmlPakningskomponentHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *pk = dynamic_cast<XmlPakningskomponent *>(&(*obj));
    if (pk == nullptr) {
        std::cerr << "Error: Did not end Pakningskomponent\n";
        return false;
    }
    return pk->Merge();
}