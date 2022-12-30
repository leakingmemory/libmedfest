//
// Created by sigsegv on 12/30/22.
//

#include "XmlSubstans.h"
#include "XmlSubstansgruppe.h"
#include <iostream>

std::string XmlSubstans::GetName() const {
    return "Substans";
}

void XmlSubstans::SetSubstans(const std::string &substans) {
    this->substans = substans;
}

bool XmlSubstans::Merge() {
    std::string refVirkestoff{};
    {
        auto refs = GetRefVirkestoff();
        if (refs.size() > 0) {
            if (refs.size() > 1) {
                std::cerr << "Error: Substans: Multiple RefVirkestoff\n";
                return false;
            }
            refVirkestoff = refs[0];
        }
    }
    parent->AddSubstans({substans, GetAtc(), refVirkestoff});
    return true;
}

std::shared_ptr<XMLObject> XmlSubstansHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                            const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlSubstansgruppe> typedParent = std::dynamic_pointer_cast<XmlSubstansgruppe>(parent);
    if (!typedParent) {
        return XmlContentElementHandler<XmlSubstans>::StartElement(parent, attributes);
    }
    return std::make_shared<XmlSubstans>(typedParent);
}

bool XmlSubstansHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *s = dynamic_cast<XmlSubstans *>(&(*obj));
    if (s == nullptr) {
        return XmlContentElementHandler<XmlSubstans>::EndElement(obj);
    }
    return s->Merge();
}

bool XmlSubstansHandler::Merge(std::shared_ptr<XmlSubstans> parent, const std::string &content) {
    parent->SetSubstans(content);
    return true;
}