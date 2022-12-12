//
// Created by sigsegv on 12/12/22.
//

#include "XmlPrisVare.h"

std::string XmlPrisVare::GetName() const {
    return "PrisVare";
}

void XmlPrisVare::SetType(const ValueWithCodeSet &type) {
    this->type = type;
}

void XmlPrisVare::SetPris(const Pris &pris) {
    this->pris = pris;
}

void XmlPrisVare::SetGyldigFraDato(const std::string &gyldigFraDato) {
    this->gyldigFraDato = gyldigFraDato;
}

bool XmlPrisVare::Merge() {
    parent->AddPrisVare({type, pris, gyldigFraDato});
    return true;
}

std::shared_ptr<XMLObject> XmlPrisVareHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                            const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlLegemiddelpakning> typedParent = std::dynamic_pointer_cast<XmlLegemiddelpakning>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected PrisVare\n";
        return {};
    }
    return std::make_shared<XmlPrisVare>(typedParent);
}

bool XmlPrisVareHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *pi = dynamic_cast<XmlPrisVare *>(&(*obj));
    if (pi == nullptr) {
        std::cerr << "Error: Not ending PrisVare\n";
        return false;
    }
    return pi->Merge();
}

bool XmlTypeHandler::Merge(std::shared_ptr<XmlValueWithCodeSet<XmlPrisVare>> obj) {
    obj->GetParent()->SetType(obj->GetValueWithCodeSet());
    return true;
}

bool XmlPrisHandler::Merge(std::shared_ptr<XmlType> obj) {
    obj->GetParent()->SetPris({obj->GetValueUnit()});
    return true;
}

bool XmlGyldigFraDatoHandler::Merge(std::shared_ptr<XmlPrisVare> parent, const std::string &content) {
    parent->SetGyldigFraDato(content);
    return true;
}