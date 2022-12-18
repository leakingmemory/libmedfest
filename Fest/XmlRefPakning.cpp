//
// Created by sigsegv on 12/18/22.
//

#include "XmlRefPakning.h"

void XmlRefPakning::AddRefPakning(const std::string &ref) {
    refs.emplace_back(ref);
}

std::vector<std::string> XmlRefPakning::GetRefPakning() const {
    return refs;
}

bool XmlRefPakningHandler::Merge(std::shared_ptr<XmlRefPakning> parent, const std::string &content) {
    parent->AddRefPakning(content);
    return true;
}