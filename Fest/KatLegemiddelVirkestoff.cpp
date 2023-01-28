//
// Created by sigsegv on 12/18/22.
//

#include "KatLegemiddelVirkestoff.h"
#include <iostream>

std::string KatLegemiddelVirkestoff::GetName() const {
    return "KatLegemiddelVirkestoff";
}

void KatLegemiddelVirkestoff::Merge(const XmlOppfLegemiddelVirkestoff &oppf) {
    fest->Add(oppf);
}

std::shared_ptr<XMLObject> KatLegemiddelVirkestoffHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                        const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<Fest> fest = std::dynamic_pointer_cast<Fest>(parent);
    if (!fest) {
        std::cerr << "Error: KatLegemiddelpakning parent is not Fest\n";
        return {};
    }
    return std::make_shared<KatLegemiddelVirkestoff>(fest);
}

bool KatLegemiddelVirkestoffHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    return true;
}

std::string XmlOppfLegemiddelVirkestoff::GetName() const {
    return "OppfLegemiddelVirkestoff";
}

void XmlOppfLegemiddelVirkestoff::SetLegemiddelVirkestoff(const LegemiddelVirkestoff &legemiddelVirkestoff) {
    this->legemiddelVirkestoff = legemiddelVirkestoff;
}

LegemiddelVirkestoff XmlOppfLegemiddelVirkestoff::GetLegemiddelVirkestoff() const {
    return legemiddelVirkestoff;
}

void XmlOppfLegemiddelVirkestoff::Merge() {
    kat->Merge(*this);
}

std::shared_ptr<XMLObject> OppfLegemiddelVirkestoffHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                         const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<KatLegemiddelVirkestoff> kat = std::dynamic_pointer_cast<KatLegemiddelVirkestoff>(parent);
    if (!kat) {
        std::cerr << "Error: OppfLegemiddelVirkestoff parent is not KatLegemiddelVirkestoff\n";
        return {};
    }
    return std::make_shared<XmlOppfLegemiddelVirkestoff>(kat);
}

bool OppfLegemiddelVirkestoffHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *oppf = dynamic_cast<XmlOppfLegemiddelVirkestoff*>(&(*obj));
    if (oppf == nullptr) {
        std::cerr << "Error: End element, not for the XmlOppfLegemiddelpakning\n";
        return false;
    }
    oppf->Merge();
    return true;
}