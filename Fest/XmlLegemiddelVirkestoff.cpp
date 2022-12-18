//
// Created by sigsegv on 12/18/22.
//

#include "XmlLegemiddelVirkestoff.h"
#include <iostream>

std::string XmlLegemiddelVirkestoff::GetName() const {
    return "LegemiddelVirkestoff";
}

bool XmlLegemiddelVirkestoff::SetForskrivningsenhetResept(const EnhetForskrivning &forskrivningsenhetResept) {
    if (!this->forskrivningsenhetResept.GetValue().empty()) {
        std::cerr << "Error: ForskrivningsenhetResept: Expected only one item\n";
        return false;
    }
    this->forskrivningsenhetResept = forskrivningsenhetResept;
    return true;
}

void XmlLegemiddelVirkestoff::Merge() {
    oppfLegemiddelVirkestoff->SetLegemiddelVirkestoff({{{
                                                                GetAtc(),
                                                                GetNavnFormStyrke(),
                                                                GetReseptgruppe(),
                                                                GetLegemiddelformKort(),
                                                                GetRefVilkar(),
                                                                GetTypeSoknadSlv(),
                                                                GetOpioidsoknad(),
                                                                GetSvartTrekant()
                                                        },
                                                        GetAdministreringLegemiddel(),
                                                        GetSortertVirkestoffMedStyrke()
                                                    },
                                                    GetRefusjon(),
                                                    GetRefLegemiddelMerkevare(),
                                                    GetRefPakning(),
                                                    forskrivningsenhetResept
    });
}

std::shared_ptr<XMLObject> XmlLegemiddelVirkestoffHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                        const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlOppfLegemiddelVirkestoff> oppf = std::dynamic_pointer_cast<XmlOppfLegemiddelVirkestoff>(parent);
    if (!oppf) {
        std::cerr << "Error: LegemiddelVirkestoff not expected here\n";
        return {};
    }
    return std::make_shared<XmlLegemiddelVirkestoff>(oppf);
}

bool XmlLegemiddelVirkestoffHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *oppf = dynamic_cast<XmlLegemiddelVirkestoff*>(&(*obj));
    if (oppf == nullptr) {
        std::cerr << "Error: End of LegemiddelVirkestoff, but not currently a L..\n";
        return false;
    }
    oppf->Merge();
    return true;
}

bool XmlForskrivningsenhetReseptHandler::Merge(std::shared_ptr<XmlValueWithCodeSet<XmlLegemiddelVirkestoff>> obj) {
    return obj->GetParent()->SetForskrivningsenhetResept({obj->GetValueWithCodeSet()});
}