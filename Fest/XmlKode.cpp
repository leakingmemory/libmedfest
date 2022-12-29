//
// Created by sigsegv on 12/29/22.
//

#include "XmlKode.h"

void XmlKode::SetKode(const std::string &kode) {
    this->kode = kode;
}

std::string XmlKode::GetKode() const {
    return kode;
}

void XmlKode::SetKode(const ValueWithDistinguishedName &kode) {
    this->vdnKode = kode;
}

ValueWithDistinguishedName XmlKode::GetKodeValueWithDN() const {
    return vdnKode;
}

std::shared_ptr<XMLObject> XmlKodeHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                        const std::map<std::string, std::string> &attributes) {
    if (attributes.find("V") != attributes.end()) {
        return XmlValueWithDistinguishedNameHandler<XmlKode>::StartElement(parent, attributes);
    } else {
        return XmlContentElementHandler<XmlKode>::StartElement(parent, attributes);
    }
}

bool XmlKodeHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    if (XmlValueWithDistinguishedNameHandler<XmlKode>::IsHandledBy(obj)) {
        return XmlValueWithDistinguishedNameHandler<XmlKode>::EndElement(obj);
    } else {
        return XmlContentElementHandler<XmlKode>::EndElement(obj);
    }
}

bool XmlKodeHandler::Merge(std::shared_ptr<XmlKode> parent, const std::string &content) {
    parent->SetKode(content);
    return true;
}

bool XmlKodeHandler::Merge(std::shared_ptr<XmlType> obj) {
    obj->GetParent()->SetKode(obj->GetValueWithDistinguishedName());
    return true;
}