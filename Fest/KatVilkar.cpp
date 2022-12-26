//
// Created by sigsegv on 12/26/22.
//

#include "KatVilkar.h"
#include <iostream>

std::string KatVilkar::GetName() const {
    return "KatVilkar";
}

void KatVilkar::Merge(const XmlOppfVilkar &oppf) {
    fest->Add(oppf);
}

std::string XmlOppfVilkar::GetName() const {
    return "OppfVilkar";
}

void XmlOppfVilkar::SetVilkar(const Vilkar &vilkar) {
    this->vilkar = vilkar;
}

Vilkar XmlOppfVilkar::GetVilkar() const {
    return vilkar;
}

void XmlOppfVilkar::Merge() {
    kat->Merge(*this);
}

std::shared_ptr<XMLObject> KatVilkarHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                          const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<Fest> fest = std::dynamic_pointer_cast<Fest>(parent);
    if (!fest) {
        std::cerr << "Error: Unexpected KatVilkar\n";
        return {};
    }
    return std::make_shared<KatVilkar>(fest);
}

bool KatVilkarHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    return true;
}

std::shared_ptr<XMLObject> OppfVilkarHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                           const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<KatVilkar> kat = std::dynamic_pointer_cast<KatVilkar>(parent);
    if (!kat) {
        std::cerr << "Error: Unexpected OppfVilkar\n";
        return {};
    }
    return std::make_shared<XmlOppfVilkar>(kat);
}

bool OppfVilkarHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *v = dynamic_cast<XmlOppfVilkar *>(&(*obj));
    if (v == nullptr) {
        std::cerr << "Error: Not ending OppfVilkar\n";
        return false;
    }
    v->Merge();
    return true;
}