//
// Created by sigsegv on 12/25/22.
//

#include "XmlRefVilkar.h"

std::vector<std::string> XmlRefVilkar::GetRefVilkar() const {
    return refVilkar;
}

void XmlRefVilkar::AddRefVilkar(const std::string &refVilkar) {
    this->refVilkar.emplace_back(refVilkar);
}

bool XmlRefVilkarHandler::Merge(std::shared_ptr<XmlRefVilkar> parent, const std::string &content) {
    parent->AddRefVilkar(content);
    return true;
}