//
// Created by sigsegv on 12/10/22.
//

#include "XmlReseptgyldighet.h"

std::string XmlReseptgyldighet::GetName() const {
    return "Reseptgyldighet";
}

bool XmlReseptgyldighet::Merge() {
    parent->SetReseptgyldighet(GetVarighet());
    return true;
}

std::shared_ptr<XMLObject> XmlReseptgyldighetHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                   const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlLegemiddelMerkevare> typedParent = std::dynamic_pointer_cast<XmlLegemiddelMerkevare>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected Reseptgyldighet\n";
        return {};
    }
    return std::make_shared<XmlReseptgyldighet>(typedParent);
}

bool XmlReseptgyldighetHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *reseptgyldighet = dynamic_cast<XmlReseptgyldighet *>(&(*obj));
    if (reseptgyldighet == nullptr) {
        std::cerr << "Error: Did not end Reseptgyldighet\n";
        return false;
    }
    return reseptgyldighet->Merge();
}