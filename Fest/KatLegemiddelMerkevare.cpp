//
// Created by sigsegv on 12/9/22.
//

#include "KatLegemiddelMerkevare.h"
#include <Fest/Fest.h>
#include <iostream>

std::string KatLegemiddelMerkevare::GetName() const {
    return "KatLegemiddelMerkevare";
}

void KatLegemiddelMerkevare::Merge(const XmlOppfLegemiddelMerkevare &oppf) {
    fest->Add(oppf);
}

std::shared_ptr<XMLObject>
KatLegemiddelMerkevareHandler::StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes) {
    std::shared_ptr<Fest> fest = std::dynamic_pointer_cast<Fest>(parent);
    if (!fest) {
        std::cerr << "Error: KatLegemiddelMerkevare parent is not Fest\n";
        return {};
    }
    return std::make_shared<KatLegemiddelMerkevare>(fest);
}

bool KatLegemiddelMerkevareHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    return dynamic_cast<KatLegemiddelMerkevare*>(&(*obj)) != nullptr;
}

std::string XmlOppfLegemiddelMerkevare::GetName() const {
    return "OppfLegemiddelMerkevare";
}

void XmlOppfLegemiddelMerkevare::SetLegemiddelMerkevare(const LegemiddelMerkevare &legemiddelMerkevare) {
    this->legemiddelMerkevare = legemiddelMerkevare;
}

LegemiddelMerkevare XmlOppfLegemiddelMerkevare::GetLegemiddelMerkevare() const {
    return legemiddelMerkevare;
}

void XmlOppfLegemiddelMerkevare::Merge() {
    kat->Merge(*this);
}

std::shared_ptr<XMLObject> OppfLegemiddelMerkevareHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                        const std::map<std::string,std::string> &attributes) {
    std::shared_ptr<KatLegemiddelMerkevare> kat = std::dynamic_pointer_cast<KatLegemiddelMerkevare>(parent);
    if (!kat) {
        std::cerr << "Error: XmlOppfLegemiddelMerkevare parent is not KatLegemiddelMerkevare\n";
        return {};
    }
    return std::make_shared<XmlOppfLegemiddelMerkevare>(kat);
}

bool OppfLegemiddelMerkevareHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *oppf = dynamic_cast<XmlOppfLegemiddelMerkevare*>(&(*obj));
    if (oppf == nullptr) {
        std::cerr << "Error: End element, not for the XmlOppfLegemiddelMerkevare\n";
        return false;
    }
    oppf->Merge();
    return true;
}