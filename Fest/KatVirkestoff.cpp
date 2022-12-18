//
// Created by sigsegv on 12/16/22.
//

#include "KatVirkestoff.h"
#include "Fest.h"
#include <iostream>

std::string KatVirkestoff::GetName() const {
    return "KatVirkestoff";
}

bool KatVirkestoff::Merge(XmlOppfVirkestoff &oppf) {
    return fest->Add(oppf);
}

std::shared_ptr<XMLObject> KatVirkestoffHandler::StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes) {
    std::shared_ptr<Fest> fest = std::dynamic_pointer_cast<Fest>(parent);
    if (!fest) {
        std::cerr << "Error: KatLegemiddelpakning parent is not Fest\n";
        return {};
    }
    return std::make_shared<KatVirkestoff>(fest);
}

bool KatVirkestoffHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    return true;
}

std::string XmlOppfVirkestoff::GetName() const {
    return "OppfVirkestoff";
}

void XmlOppfVirkestoff::SetVirkestoff(const Virkestoff &virkestoff) {
    this->virkestoff = virkestoff;
}

Virkestoff XmlOppfVirkestoff::GetVirkestoff() const {
    return virkestoff;
}

void XmlOppfVirkestoff::SetVirkestoffMedStyrke(const VirkestoffMedStyrke &virkestoffMedStyrke) {
    this->virkestoffMedStyrke = virkestoffMedStyrke;
}

VirkestoffMedStyrke XmlOppfVirkestoff::GetVirkestoffMedStyrke() const {
    return virkestoffMedStyrke;
}

bool XmlOppfVirkestoff::Merge() {
    return kat->Merge(*this);
}

std::shared_ptr<XMLObject> XmlOppfVirkestoffHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                  const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<KatVirkestoff> kat = std::dynamic_pointer_cast<KatVirkestoff>(parent);
    if (!kat) {
        std::cerr << "Error: OppfVirkestoff parent is not KatVirkestoff\n";
        return {};
    }
    return std::make_shared<XmlOppfVirkestoff>(kat);
}

bool XmlOppfVirkestoffHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *oppf = dynamic_cast<XmlOppfVirkestoff*>(&(*obj));
    if (oppf == nullptr) {
        std::cerr << "Error: End element, not for the OppfVirkestoff\n";
        return false;
    }
    return oppf->Merge();
}