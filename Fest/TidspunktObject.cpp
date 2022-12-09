//
// Created by sigsegv on 12/9/22.
//

#include "TidspunktObject.h"
#include <iostream>

std::string TidspunktObject::GetTidspunkt() {
    return tidspunkt;
}

void TidspunktObject::SetTidspunkt(const std::string &tidspunkt) {
    this->tidspunkt = tidspunkt;
}

std::string XmlTidspunktObject::GetName() {
    return "Tidspunkt";
}

bool XmlTidspunktObject::AppendCharacterData(const std::string &charData) {
    tidspunkt.append(charData);
    return true;
}

void XmlTidspunktObject::Merge() {
    tidspunktObject->SetTidspunkt(tidspunkt);
}

std::shared_ptr<XMLObject>
XmlTidspunktObjectHandler::StartElement(const std::shared_ptr<XMLObject> &parent, const std::vector<NameValue> &attributes) {
    std::shared_ptr<TidspunktObject> tidspunktObject = std::dynamic_pointer_cast<TidspunktObject>(parent);
    if (!tidspunktObject) {
        std::cerr << "Tidspunkt, but parent doesn't accept tidspunkt\n";
        return {};
    }
    return std::make_shared<XmlTidspunktObject>(tidspunktObject);
}

bool XmlTidspunktObjectHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *xmlTidspunkt = dynamic_cast<XmlTidspunktObject*>(&(*obj));
    if (xmlTidspunkt == nullptr) {
        std::cerr << "Tidspunkt ended, but current object is not a Tidspunkt\n";
        return false;
    }
    xmlTidspunkt->Merge();
    return true;
}
