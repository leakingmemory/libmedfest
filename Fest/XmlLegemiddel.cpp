//
// Created by jeo on 12/9/22.
//

#include "XmlLegemiddel.h"
#include <iostream>

Atc XmlLegemiddel::GetAtc() const {
    return atc;
}

void XmlLegemiddel::SetAtc(const Atc &atc) {
    this->atc = atc;
}

std::string XmlLegemiddel::GetNavnFormStyrke() {
    return navnFormStyrke;
}

void XmlLegemiddel::SetNavnFormStyrke(const std::string &navnFormStyrke) {
    this->navnFormStyrke = navnFormStyrke;
}

std::string XmlAtc::GetName() {
    return "Atc";
}

std::string XmlNavnFormStyrke::GetName() {
    return "NavnFormStyrke";
}

bool XmlNavnFormStyrke::AppendCharacterData(const std::string &charData) {
    navnFormStyrke.append(charData);
    return true;
}

void XmlNavnFormStyrke::Merge() {
    legemiddel->SetNavnFormStyrke(navnFormStyrke);
}

std::shared_ptr<XMLObject> XmlAtcHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                       const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlLegemiddel> legemiddel = std::dynamic_pointer_cast<XmlLegemiddel>(parent);
    if (!legemiddel) {
        std::cerr << "Error: Unexpected Atc here\n";
        return {};
    }
    auto i_v = attributes.find("V");
    auto i_s = attributes.find("S");
    auto i_dn = attributes.find("DN");
    if (i_v == attributes.end() || i_s == attributes.end() || i_dn == attributes.end()) {
        std::cerr << "Error: Atc requires V, S and DN\n";
        return {};
    }
    legemiddel->SetAtc({i_v->second, i_s->second, i_dn->second});
    return std::make_shared<XmlAtc>();
}

bool XmlAtcHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    return true;
}

std::shared_ptr<XMLObject> XmlNavnFormStyrkeHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                  const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlLegemiddel> legemiddel = std::dynamic_pointer_cast<XmlLegemiddel>(parent);
    if (!legemiddel) {
        std::cerr << "Error: NavnFormStyrke not accepted here\n";
        return {};
    }
    return std::make_shared<XmlNavnFormStyrke>(legemiddel);
}

bool XmlNavnFormStyrkeHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *nfs = dynamic_cast<XmlNavnFormStyrke*>(&(*obj));
    if (nfs == nullptr) {
        std::cerr << "Error: Ending, but not a NavnFormStyrke\n";
        return false;
    }
    nfs->Merge();
    return true;
}