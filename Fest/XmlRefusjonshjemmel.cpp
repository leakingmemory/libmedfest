//
// Created by sigsegv on 12/24/22.
//

#include "XmlRefusjonshjemmel.h"
#include <iostream>

std::string XmlRefusjonshjemmel::GetName() const {
    return "Refusjonshjemmel";
}

void XmlRefusjonshjemmel::SetRefusjonshjemmel(const ValueWithCodeSet &refusjonshjemmel) {
    this->refusjonshjemmel = refusjonshjemmel;
}

void XmlRefusjonshjemmel::SetKreverVarekobling(bool kreverVarekobling) {
    this->kreverVarekobling = kreverVarekobling ? MaybeBoolean::TRUE : MaybeBoolean::FALSE;
}

void XmlRefusjonshjemmel::SetKreverVedtak(bool kreverVedtak) {
    this->kreverVedtak = kreverVedtak ? MaybeBoolean::TRUE : MaybeBoolean::FALSE;
}

void XmlRefusjonshjemmel::SetRefusjonsgruppe(const Refusjonsgruppe &refusjonsgruppe) {
    this->refusjongruppe = refusjonsgruppe;
}

bool XmlRefusjonshjemmel::Merge() {
    bool kreverVarekobling;
    switch (this->kreverVarekobling) {
        case MaybeBoolean::FALSE:
            kreverVarekobling = false;
            break;
        case MaybeBoolean::TRUE:
            kreverVarekobling = true;
            break;
        default:
            std::cerr << "Error: Refusjonshjemmel: Missing value for KreverVarekobling\n";
            return false;
    }
    bool kreverVedtak;
    switch (this->kreverVedtak) {
        case MaybeBoolean::FALSE:
            kreverVedtak = false;
            break;
        case MaybeBoolean::TRUE:
            kreverVedtak = true;
            break;
        default:
            std::cerr << "Error: Refusjonshjemmel: Missing value for KreverVedtak\n";
            return false;
    }
    parent->SetRefusjonshjemmel({refusjonshjemmel, kreverVarekobling, kreverVedtak, refusjongruppe});
    return true;
}

std::shared_ptr<XMLObject> XmlRefusjonshjemmelHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                    const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlOppfRefusjon> oppf = std::dynamic_pointer_cast<XmlOppfRefusjon>(parent);
    if (!oppf) {
        return XmlValueWithCodeSetHandler<XmlRefusjonshjemmel>::StartElement(parent, attributes);
    }
    return std::make_shared<XmlRefusjonshjemmel>(oppf);
}

bool XmlRefusjonshjemmelHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *r = dynamic_cast<XmlRefusjonshjemmel *>(&(*obj));
    if (r == nullptr) {
        return XmlValueWithCodeSetHandler<XmlRefusjonshjemmel>::EndElement(obj);
    }
    return r->Merge();
}

bool XmlRefusjonshjemmelHandler::Merge(std::shared_ptr<XmlValueWithCodeSet<XmlRefusjonshjemmel>> obj) {
    obj->GetParent()->SetRefusjonshjemmel(obj->GetValueWithCodeSet());
    return true;
}

bool XmlKreverVarekoblingHandler::Merge(std::shared_ptr<XmlRefusjonshjemmel> parent, const std::string &content) {
    if (content == "true") {
        parent->SetKreverVarekobling(true);
        return true;
    } else if (content == "false") {
        parent->SetKreverVarekobling(false);
        return true;
    } else {
        std::cerr << "Error: KreverVarekobling: Invalid value: " << content << "\n";
        return false;
    }
}

bool XmlKreverVedtakHandler::Merge(std::shared_ptr<XmlRefusjonshjemmel> parent, const std::string &content) {
    if (content == "true") {
        parent->SetKreverVedtak(true);
        return true;
    } else if (content == "false") {
        parent->SetKreverVedtak(false);
        return true;
    } else {
        std::cerr << "Error: KreverVedtak: Invalid value: " << content << "\n";
        return false;
    }
}