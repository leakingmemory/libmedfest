//
// Created by sigsegv on 12/11/22.
//

#include "XmlRefVirkestoff.h"

void XmlRefVirkestoff::AddRefVirkestoff(const std::string &ref) {
    refs.push_back(ref);
}

std::vector<std::string> XmlRefVirkestoff::GetRefVirkestoff() const {
    return refs;
}

bool XmlRefVirkestoffHandler::Merge(std::shared_ptr<XmlRefVirkestoff> parent, const std::string &content) {
    parent->AddRefVirkestoff(content);
    return true;
}