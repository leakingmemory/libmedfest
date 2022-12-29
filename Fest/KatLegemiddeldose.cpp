//
// Created by sigsegv on 12/29/22.
//

#include "KatLegemiddeldose.h"
#include "Fest.h"
#include <iostream>

std::string KatLegemiddeldose::GetName() const {
    return "KatLegemiddeldose";
}

void KatLegemiddeldose::Merge(const XmlOppfLegemiddeldose &oppf) {
    fest->Add(oppf);
}

std::string XmlOppfLegemiddeldose::GetName() const {
    return "OppfLegemiddeldose";
}

void XmlOppfLegemiddeldose::SetLegemiddeldose(const Legemiddeldose &legemiddeldose) {
    this->legemiddeldose = legemiddeldose;
}

Legemiddeldose XmlOppfLegemiddeldose::GetLegemiddeldose() const {
    return legemiddeldose;
}

void XmlOppfLegemiddeldose::Merge() {
    kat->Merge(*this);
}

std::shared_ptr<XMLObject> KatLegemiddeldoseHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                  const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<Fest> fest = std::dynamic_pointer_cast<Fest>(parent);
    if (!fest) {
        std::cerr << "Error: Unexpected KatLegemiddeldose\n";
        return {};
    }
    return std::make_shared<KatLegemiddeldose>(fest);
}

bool KatLegemiddeldoseHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    return true;
}

std::shared_ptr<XMLObject> XmlOppfLegemiddeldoseHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                      const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<KatLegemiddeldose> kat = std::dynamic_pointer_cast<KatLegemiddeldose>(parent);
    if (!kat) {
        std::cerr << "Error: Unexpected OppfLegemiddeldose\n";
        return {};
    }
    return std::make_shared<XmlOppfLegemiddeldose>(kat);
}

bool XmlOppfLegemiddeldoseHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *l = dynamic_cast<XmlOppfLegemiddeldose *>(&(*obj));
    if (l == nullptr) {
        std::cerr << "Error: Not ending OppfLegemiddeldose\n";
        return false;
    }
    l->Merge();
    return true;
}