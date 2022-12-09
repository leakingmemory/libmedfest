//
// Created by jeo on 12/9/22.
//

#include "XmlLegemiddelMerkevare.h"
#include <iostream>


std::string XmlLegemiddelMerkevare::GetName() {
    return "LegemiddelMerkevare";
}

void XmlLegemiddelMerkevare::Merge() {
    oppfLegemiddelMerkevare->SetLegemiddelMerkevare({{
        GetAtc(),
        GetNavnFormStyrke()
    }});
}

std::shared_ptr<XMLObject> XmlLegemiddelMerkevareHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                       const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlOppfLegemiddelMerkevare> oppf = std::dynamic_pointer_cast<XmlOppfLegemiddelMerkevare>(parent);
    if (!oppf) {
        std::cerr << "Error: LegemiddelMerkevare not expected here\n";
        return {};
    }
    return std::make_shared<XmlLegemiddelMerkevare>(oppf);
}

bool XmlLegemiddelMerkevareHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *oppf = dynamic_cast<XmlLegemiddelMerkevare*>(&(*obj));
    if (oppf == nullptr) {
        std::cerr << "Error: End of LegemiddelMerkevare, but not currently a L..\n";
        return false;
    }
    oppf->Merge();
    return true;
}