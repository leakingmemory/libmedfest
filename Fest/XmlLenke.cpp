//
// Created by sigsegv on 12/27/22.
//

#include "XmlLenke.h"

void XmlLenke::SetLenke(const Lenke &lenke) {
    this->lenke = lenke;
}

Lenke XmlLenke::GetLenke() const {
    return lenke;
}

std::string XmlLenkeObject::GetName() const {
    return "Lenke";
}

void XmlLenkeObject::SetBeskrivelse(const std::string &beskrivelse) {
    this->beskrivelse = beskrivelse;
}

void XmlLenkeObject::SetWww(const std::string &www) {
    this->www = www;
}

bool XmlLenkeObject::Merge() {
    parent->SetLenke({beskrivelse, www});
    return true;
}

std::shared_ptr<XMLObject> XmlLenkeHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                         const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlLenke> typedParent = std::dynamic_pointer_cast<XmlLenke>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected Lenke\n";
        return {};
    }
    return std::make_shared<XmlLenkeObject>(typedParent);
}

bool XmlLenkeHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *l = dynamic_cast<XmlLenkeObject *>(&(*obj));
    if (l == nullptr) {
        std::cerr << "Error: Did not end Lenke\n";
        return false;
    }
    return l->Merge();
}

bool XmlBeskrivelseHandler::Merge(std::shared_ptr<XmlLenkeObject> parent, const std::string &content) {
    parent->SetBeskrivelse(content);
    return true;
}

bool XmlWwwHandler::Merge(std::shared_ptr<XmlType> obj) {
    obj->GetParent()->SetWww(obj->GetValue());
    return true;
}