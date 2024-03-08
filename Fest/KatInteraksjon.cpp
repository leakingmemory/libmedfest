//
// Created by sigsegv on 12/29/22.
//

#include "KatInteraksjon.h"
#include <Fest/Fest.h>
#include <iostream>

std::string KatInteraksjon::GetName() const {
    return "KatInteraksjon";
}

bool KatInteraksjon::Merge(const XmlOppfInteraksjon &oppf) {
    return fest->Add(oppf);
}

std::string XmlOppfInteraksjon::GetName() const {
    return "OppfInteraksjon";
}

bool XmlOppfInteraksjon::SetInteraksjon(const Interaksjon &interaksjon) {
    if (this->interaksjon.GetId().empty() && this->interaksjon.GetRelevans().GetValue().empty()) {
        this->interaksjon = interaksjon;
        return true;
    } else {
        std::cerr << "Error: Duplicate OppfInteraksjon -> Interaksjon\n";
        return false;
    }
}

Interaksjon XmlOppfInteraksjon::GetInteraksjon() const {
    return interaksjon;
}

bool XmlOppfInteraksjon::SetInteraksjonIkkeVurdert(const InteraksjonIkkeVurdert &interaksjonIkkeVurdert) {
    if (this->interaksjonIkkeVurdert.GetAtc().GetValue().empty()) {
        this->interaksjonIkkeVurdert = interaksjonIkkeVurdert;
        return true;
    } else {
        std::cerr << "Error: Duplicate OppfInteraksjon -> InteraksjonIkkeVurdert\n";
        return false;
    }
}

InteraksjonIkkeVurdert XmlOppfInteraksjon::GetInteraksjonIkkeVurdert() const {
    return interaksjonIkkeVurdert;
}

bool XmlOppfInteraksjon::Merge() {
    return kat->Merge(*this);
}

std::shared_ptr<XMLObject> KatInteraksjonHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                               const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<Fest> fest = std::dynamic_pointer_cast<Fest>(parent);
    if (!fest) {
        std::cerr << "Error: Unexpected KatInteraksjon\n";
        return {};
    }
    return std::make_shared<KatInteraksjon>(fest);
}

bool KatInteraksjonHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    return true;
}

std::shared_ptr<XMLObject> XmlOppfInteraksjonHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                   const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<KatInteraksjon> kat = std::dynamic_pointer_cast<KatInteraksjon>(parent);
    if (!kat) {
        std::cerr << "Error: Unexpected OppfInteraksjon\n";
        return {};
    }
    return std::make_shared<XmlOppfInteraksjon>(kat);
}

bool XmlOppfInteraksjonHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *i = dynamic_cast<XmlOppfInteraksjon *>(&(*obj));
    if (i == nullptr) {
        std::cerr << "Error: Not ending OppfInteraksjon\n";
        return false;
    }
    return i->Merge();
}