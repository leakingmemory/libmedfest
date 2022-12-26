//
// Created by sigsegv on 12/12/22.
//

#include "XmlPrisVare.h"

void XmlPrisVare::AddPrisVare(const PrisVare &prisVare) {
    this->prisVare.emplace_back(prisVare);
}

std::vector<PrisVare> XmlPrisVare::GetPrisVare() const {
    return prisVare;
}

std::string XmlPrisVareObject::GetName() const {
    return "PrisVare";
}

void XmlPrisVareObject::SetPris(const Pris &pris) {
    this->pris = pris;
}

bool XmlPrisVareObject::Merge() {
    parent->AddPrisVare({GetType(), pris, GetGyldigFraDato(), GetGyldigTilDato()});
    return true;
}

std::shared_ptr<XMLObject> XmlPrisVareHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                            const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlPrisVare> typedParent = std::dynamic_pointer_cast<XmlPrisVare>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected PrisVare\n";
        return {};
    }
    return std::make_shared<XmlPrisVareObject>(typedParent);
}

bool XmlPrisVareHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *pi = dynamic_cast<XmlPrisVareObject *>(&(*obj));
    if (pi == nullptr) {
        std::cerr << "Error: Not ending PrisVare\n";
        return false;
    }
    return pi->Merge();
}

bool XmlPrisHandler::Merge(std::shared_ptr<XmlType> obj) {
    obj->GetParent()->SetPris({obj->GetValueUnit()});
    return true;
}
