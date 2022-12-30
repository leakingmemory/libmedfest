//
// Created by sigsegv on 12/30/22.
//

#include "XmlSubstansgruppe.h"
#include "XmlInteraksjon.h"
#include <iostream>

std::string XmlSubstansgruppe::GetName() const {
    return "Substansgruppe";
}

void XmlSubstansgruppe::AddSubstans(const Substans &substans) {
    this->substans.emplace_back(substans);
}

bool XmlSubstansgruppe::Merge() {
    parent->AddSubstansgruppe({substans, GetNavn()});
    return true;
}

std::shared_ptr<XMLObject> XmlSubstansgruppeHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                  const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlInteraksjon> typedParent = std::dynamic_pointer_cast<XmlInteraksjon>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected Substansgruppe\n";
        return {};
    }
    return std::make_shared<XmlSubstansgruppe>(typedParent);
}

bool XmlSubstansgruppeHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *s = dynamic_cast<XmlSubstansgruppe *>(&(*obj));
    if (s == nullptr) {
        std::cerr << "Error: Not ending Substansgruppe\n";
        return false;
    }
    return s->Merge();
}