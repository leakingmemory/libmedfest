//
// Created by sigsegv on 12/25/22.
//

#include "XmlRefusjonskode.h"

std::string XmlRefusjonskode::GetName() const {
    return "Refusjonskode";
}

void XmlRefusjonskode::SetRefusjonskode(const ValueWithCodeSet &refusjonskode) {
    this->refusjonskode = refusjonskode;
}

void XmlRefusjonskode::AddUnderterm(const std::string &underterm) {
    this->underterm.emplace_back(underterm);
}

bool XmlRefusjonskode::Merge() {
    parent->AddRefusjonskode({refusjonskode, GetGyldigFraDato(), GetForskrivesTilDato(), GetUtleveresTilDato(), underterm, GetRefusjonsvilkar()});
    return true;
}

std::shared_ptr<XMLObject> XmlRefusjonskodeHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                 const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlRefusjonsgruppe> typeParent = std::dynamic_pointer_cast<XmlRefusjonsgruppe>(parent);
    if (!typeParent) {
        return XmlValueWithCodeSetHandler<XmlRefusjonskode>::StartElement(parent, attributes);
    }
    return std::make_shared<XmlRefusjonskode>(typeParent);
}

bool XmlRefusjonskodeHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *r = dynamic_cast<XmlRefusjonskode *>(&(*obj));
    if (r == nullptr) {
        return XmlValueWithCodeSetHandler<XmlRefusjonskode>::EndElement(obj);
    }
    return r->Merge();
}

bool XmlRefusjonskodeHandler::Merge(std::shared_ptr<XmlValueWithCodeSet<XmlRefusjonskode>> obj) {
    obj->GetParent()->SetRefusjonskode(obj->GetValueWithCodeSet());
    return true;
}

bool XmlUndertermHandler::Merge(std::shared_ptr<XmlRefusjonskode> parent, const std::string &content) {
    parent->AddUnderterm(content);
    return true;
}