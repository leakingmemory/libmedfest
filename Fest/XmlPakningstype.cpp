//
// Created by sigsegv on 12/13/22.
//

#include "XmlPakningstype.h"

void XmlPakningstype::SetPakningstype(const Pakningstype &pakningstype) {
    this->pakningstype = pakningstype;
}

Pakningstype XmlPakningstype::GetPakningstype() const {
    return pakningstype;
}

bool XmlPakningstypeHandler::Merge(std::shared_ptr<XmlValueWithCodeSet<XmlPakningstype>> obj) {
    obj->GetParent()->SetPakningstype({obj->GetValueWithCodeSet()});
    return true;
}
