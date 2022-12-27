//
// Created by sigsegv on 12/11/22.
//

#include "XmlPreparatomtaleavsnitt.h"
#include <iostream>

void XmlPreparatomtaleavsnitt::SetPreparatomtaleavsnitt(const Preparatomtaleavsnitt &preparatomtaleavsnitt) {
    this->preparatomtaleavsnitt = preparatomtaleavsnitt;
}

Preparatomtaleavsnitt XmlPreparatomtaleavsnitt::GetPreparatomtaleavsnitt() const {
    return preparatomtaleavsnitt;
}

std::string XmlPreparatomtaleavsnittObject::GetName() const {
    return "Preparatomtaleavsnitt";
}

void XmlPreparatomtaleavsnittObject::SetAvsnittoverskrift(const ValueWithDistinguishedName &avsnittoverskrift) {
    this->avsnittoverskrift = avsnittoverskrift;
}

bool XmlPreparatomtaleavsnittObject::Merge() {
    parent->SetPreparatomtaleavsnitt({avsnittoverskrift, GetLenke()});
    return true;
}

std::shared_ptr<XMLObject> XmlPreparatomtaleavsnittHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                         const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlPreparatomtaleavsnitt> typedParent = std::dynamic_pointer_cast<XmlPreparatomtaleavsnitt>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected Preparatomtaleavsnitt\n";
        return {};
    }
    return std::make_shared<XmlPreparatomtaleavsnittObject>(typedParent);
}

bool XmlPreparatomtaleavsnittHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *p = dynamic_cast<XmlPreparatomtaleavsnittObject *>(&(*obj));
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
