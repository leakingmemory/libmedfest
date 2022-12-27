//
// Created by sigsegv on 12/27/22.
//

#include "XmlReferanseelement.h"
#include <iostream>

void XmlReferanseelement::SetReferanseelement(const Referanseelement &referanseelement) {
    this->referanseelement = referanseelement;
}

Referanseelement XmlReferanseelement::GetReferanseelement() const {
    return referanseelement;
}

std::string XmlReferanseelementObject::GetName() const {
    return "Referanseelement";
}

void XmlReferanseelementObject::SetKlasse(const Klasse &klasse) {
    this->klasse = klasse;
}

void XmlReferanseelementObject::AddRef(const std::string &ref) {
    this->refs.emplace_back(ref);
}

bool XmlReferanseelementObject::Merge() {
    parent->SetReferanseelement({klasse, refs});
    return true;
}

std::shared_ptr<XMLObject> XmlReferanseelementHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                    const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlReferanseelement> typedParent = std::dynamic_pointer_cast<XmlReferanseelement>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected Referanseelement\n";
        return {};
    }
    return std::make_shared<XmlReferanseelementObject>(typedParent);
}

bool XmlReferanseelementHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *r = dynamic_cast<XmlReferanseelementObject *>(&(*obj));
    if (r == nullptr) {
        std::cerr << "Error: Not ending Referanseelement\n";
        return false;
    }
    return r->Merge();
}

bool XmlKlasseHandler::Merge(std::shared_ptr<XmlType> obj) {
    obj->GetParent()->SetKlasse({obj->GetValueWithDistinguishedName()});
    return true;
}

bool XmlRefElementHandler::Merge(std::shared_ptr<XmlReferanseelementObject> parent, const std::string &content) {
    parent->AddRef(content);
    return true;
}
