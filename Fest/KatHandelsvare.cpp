//
// Created by sigsegv on 12/19/22.
//

#include "KatHandelsvare.h"
#include <iostream>

std::string KatHandelsvare::GetName() const {
    return "KatHandelsvare";
}

void KatHandelsvare::Merge(const XmlOppfHandelsvare &oppf) {

}

std::shared_ptr<XMLObject> KatHandelsvareHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                               const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<Fest> fest = std::dynamic_pointer_cast<Fest>(parent);
    if (!fest) {
        std::cerr << "Error: KatLegemiddelpakning parent is not Fest\n";
        return {};
    }
    return std::make_shared<KatHandelsvare>(fest);
}

bool KatHandelsvareHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    return true;
}

std::string XmlOppfHandelsvare::GetName() const {
    return "OppfHandelsvare";
}

void XmlOppfHandelsvare::Merge() {
    kat->Merge(*this);
}

std::shared_ptr<XMLObject> OppfHandelsvareHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<KatHandelsvare> kat = std::dynamic_pointer_cast<KatHandelsvare>(parent);
    if (!kat) {
        std::cerr << "Error: OppfLegemiddelVirkestoff parent is not KatLegemiddelVirkestoff\n";
        return {};
    }
    return std::make_shared<XmlOppfHandelsvare>(kat);
}

bool OppfHandelsvareHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *oppf = dynamic_cast<XmlOppfHandelsvare*>(&(*obj));
    if (oppf == nullptr) {
        std::cerr << "Error: End element, not for the XmlOppfLegemiddelpakning\n";
        return false;
    }
    oppf->Merge();
    return true;
}