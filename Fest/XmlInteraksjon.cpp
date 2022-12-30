//
// Created by sigsegv on 12/29/22.
//

#include "XmlInteraksjon.h"
#include "KatInteraksjon.h"
#include <iostream>

std::string XmlInteraksjon::GetName() const {
    return "Interaksjon";
}

void XmlInteraksjon::SetRelevans(const Relevans &relevans) {
    this->relevans = relevans;
}

void XmlInteraksjon::SetKliniskKonsekvens(const std::string &kliniskKonsekvens) {
    this->kliniskKonsekvens = kliniskKonsekvens;
}

void XmlInteraksjon::SetInteraksjonsmekanisme(const std::string &interaksjonsmekanisme) {
    this->interaksjonsmekanisme = interaksjonsmekanisme;
}

void XmlInteraksjon::SetKildegrunnlag(const Kildegrunnlag &kildegrunnlag) {
    this->kildegrunnlag = kildegrunnlag;
}

void XmlInteraksjon::SetHandtering(const std::string &handtering) {
    this->handtering = handtering;
}

void XmlInteraksjon::AddReferanse(const Referanse &referanse) {
    this->referanse.emplace_back(referanse);
}

void XmlInteraksjon::AddSubstansgruppe(const Substansgruppe &substansgruppe) {
    this->substansgruppe.emplace_back(substansgruppe);
}

void XmlInteraksjon::SetSituasjonskriterium(const std::string &situasjonskriterium) {
    this->situasjonskriterium = situasjonskriterium;
}

bool XmlInteraksjon::Merge() {
    return parent->SetInteraksjon({GetId(), relevans, kliniskKonsekvens, interaksjonsmekanisme, kildegrunnlag,
                                   handtering, GetVisningsregel(), referanse, substansgruppe, situasjonskriterium});
}

std::shared_ptr<XMLObject> XmlInteraksjonHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                               const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlOppfInteraksjon> typedParent = std::dynamic_pointer_cast<XmlOppfInteraksjon>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected Interaksjon\n";
        return {};
    }
    return std::make_shared<XmlInteraksjon>(typedParent);
}

bool XmlInteraksjonHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *i = dynamic_cast<XmlInteraksjon *>(&(*obj));
    if (i == nullptr) {
        std::cerr << "Error: Not ending Interaksjon\n";
        return false;
    }
    return i->Merge();
}

bool XmlRelevansHandler::Merge(std::shared_ptr<XmlType> obj) {
    obj->GetParent()->SetRelevans({obj->GetValueWithDistinguishedName()});
    return true;
}

bool XmlKliniskKonsekvensHandler::Merge(std::shared_ptr<XmlInteraksjon> parent, const std::string &content) {
    parent->SetKliniskKonsekvens(content);
    return true;
}

bool XmlInteraksjonsmekanismeHandler::Merge(std::shared_ptr<XmlInteraksjon> parent, const std::string &content) {
    parent->SetInteraksjonsmekanisme(content);
    return true;
}

bool XmlKildegrunnlagHandler::Merge(std::shared_ptr<XmlType> obj) {
    obj->GetParent()->SetKildegrunnlag({obj->GetValueWithDistinguishedName()});
    return true;
}

bool XmlHandteringHandler::Merge(std::shared_ptr<XmlInteraksjon> parent, const std::string &content) {
    parent->SetHandtering(content);
    return true;
}

bool XmlSituasjonskriteriumHandler::Merge(std::shared_ptr<XmlInteraksjon> parent, const std::string &content) {
    parent->SetSituasjonskriterium(content);
    return true;
}