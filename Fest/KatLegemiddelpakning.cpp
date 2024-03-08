//
// Created by sigsegv on 12/11/22.
//

#include "KatLegemiddelpakning.h"
#include <Fest/Fest.h>
#include <iostream>

std::string KatLegemiddelpakning::GetName() const {
    return "KatLegemiddelpakning";
}

void KatLegemiddelpakning::Merge(const XmlOppfLegemiddelpakning &oppf) {
    fest->Add(oppf);
}

std::shared_ptr<XMLObject> KatLegemiddelpakningHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                     const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<Fest> fest = std::dynamic_pointer_cast<Fest>(parent);
    if (!fest) {
        std::cerr << "Error: KatLegemiddelpakning parent is not Fest\n";
        return {};
    }
    return std::make_shared<KatLegemiddelpakning>(fest);
}

bool KatLegemiddelpakningHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    return dynamic_cast<KatLegemiddelpakning*>(&(*obj)) != nullptr;
}

std::string XmlOppfLegemiddelpakning::GetName() const {
    return "OppfLegemiddelpakning";
}

Legemiddelpakning XmlOppfLegemiddelpakning::GetLegemiddelpakning() const {
    return legemiddelpakning;
}

void XmlOppfLegemiddelpakning::SetLegemiddelpakning(const Legemiddelpakning &legemiddelpakning) {
    this->legemiddelpakning = legemiddelpakning;
}

void XmlOppfLegemiddelpakning::Merge() {
    kat->Merge(*this);
}

std::shared_ptr<XMLObject> OppfLegemiddelpakningHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                      const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<KatLegemiddelpakning> kat = std::dynamic_pointer_cast<KatLegemiddelpakning>(parent);
    if (!kat) {
        std::cerr << "Error: OppfLegemiddelpakning parent is not KatLegemiddelpakning\n";
        return {};
    }
    return std::make_shared<XmlOppfLegemiddelpakning>(kat);
}

bool OppfLegemiddelpakningHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *oppf = dynamic_cast<XmlOppfLegemiddelpakning*>(&(*obj));
    if (oppf == nullptr) {
        std::cerr << "Error: End element, not for the XmlOppfLegemiddelpakning\n";
        return false;
    }
    oppf->Merge();
    return true;
}