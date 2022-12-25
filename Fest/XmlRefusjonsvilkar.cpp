//
// Created by sigsegv on 12/25/22.
//

#include "XmlRefusjonsvilkar.h"
#include <iostream>

void XmlRefRefusjonsvilkar::AddRefusjonsvilkar(const RefRefusjonsvilkar &refusjonsvilkar) {
    this->refusjonsvilkar.emplace_back(refusjonsvilkar);
}

std::vector<RefRefusjonsvilkar> XmlRefRefusjonsvilkar::GetRefusjonsvilkar() const {
    return refusjonsvilkar;
}

std::string XmlRefRefusjonsvilkarObject::GetName() const {
    return "Refusjonsvilkar";
}

void XmlRefRefusjonsvilkarObject::SetFraDato(const std::string &fraDato) {
    this->fraDato = fraDato;
}

bool XmlRefRefusjonsvilkarObject::Merge() {
    std::string id{};
    {
        auto ids = GetRefVilkar();
        if (ids.size() < 1) {
            std::cerr << "Error: Refusjonsvilkar: No RefVilkar\n";
            return false;
        }
        if (ids.size() > 1) {
            std::cerr << "Error: Refusjonsvilkar: Multiple RefVilkar\n";
            return false;
        }
        id = ids[0];
    }
    parent->AddRefusjonsvilkar({id, fraDato});
    return true;
}

std::shared_ptr<XMLObject> XmlRefusjonsvilkarHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                   const std::map<std::string, std::string> &attributes) {
    {
        std::shared_ptr<XmlRefRefusjonsvilkar> refRefusjonsvilkar = std::dynamic_pointer_cast<XmlRefRefusjonsvilkar>(
                parent);
        if (refRefusjonsvilkar) {
            return std::make_shared<XmlRefRefusjonsvilkarObject>(refRefusjonsvilkar);
        }
    }
    std::cerr << "Error: Unexpected Refusjonsvilkar\n";
    return {};
}

bool XmlRefusjonsvilkarHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *mergeable = dynamic_cast<XmlRefusjonsvilkarMergeable *>(&(*obj));
    if (mergeable == nullptr) {
        std::cerr << "Error: Not ending a Refusjonsvilkar object\n";
        return false;
    }
    return mergeable->Merge();
}

bool XmlFraDatoHandler::Merge(std::shared_ptr<XmlRefRefusjonsvilkarObject> parent, const std::string &content) {
    parent->SetFraDato(content);
    return true;
}