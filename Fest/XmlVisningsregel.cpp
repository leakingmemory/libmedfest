//
// Created by sigsegv on 12/30/22.
//

#include "XmlVisningsregel.h"

void XmlVisningsregel::AddVisningsregel(const Visningsregel &visningsregel) {
    this->visningsregel.emplace_back(visningsregel);
}

std::vector<Visningsregel> XmlVisningsregel::GetVisningsregel() const {
    return visningsregel;
}

bool XmlVisningsregelHandler::Merge(std::shared_ptr<XmlValueWithCodeSet<XmlVisningsregel>> obj) {
    obj->GetParent()->AddVisningsregel({obj->GetValueWithCodeSet()});
    return true;
}
