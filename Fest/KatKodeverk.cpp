//
// Created by sigsegv on 12/27/22.
//

#include "KatKodeverk.h"
#include <Fest/Fest.h>
#include <iostream>

std::string KatKodeverk::GetName() const {
    return "KatKodeverk";
}

void KatKodeverk::Merge(XmlOppfKodeverk &oppf) {
    fest->Add(oppf);
}

std::string XmlOppfKodeverk::GetName() const {
    return "OppfKodeverk";
}

void XmlOppfKodeverk::SetInfo(const Info &info) {
    this->info = info;
}

Info XmlOppfKodeverk::GetInfo() const {
    return info;
}

void XmlOppfKodeverk::AddElement(const Element &element) {
    this->element.emplace_back(element);
}

std::vector<Element> XmlOppfKodeverk::GetElement() const {
    return element;
}

void XmlOppfKodeverk::Merge() {
    kat->Merge(*this);
}

std::shared_ptr<XMLObject> KatKodeverkHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                            const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<Fest> fest = std::dynamic_pointer_cast<Fest>(parent);
    if (!fest) {
        std::cerr << "Error: Unexpected KatKodeverk\n";
        return {};
    }
    return std::make_shared<KatKodeverk>(fest);
}

bool KatKodeverkHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    return true;
}

std::shared_ptr<XMLObject> OppfKodeverkHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                             const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<KatKodeverk> kat = std::dynamic_pointer_cast<KatKodeverk>(parent);
    if (!kat) {
        std::cerr << "Error: Unexpected OppfKodeverk\n";
    }
    return std::make_shared<XmlOppfKodeverk>(kat);
}

bool OppfKodeverkHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *k = dynamic_cast<XmlOppfKodeverk *>(&(*obj));
    if (k == nullptr) {
        std::cerr << "Error: Not ending OppfKodeverk\n";
        return false;
    }
    k->Merge();
    return true;
}