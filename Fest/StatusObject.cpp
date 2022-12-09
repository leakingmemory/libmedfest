//
// Created by jeo on 12/9/22.
//

#include "StatusObject.h"
#include <iostream>
#include <map>

Status StatusObject::GetStatus() const {
    return status;
}

void StatusObject::SetStatus(const Status &status) {
    this->status = status;
}

std::string XmlStatusObject::GetName() {
    return "Status";
}

std::shared_ptr<XMLObject> XmlStatusObjectHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                const std::map<std::string,std::string> &attributes) {
    std::shared_ptr<StatusObject> statusObject = std::dynamic_pointer_cast<StatusObject>(parent);
    if (!statusObject) {
        std::cerr << "Error: Status object, but parent doesn't implement status\n";
        return {};
    }
    auto i_dn = attributes.find("DN");
    auto i_v = attributes.find("V");
    auto lacking = i_dn == attributes.end() || i_v == attributes.end();
    if (lacking) {
        std::cerr << "Error: Status object lacks V and/or DN\n";
        return {};
    }
    statusObject->SetStatus({i_v->second, i_dn->second});
    return std::make_shared<XmlStatusObject>();
}

bool XmlStatusObjectHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    return dynamic_cast<XmlStatusObject*>(&(*obj)) != nullptr;
}
