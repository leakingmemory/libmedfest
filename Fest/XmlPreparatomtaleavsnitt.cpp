//
// Created by sigsegv on 12/11/22.
//

#include "XmlPreparatomtaleavsnitt.h"
#include <iostream>

std::string XmlPreparatomtaleavsnitt::GetName() const {
    return "Preparatomtaleavsnitt";
}

void XmlPreparatomtaleavsnitt::SetAvsnittoverskrift(const ValueWithDistinguishedName &avsnittoverskrift) {
    this->avsnittoverskrift = avsnittoverskrift;
}

void XmlPreparatomtaleavsnitt::SetLink(const std::string &link) {
    this->link = link;
}

bool XmlPreparatomtaleavsnitt::Merge() {
    parent->SetPreparatomtaleavsnitt({avsnittoverskrift, link});
    return true;
}

std::shared_ptr<XMLObject> XmlPreparatomtaleavsnittHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                         const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlLegemiddelMerkevare> typedParent = std::dynamic_pointer_cast<XmlLegemiddelMerkevare>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected Preparatomtaleavsnitt\n";
        return {};
    }
    return std::make_shared<XmlPreparatomtaleavsnitt>(typedParent);
}

bool XmlPreparatomtaleavsnittHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *p = dynamic_cast<XmlPreparatomtaleavsnitt *>(&(*obj));
    if (p == nullptr) {
        std::cerr << "Error: Did not end Preparatomtaleavsnitt\n";
        return false;
    }
    return p->Merge();
}

bool XmlAvsnittoverskriftHandler::Merge(std::shared_ptr<XmlType> obj) {
    obj->GetParent()->SetAvsnittoverskrift(obj->GetValueWithDistinguishedName());
    return true;
}

std::string XmlLenke::GetName() const {
    return "Lenke";
}

void XmlLenke::SetLink(const std::string &link) {
    this->link = link;
}

bool XmlLenke::Merge() {
    parent->SetLink(link);
    return true;
}

std::shared_ptr<XMLObject> XmlLenkeHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                         const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlPreparatomtaleavsnitt> typedParent = std::dynamic_pointer_cast<XmlPreparatomtaleavsnitt>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected Lenke\n";
        return {};
    }
    return std::make_shared<XmlLenke>(typedParent);
}

bool XmlLenkeHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *l = dynamic_cast<XmlLenke *>(&(*obj));
    if (l == nullptr) {
        std::cerr << "Error: Did not end Lenke\n";
        return false;
    }
    return l->Merge();
}

bool XmlWwwHandler::Merge(std::shared_ptr<XmlType> obj) {
    obj->GetParent()->SetLink(obj->GetValue());
    return true;
}
