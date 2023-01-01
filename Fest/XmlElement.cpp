//
// Created by sigsegv on 12/28/22.
//

#include "XmlElement.h"
#include "KatKodeverk.h"
#include <iostream>

std::string XmlElement::GetName() const {
    return "Element";
}

void XmlElement::SetTerm(const Term &term) {
    this->term = term;
}

bool XmlElement::Merge() {
    parent->AddElement({GetId(), GetKode(), term});
    return true;
}

std::string XmlTerm::GetName() const {
    return "Term";
}

void XmlTerm::SetTerm(const std::string &term) {
    this->term = term;
}

void XmlTerm::SetSprak(const Sprak &sprak) {
    this->sprak = sprak;
}

bool XmlTerm::Merge() {
    parent->SetTerm({term, GetBeskrivelseTerm(), sprak});
    return true;
}

std::shared_ptr<XMLObject> XmlElementHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                           const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlOppfKodeverk> typedParent = std::dynamic_pointer_cast<XmlOppfKodeverk>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected Element\n";
        return {};
    }
    return std::make_shared<XmlElement>(typedParent);
}

bool XmlElementHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *e = dynamic_cast<XmlElement *>(&(*obj));
    if (e == nullptr) {
        std::cerr << "Error: Not ending Element\n";
        return false;
    }
    return e->Merge();
}

std::shared_ptr<XMLObject> XmlTermHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                        const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlElement> typedParent = std::dynamic_pointer_cast<XmlElement>(parent);
    if (!typedParent) {
        return XmlContentElementHandler<XmlTerm>::StartElement(parent, attributes);
    }
    return std::make_shared<XmlTerm>(typedParent);
}

bool XmlTermHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *t = dynamic_cast<XmlTerm *>(&(*obj));
    if (t == nullptr) {
        return XmlContentElementHandler<XmlTerm>::EndElement(obj);
    }
    return t->Merge();
}

bool XmlTermHandler::Merge(std::shared_ptr<XmlTerm> parent, const std::string &content) {
    parent->SetTerm(content);
    return true;
}

bool XmlSprakHandler::Merge(std::shared_ptr<XmlType> obj) {
    obj->GetParent()->SetSprak({obj->GetValueWithDistinguishedName()});
    return true;
}