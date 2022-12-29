//
// Created by sigsegv on 12/29/22.
//

#include "XmlLegemiddeldose.h"
#include "KatLegemiddeldose.h"
#include <iostream>

std::string XmlLegemiddeldose::GetName() const {
    return "Legemiddeldose";
}

void XmlLegemiddeldose::SetLmrLopenr(const std::string &lmrLopenr) {
    this->lmrLopenr = lmrLopenr;
}

bool XmlLegemiddeldose::Mengde(const ValueUnit &mengde) {
    this->mengde = mengde;
    return true;
}

bool XmlLegemiddeldose::Mengde(const std::string &) {
    std::cerr << "Error: At Legemiddeldose, unexpected Mengde without unit\n";
    return false;
}

bool XmlLegemiddeldose::Merge(const PakningskomponentInfo &pakningskomponent) {
    this->pakningskomponent.emplace_back(pakningskomponent);
    return true;
}

bool XmlLegemiddeldose::Merge() {
    parent->SetLegemiddeldose({{GetAtc(), GetNavnFormStyrke(), GetReseptgruppe(), GetLegemiddelformKort(),
                                GetRefVilkar(), GetTypeSoknadSlv(), GetOpioidsoknad(), GetSvartTrekant()},
                               GetPreparattype(), GetId(), lmrLopenr, mengde, GetRefLegemiddelMerkevare(),
                               GetRefPakning(), pakningskomponent, GetPakningstype()});
    return true;
}

std::shared_ptr<XMLObject> XmlLegemiddeldoseHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                  const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlOppfLegemiddeldose> oppf = std::dynamic_pointer_cast<XmlOppfLegemiddeldose>(parent);
    if (!oppf) {
        std::cerr << "Error: Unexpected Legemiddeldose\n";
        return {};
    }
    return std::make_shared<XmlLegemiddeldose>(oppf);
}

bool XmlLegemiddeldoseHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *l = dynamic_cast<XmlLegemiddeldose *>(&(*obj));
    if (l == nullptr) {
        std::cerr << "Error: Not ending Legemiddeldose\n";
        return false;
    }
    return l->Merge();
}

bool XmlLmrLopenrHandler::Merge(std::shared_ptr<XmlLegemiddeldose> parent, const std::string &content) {
    parent->SetLmrLopenr(content);
    return true;
}
