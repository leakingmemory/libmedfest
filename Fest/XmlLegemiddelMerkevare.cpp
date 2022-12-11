//
// Created by jeo on 12/9/22.
//

#include "XmlLegemiddelMerkevare.h"
#include <iostream>


std::string XmlLegemiddelMerkevare::GetName() const {
    return "LegemiddelMerkevare";
}

void XmlLegemiddelMerkevare::SetVarenavn(const std::string &varenavn) {
    this->varenavn = varenavn;
}

void XmlLegemiddelMerkevare::SetLegemiddelformLang(const std::string &legemiddelformLang) {
    this->legemiddelformLang = legemiddelformLang;
}

void XmlLegemiddelMerkevare::SetProdusent(const std::string &produsent) {
    this->produsent = produsent;
}

void XmlLegemiddelMerkevare::AddReseptgyldighet(const Reseptgyldighet &reseptgyldighet) {
    this->reseptgyldighet.push_back(reseptgyldighet);
}

void XmlLegemiddelMerkevare::SetVarseltrekant(MaybeBoolean varseltrekant) {
    this->varseltrekant = varseltrekant;
}

void XmlLegemiddelMerkevare::SetReferanseprodukt(const std::string &referanseprodukt) {
    this->referanseprodukt = referanseprodukt;
}

void XmlLegemiddelMerkevare::SetPreparatomtaleavsnitt(const Preparatomtaleavsnitt &preparatomtaleavsnitt) {
    this->preparatomtaleavsnitt = preparatomtaleavsnitt;
}

void XmlLegemiddelMerkevare::SetSmak(const Smak &smak) {
    this->smak = smak;
}

void XmlLegemiddelMerkevare::Merge() {
    oppfLegemiddelMerkevare->SetLegemiddelMerkevare({{
                GetAtc(),
                GetNavnFormStyrke(),
                GetReseptgruppe(),
                GetLegemiddelformKort(),
                GetRefVilkar(),
                GetTypeSoknadSlv(),
                GetAdministreringLegemiddel(),
                GetSortertVirkestoffMedStyrke(),
                GetOpioidsoknad(),
                GetSvartTrekant()
            },
            GetPreparattype(),
            varenavn,
            legemiddelformLang,
            produsent,
            reseptgyldighet,
            varseltrekant,
            referanseprodukt,
            preparatomtaleavsnitt,
            smak,
            GetSortertVirkestoffUtenStyrke()
        });
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

bool XmlVarenavnHandler::Merge(std::shared_ptr<XmlLegemiddelMerkevare> parent, const std::string &content) {
    parent->SetVarenavn(content);
    return true;
}

bool XmlLegemiddelformLangHandler::Merge(std::shared_ptr<XmlLegemiddelMerkevare> parent, const std::string &content) {
    parent->SetLegemiddelformLang(content);
    return true;
}

bool XmlSmakHandler::Merge(std::shared_ptr<XmlType> obj) {
    obj->GetParent()->SetSmak({obj->GetValueWithDistinguishedName()});
    return true;
}