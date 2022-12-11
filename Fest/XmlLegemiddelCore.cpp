//
// Created by jeo on 12/9/22.
//

#include "XmlLegemiddelCore.h"
#include <iostream>

Atc XmlLegemiddelCore::GetAtc() const {
    return atc;
}

void XmlLegemiddelCore::SetAtc(const Atc &atc) {
    this->atc = atc;
}

std::string XmlLegemiddelCore::GetNavnFormStyrke() {
    return navnFormStyrke;
}

void XmlLegemiddelCore::SetNavnFormStyrke(const std::string &navnFormStyrke) {
    this->navnFormStyrke = navnFormStyrke;
}

Reseptgruppe XmlLegemiddelCore::GetReseptgruppe() {
    return reseptgruppe;
}

void XmlLegemiddelCore::SetReseptgruppe(const Reseptgruppe &reseptgruppe) {
    this->reseptgruppe = reseptgruppe;
}

LegemiddelformKort XmlLegemiddelCore::GetLegemiddelformKort() const {
    return legemiddelformKort;
}

void XmlLegemiddelCore::SetLegemiddelformKort(const LegemiddelformKort &legemiddelformKort) {
    this->legemiddelformKort = legemiddelformKort;
}

std::vector<std::string> XmlLegemiddelCore::GetRefVilkar() const {
    return refVilkar;
}

void XmlLegemiddelCore::AddRefVilkar(const std::string &refVilkar) {
    this->refVilkar.push_back(refVilkar);
}

TypeSoknadSlv XmlLegemiddelCore::GetTypeSoknadSlv() const {
    return typeSoknadSlv;
}

void XmlLegemiddelCore::SetTypeSoknadSlv(const TypeSoknadSlv &typeSoknadSlv) {
    this->typeSoknadSlv = typeSoknadSlv;
}

MaybeBoolean XmlLegemiddelCore::GetOpioidsoknad() const {
    return opioidsoknad;
}

void XmlLegemiddelCore::SetOpioidsoknad(bool opioidsoknad) {
    this->opioidsoknad = opioidsoknad ? MaybeBoolean::TRUE : MaybeBoolean::FALSE;
}

SvartTrekant XmlLegemiddelCore::GetSvartTrekant() const {
    return svartTrekant;
}

void XmlLegemiddelCore::SetSvartTrekant(const SvartTrekant &svartTrekant) {
    this->svartTrekant = svartTrekant;
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

bool XmlAtcHandler::Merge(std::shared_ptr<XmlValueWithCodeSet<XmlLegemiddelCore>> obj) {
    obj->GetParent()->SetAtc(Atc(obj->GetValueWithCodeSet()));
    return true;
}

bool XmlNavnFormStyrkeHandler::Merge(std::shared_ptr<XmlLegemiddelCore> parent, const std::string &content) {
    parent->SetNavnFormStyrke(content);
    return true;
}

bool XmlReseptgruppeHandler::Merge(std::shared_ptr<XmlType> obj) {
    obj->GetParent()->SetReseptgruppe({obj->GetValueWithDistinguishedName()});
    return true;
}

bool XmlLegemiddelformKortHandler::Merge(std::shared_ptr<XmlValueWithCodeSet<XmlLegemiddelCore>> obj) {
    obj->GetParent()->SetLegemiddelformKort({obj->GetValueWithCodeSet()});
    return true;
}

bool XmlRefVilkarHandler::Merge(std::shared_ptr<XmlLegemiddelCore> parent, const std::string &content) {
    parent->AddRefVilkar(content);
    return true;
}

bool XmlTypeSoknadSlvHandler::Merge(std::shared_ptr<XmlType> obj) {
    obj->GetParent()->SetTypeSoknadSlv({obj->GetValueWithDistinguishedName()});
    return true;
}

bool XmlOpioidsoknadHandler::Merge(std::shared_ptr<XmlLegemiddelCore> parent, const std::string &content) {
    if (content == "true") {
        parent->SetOpioidsoknad(true);
        return true;
    } else if (content == "false") {
        parent->SetOpioidsoknad(false);
        return true;
    }
    std::cerr << "Error: Opioidsoknad: Unrecognized value: " << content << "\n";
    return false;
}

bool XmlSvartTrekantHandler::Merge(std::shared_ptr<XmlValueWithCodeSet<XmlLegemiddelCore>> obj) {
    obj->GetParent()->SetSvartTrekant({obj->GetValueWithCodeSet()});
    return true;
}
