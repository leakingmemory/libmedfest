//
// Created by sigsegv on 12/9/22.
//

#include "XmlAdministreringLegemiddel.h"
#include "XmlLegemiddel.h"

std::string XmlAdministreringLegemiddel::GetName() const {
    return "AdministreringLegemiddel";
}

void XmlAdministreringLegemiddel::SetAdministrasjonsvei(const Administrasjonsvei &administrasjonsvei) {
    this->administrasjonsvei = administrasjonsvei;
}

void XmlAdministreringLegemiddel::SetEnhetDosering(const EnhetDosering &enhetDosering) {
    this->enhetDosering = enhetDosering;
}

void XmlAdministreringLegemiddel::AddBruksomradeEtikett(const BruksomradeEtikett &bruksomradeEtikett) {
    this->bruksomradeEtikett.push_back(bruksomradeEtikett);
}

void XmlAdministreringLegemiddel::SetKanKnuses(const KanKnuses &kanKnuses) {
    this->kanKnuses = kanKnuses;
}

void XmlAdministreringLegemiddel::AddForhandsregelInntak(const ForhandsregelInntak &forhandsregelInntak) {
    this->forhandsregelInntak.push_back(forhandsregelInntak);
}

void XmlAdministreringLegemiddel::AddKortdose(const Kortdose &kortdose) {
    this->kortdose.push_back(kortdose);
}

void XmlAdministreringLegemiddel::Merge() {
    parent->SetAdministreringLegemiddel({
        administrasjonsvei,
        enhetDosering,
        bruksomradeEtikett,
        kanKnuses,
        forhandsregelInntak,
        kortdose
    });
}

std::shared_ptr<XMLObject> XmlAdministreringLegemiddelHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                            const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlLegemiddel> typedParent = std::dynamic_pointer_cast<XmlLegemiddel>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpecgted AdministreringLegemiddel\n";
        return {};
    }
    return std::make_shared<XmlAdministreringLegemiddel>(typedParent);
}

bool XmlAdministreringLegemiddelHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *al = dynamic_cast<XmlAdministreringLegemiddel *>(&(*obj));
    if (al == nullptr) {
        std::cerr << "Error: End of not AdministreringLegemiddel\n";
        return false;
    }
    al->Merge();
    return true;
}

bool XmlAdministrasjonsveiHandler::Merge(std::shared_ptr<XmlValueWithCodeSet<XmlAdministreringLegemiddel>> obj) {
    obj->GetParent()->SetAdministrasjonsvei({obj->GetValueWithCodeSet()});
    return true;
}

bool XmlEnhetDoseringHandler::Merge(std::shared_ptr<XmlValueWithCodeSet<XmlAdministreringLegemiddel>> obj) {
    obj->GetParent()->SetEnhetDosering({obj->GetValueWithCodeSet()});
    return true;
}

bool XmlBruksomradeEtikettHandler::Merge(std::shared_ptr<XmlValueWithCodeSet<XmlAdministreringLegemiddel>> obj) {
    obj->GetParent()->AddBruksomradeEtikett({obj->GetValueWithCodeSet()});
    return true;
}

bool XmlKanKnusesHandler::Merge(std::shared_ptr<XmlType> obj) {
    obj->GetParent()->SetKanKnuses({obj->GetValueWithDistinguishedName()});
    return true;
}

bool XmlForhandsregelInntakHandler::Merge(std::shared_ptr<XmlValueWithCodeSet<XmlAdministreringLegemiddel>> obj) {
    obj->GetParent()->AddForhandsregelInntak({obj->GetValueWithCodeSet()});
    return true;
}

bool XmlKortdoseHandler::Merge(std::shared_ptr<XmlValueWithCodeSet<XmlAdministreringLegemiddel>> obj) {
    obj->GetParent()->AddKortdose({obj->GetValueWithCodeSet()});
    return true;
}