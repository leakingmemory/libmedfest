//
// Created by sigsegv on 12/12/22.
//

#include "XmlPakningskomponent.h"

std::string XmlPakningskomponentInfoObject::GetName() const {
    return "Pakningskomponent";
}

bool XmlPakningskomponentInfoObject::Mengde(const ValueUnit &mengde) {
    this->mengde = mengde;
    return true;
}

bool XmlPakningskomponentInfoObject::Merge() {
    return parent.Merge({GetPakningstype(), mengde});
}

bool XmlPakningskomponent::Merge(const PakningskomponentInfo &info) {
    parent->AddPakningskomponent({info, GetAntall()});
    return true;
}

std::shared_ptr<XMLObject> XmlPakningskomponentHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                     const std::map<std::string, std::string> &attributes) {
    {
        std::shared_ptr<XmlPakningskomponentInfo> typedParent = std::dynamic_pointer_cast<XmlPakningskomponentInfo>(parent);
        if (typedParent) {
            return std::make_shared<XmlPakningskomponentInfoObject>(typedParent);
        }
    }
    std::shared_ptr<XmlPakningsinfoObject> typedParent = std::dynamic_pointer_cast<XmlPakningsinfoObject>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected Pakningskomponent\n";
        return {};
    }
    return std::make_shared<XmlPakningskomponent>(typedParent);
}

bool XmlPakningskomponentHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *pk = dynamic_cast<XmlPakningskomponentInfoObject *>(&(*obj));
    if (pk == nullptr) {
        std::cerr << "Error: Did not end Pakningskomponent\n";
        return false;
    }
    return pk->Merge();
}