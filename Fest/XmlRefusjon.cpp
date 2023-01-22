//
// Created by sigsegv on 12/13/22.
//

#include "XmlRefusjon.h"
#include <iostream>

void XmlRefusjon::AddRefusjon(const Refusjon &refusjon) {
    this->refusjon.emplace_back(refusjon);
}

std::vector<Refusjon> XmlRefusjon::GetRefusjon() const {
    return refusjon;
}

std::string XmlRefusjonObject::GetName() const {
    return "Refusjon";
}

void XmlRefusjonObject::AddRefRefusjonsgruppe(const std::string &ref) {
    this->ref.emplace_back(ref);
}

void XmlRefusjonObject::SetUtleveresTilDato(const std::string &utleveresTilDato) {
    this->utleveresTilDato = utleveresTilDato;
}

bool XmlRefusjonObject::Merge() {
    parent->AddRefusjon({ref, GetGyldigFraDato(), GetForskrivesTilDato(), utleveresTilDato});
    return true;
}

std::shared_ptr<XMLObject> XmlRefusjonHandler::StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &) {
    std::shared_ptr<XmlRefusjon> typedParent = std::dynamic_pointer_cast<XmlRefusjon>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected Refusjon\n";
        return {};
    }
    return std::make_shared<XmlRefusjonObject>(typedParent);
}

bool XmlRefusjonHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *r = dynamic_cast<XmlRefusjonObject *>(&(*obj));
    if (r == nullptr) {
        std::cerr << "Error: Did not end Refusjon\n";
        return false;
    }
    return r->Merge();
}

bool XmlRefRefusjonsgruppeHandler::Merge(std::shared_ptr<XmlRefusjonObject> parent, const std::string &content) {
    parent->AddRefRefusjonsgruppe(content);
    return true;
}

bool XmlUtleveresTilDatoHandler::Merge(std::shared_ptr<XmlRefusjonObject> parent, const std::string &content) {
    parent->SetUtleveresTilDato(content);
    return true;
}