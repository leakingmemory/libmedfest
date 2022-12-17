//
// Created by sigsegv on 12/16/22.
//

#include "XmlVirkestoff.h"
#include <iostream>

std::string XmlVirkestoff::GetName() const {
    return "Virkestoff";
}

void XmlVirkestoff::Merge() {
    oppfVirkestoff->SetVirkestoff({GetId(), GetNavn(), GetNavnEngelsk(), GetRefVirkestoff()});
}

std::shared_ptr<XMLObject> XmlVirkestoffHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                              const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlOppfVirkestoff> oppf = std::dynamic_pointer_cast<XmlOppfVirkestoff>(parent);
    if (!oppf) {
        std::cerr << "Error: Virkestoff not expected here\n";
        return {};
    }
    return std::make_shared<XmlVirkestoff>(oppf);
}

bool XmlVirkestoffHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *oppf = dynamic_cast<XmlVirkestoff*>(&(*obj));
    if (oppf == nullptr) {
        std::cerr << "Error: End of Virkestoff, but not currently a V..\n";
        return false;
    }
    oppf->Merge();
    return true;
}