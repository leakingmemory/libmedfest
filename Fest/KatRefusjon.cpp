//
// Created by sigsegv on 12/23/22.
//

#include "KatRefusjon.h"
#include <iostream>

std::string KatRefusjon::GetName() const {
    return "KatRefusjon";
}

void KatRefusjon::Merge(const XmlOppfRefusjon &oppf) {
    fest->Add(oppf);
}

std::shared_ptr<XMLObject> KatRefusjonHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                            const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<Fest> fest = std::dynamic_pointer_cast<Fest>(parent);
    if (!fest) {
        std::cerr << "Error: KatRefusjon parent is not Fest\n";
        return {};
    }
    return std::make_shared<KatRefusjon>(fest);
}

bool KatRefusjonHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    return true;
}

std::string XmlOppfRefusjon::GetName() const {
    return "OppfRefusjon";
}

void XmlOppfRefusjon::SetRefusjonshjemmel(const Refusjonshjemmel &refusjonshjemmel) {
    this->refusjonshjemmel = refusjonshjemmel;
}

Refusjonshjemmel XmlOppfRefusjon::GetRefusjonshjemmel() const {
    return refusjonshjemmel;
}

void XmlOppfRefusjon::Merge() {
    parent->Merge(*this);
}

std::shared_ptr<XMLObject> OppfRefusjonHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                             const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<KatRefusjon> typedParent = std::dynamic_pointer_cast<KatRefusjon>(parent);
    if (!typedParent) {
        std::cerr << "Error: OppfRefusjon parent is not KatRefusjon\n";
        return {};
    }
    return std::make_shared<XmlOppfRefusjon>(typedParent);
}

bool OppfRefusjonHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *r = dynamic_cast<XmlOppfRefusjon *>(&(*obj));
    if (r == nullptr) {
        std::cerr << "Error: Not ending OppfRefusjon\n";
        return false;
    }
    r->Merge();
    return true;
}
