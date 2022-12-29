//
// Created by sigsegv on 12/28/22.
//

#include "KatByttegruppe.h"
#include "Fest.h"
#include <iostream>

std::string KatByttegruppe::GetName() const {
    return "KatByttegruppe";
}

void KatByttegruppe::Merge(XmlOppfByttegruppe &oppf) {

}

std::string XmlOppfByttegruppe::GetName() const {
    return "OppfByttegruppe";
}

void XmlOppfByttegruppe::SetByttegruppe(const Byttegruppe &byttegruppe) {
    this->byttegruppe = byttegruppe;
}

Byttegruppe XmlOppfByttegruppe::GetByttegruppe() const {
    return byttegruppe;
}

void XmlOppfByttegruppe::Merge() {
    kat->Merge(*this);
}

std::shared_ptr<XMLObject> KatByttegruppeHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                               const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<Fest> fest = std::dynamic_pointer_cast<Fest>(parent);
    if (!fest) {
        std::cerr << "Error: Unexpected KatByttegruppe\n";
        return {};
    }
    return std::make_shared<KatByttegruppe>(fest);
}

bool KatByttegruppeHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    return true;
}

std::shared_ptr<XMLObject> XmlOppfByttegruppeHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                   const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<KatByttegruppe> kat = std::dynamic_pointer_cast<KatByttegruppe>(parent);
    if (!kat) {
        std::cerr << "Error: Unexpected OppfByttegruppe\n";
        return {};
    }
    return std::make_shared<XmlOppfByttegruppe>(kat);
}

bool XmlOppfByttegruppeHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *b = dynamic_cast<XmlOppfByttegruppe *>(&(*obj));
    if (b == nullptr) {
        std::cerr << "Error: Not ending OppfByttegruppe\n";
        return false;
    }
    b->Merge();
    return true;
}