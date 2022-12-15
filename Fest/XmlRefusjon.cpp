//
// Created by sigsegv on 12/13/22.
//

#include "XmlRefusjon.h"
#include <iostream>

void XmlRefusjon::SetRefusjon(const Refusjon &refusjon) {
    this->refusjon = refusjon;
}

Refusjon XmlRefusjon::GetRefusjon() const {
    return refusjon;
}

std::string XmlRefusjonObject::GetName() const {
    return "Refusjon";
}

void XmlRefusjonObject::SetRefRefusjonsgruppe(const std::string &ref) {
    this->ref = ref;
}

void XmlRefusjonObject::SetForskrivesTilDato(const std::string &forskrivesTilDato) {
    this->forskrivesTilDato = forskrivesTilDato;
}

bool XmlRefusjonObject::Merge() {
    parent->SetRefusjon({ref, GetGyldigFraDato(), forskrivesTilDato});
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
    parent->SetRefRefusjonsgruppe(content);
    return true;
}

bool XmlForskrivesTilDatoHandler::Merge(std::shared_ptr<XmlRefusjonObject> parent, const std::string &content) {
    parent->SetForskrivesTilDato(content);
    return true;
}