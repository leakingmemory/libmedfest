//
// Created by jeo on 12/9/22.
//

#include "XmlPreparattypeObject.h"

void XmlPreparattypeObject::SetPreparattype(const Preparattype &preparattype) {
    this->preparattype = preparattype;
}

Preparattype XmlPreparattypeObject::GetPreparattype() const {
    return preparattype;
}

bool XmlPreparattypeObjectHandler::Merge(std::shared_ptr<XmlType> obj) {
    obj->GetParent()->SetPreparattype({obj->GetValueWithDistinguishedName()});
    return true;
}