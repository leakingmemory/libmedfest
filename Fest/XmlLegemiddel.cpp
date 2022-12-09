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

LegemiddelformKort XmlLegemiddel::GetLegemiddelformKort() const {
    return legemiddelformKort;
}

void XmlLegemiddel::SetLegemiddelformKort(const LegemiddelformKort &legemiddelformKort) {
    this->legemiddelformKort = legemiddelformKort;
}

std::vector<std::string> XmlLegemiddel::GetRefVilkar() const {
    return refVilkar;
}

void XmlLegemiddel::AddRefVilkar(const std::string &refVilkar) {
    this->refVilkar.push_back(refVilkar);
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

bool XmlNavnFormStyrkeHandler::Merge(std::shared_ptr<XmlLegemiddel> parent, const std::string &content) {
    parent->SetNavnFormStyrke(content);
    return true;
}

bool XmlReseptgruppeHandler::Merge(std::shared_ptr<XmlType> obj) {
    obj->GetParent()->SetReseptgruppe({obj->GetValueWithDistinguishedName()});
    return true;
}

bool XmlLegemiddelformKortHandler::Merge(std::shared_ptr<XmlValueWithCodeSet<XmlLegemiddel>> obj) {
    obj->GetParent()->SetLegemiddelformKort({obj->GetValueWithCodeSet()});
    return true;
}

bool XmlRefVilkarHandler::Merge(std::shared_ptr<XmlLegemiddel> parent, const std::string &content) {
    parent->AddRefVilkar(content);
    return true;
}
