//
// Created by sigsegv on 12/16/22.
//

#include "XmlNavn.h"

void XmlNavn::SetNavn(const std::string &name) {
    this->navn = name;
}

std::string XmlNavn::GetNavn() const {
    return navn;
}

bool XmlNavnHandler::Merge(std::shared_ptr<XmlNavn> parent, const std::string &content) {
    parent->SetNavn(content);
    return true;
}