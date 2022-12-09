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

Reseptgruppe XmlLegemiddel::GetReseptgruppe() {
    return reseptgruppe;
}

void XmlLegemiddel::SetReseptgruppe(const Reseptgruppe &reseptgruppe) {
    this->reseptgruppe = reseptgruppe;
}

std::string XmlAtc::GetName() const {
    return "Atc";
}

std::string XmlNavnFormStyrke::GetName() const {
    return "NavnFormStyrke";
}

bool XmlNavnFormStyrke::AppendCharacterData(const std::string &charData) {
    navnFormStyrke.append(charData);
    return true;
}

void XmlNavnFormStyrke::Merge() {
    legemiddel->SetNavnFormStyrke(navnFormStyrke);
}

bool XmlAtcHandler::Merge(std::shared_ptr<XmlValueWithCodeSet<XmlLegemiddel>> obj) {
    obj->GetParent()->SetAtc(Atc(obj->GetValueWithCodeSet()));
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

bool XmlReseptgruppeHandler::Merge(std::shared_ptr<XmlType> obj) {
    obj->GetParent()->SetReseptgruppe({obj->GetValueWithDistinguishedName()});
    return true;
}
