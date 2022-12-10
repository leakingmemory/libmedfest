//
// Created by sigsegv on 12/10/22.
//

#include "XmlRefVirkestoffMedStyrke.h"

void XmlRefVirkestoffMedStyrke::AddRefVirkestoffMedStyrke(const std::string &ref) {
    refs.push_back(ref);
}

std::vector<std::string> XmlRefVirkestoffMedStyrke::GetRefVirkestoffMedStyrke() const {
    return refs;
}

bool XmlRefVirkestoffMedStyrkeHandler::Merge(std::shared_ptr<XmlRefVirkestoffMedStyrke> parent, const std::string &content) {
    parent->AddRefVirkestoffMedStyrke(content);
    return true;
}