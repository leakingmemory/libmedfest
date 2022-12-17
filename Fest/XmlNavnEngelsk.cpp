//
// Created by sigsegv on 12/17/22.
//

#include "XmlNavnEngelsk.h"


void XmlNavnEngelsk::SetNavnEngelsk(const std::string &name) {
    this->navnEngelsk = name;
}

std::string XmlNavnEngelsk::GetNavnEngelsk() const {
    return navnEngelsk;
}

bool XmlNavnEngelskHandler::Merge(std::shared_ptr<XmlNavnEngelsk> parent, const std::string &content) {
    parent->SetNavnEngelsk(content);
    return true;
}