//
// Created by sigsegv on 12/11/22.
//

#include "XmlLegemiddelpakning.h"

std::string XmlLegemiddelpakning::GetName() const {
    return "Legemiddelpakning";
}

void XmlLegemiddelpakning::Merge() {
    oppfLegemiddelpakning->SetLegemiddelpakning({{
            GetAtc(),
            GetNavnFormStyrke(),
            GetReseptgruppe(),
            GetLegemiddelformKort(),
            GetRefVilkar(),
            GetTypeSoknadSlv(),
            GetOpioidsoknad(),
            GetSvartTrekant()
        },
        GetPreparattype()
    });
}

std::shared_ptr<XMLObject> XmlLegemiddelpakningHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                     const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlOppfLegemiddelpakning> oppf = std::dynamic_pointer_cast<XmlOppfLegemiddelpakning>(parent);
    if (!oppf) {
        std::cerr << "Error: Legemiddelpakning not expected here\n";
        return {};
    }
    return std::make_shared<XmlLegemiddelpakning>(oppf);
}

bool XmlLegemiddelpakningHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *oppf = dynamic_cast<XmlLegemiddelpakning*>(&(*obj));
    if (oppf == nullptr) {
        std::cerr << "Error: End of Legemiddelpakning, but not currently a L..\n";
        return false;
    }
    oppf->Merge();
    return true;
}