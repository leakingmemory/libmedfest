//
// Created by sigsegv on 12/26/22.
//

#include "XmlType.h"

void XmlTypeObject::SetType(const ValueWithCodeSet &type) {
    this->type = type;
}

ValueWithCodeSet XmlTypeObject::GetType() const {
    return type;
}

bool XmlTypeHandler::Merge(std::shared_ptr<XmlValueWithCodeSet<XmlTypeObject>> obj) {
    obj->GetParent()->SetType(obj->GetValueWithCodeSet());
    return true;
}
