//
// Created by sigsegv on 12/25/22.
//

#include "XmlAtc.h"

void XmlAtc::SetAtc(const Atc &atc) {
    this->atc = atc;
}

Atc XmlAtc::GetAtc() const {
    return atc;
}

bool XmlAtcHandler::Merge(std::shared_ptr<XmlValueWithCodeSet<XmlAtc>> obj) {
    obj->GetParent()->SetAtc(Atc(obj->GetValueWithCodeSet()));
    return true;
}
