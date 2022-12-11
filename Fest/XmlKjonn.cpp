//
// Created by sigsegv on 12/11/22.
//

#include "XmlKjonn.h"

void XmlKjonn::SetKjonn(const ValueWithDistinguishedName &kjonn) {
    this->kjonn = kjonn;
}

ValueWithDistinguishedName XmlKjonn::GetKjonn() const {
    return kjonn;
}

bool XmlKjonnHandler::Merge(std::shared_ptr<XmlType> obj) {
    obj->GetParent()->SetKjonn({obj->GetValueWithDistinguishedName()});
    return true;
}