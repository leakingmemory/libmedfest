//
// Created by sigsegv on 12/30/22.
//

#include "XmlInteraksjonIkkeVurdert.h"
#include "KatInteraksjon.h"
#include <iostream>

std::string XmlInteraksjonIkkeVurdert::GetName() const {
    return "InteraksjonIkkeVurdert";
}

bool XmlInteraksjonIkkeVurdert::Merge() {
    return parent->SetInteraksjonIkkeVurdert({GetAtc()});
}

std::shared_ptr<XMLObject> XmlInteraksjonIkkeVurdertHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                          const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlOppfInteraksjon> typedParent = std::dynamic_pointer_cast<XmlOppfInteraksjon>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected InteraksjonIkkeVurdert\n";
        return {};
    }
    return std::make_shared<XmlInteraksjonIkkeVurdert>(typedParent);
}

bool XmlInteraksjonIkkeVurdertHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *i = dynamic_cast<XmlInteraksjonIkkeVurdert *>(&(*obj));
    if (i == nullptr) {
        std::cerr << "Error: Not ending InteraksjonIkkeVurdert\n";
        return false;
    }
    return i->Merge();
}