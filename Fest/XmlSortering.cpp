//
// Created by sigsegv on 12/10/22.
//

#include "XmlSortering.h"

int XmlSortering::GetSortering() const {
    return sortering;
}

void XmlSortering::SetSortering(int sortering) {
    this->sortering = sortering;
}

bool XmlSorteringHandler::Merge(std::shared_ptr<XmlSortering> parent, const std::string &content) {
    char *endptr;
    auto sortering = std::strtol(content.c_str(), &endptr, 10);
    if (endptr == nullptr || *endptr != '\0') {
        std::cerr << "Error: Invalid integer for Sortering: " << content << "\n";
        return false;
    }
    parent->SetSortering(sortering);
    return true;
}