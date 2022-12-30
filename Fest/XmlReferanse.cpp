//
// Created by sigsegv on 12/30/22.
//

#include "XmlReferanse.h"
#include "XmlInteraksjon.h"
#include <iostream>

std::string XmlReferanse::GetName() const {
    return "Referanse";
}

void XmlReferanse::SetKilde(const std::string &kilde) {
    this->kilde = kilde;
}

bool XmlReferanse::Merge() {
    parent->AddReferanse({kilde, GetLenke()});
    return true;
}

std::shared_ptr<XMLObject> XmlReferanseHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                             const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlInteraksjon> typedParent = std::dynamic_pointer_cast<XmlInteraksjon>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected Referanse\n";
        return {};
    }
    return std::make_shared<XmlReferanse>(typedParent);
}

bool XmlReferanseHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *r = dynamic_cast<XmlReferanse *>(&(*obj));
    if (r == nullptr) {
        std::cerr << "Error: Not ending Referanse\n";
        return false;
    }
    return r->Merge();
}

bool XmlKildeHandler::Merge(std::shared_ptr<XmlReferanse> parent, const std::string &content) {
    parent->SetKilde(content);
    return true;
}