//
// Created by sigsegv on 12/9/22.
//

#include "FestIdObject.h"
#include <iostream>

std::string FestIdObject::GetId() const {
    return id;
}

void FestIdObject::SetId(const std::string &id) {
    this->id = id;
}

std::string XmlIdObject::GetName() {
    return "Id";
}

bool XmlIdObject::AppendCharacterData(const std::string &charData) {
    id.append(charData);
    return true;
}

void XmlIdObject::Merge() {
    festIdObject->SetId(id);
}

std::shared_ptr<XMLObject>
FestIdHandler::StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes) {
    std::shared_ptr<FestIdObject> idObject = std::dynamic_pointer_cast<FestIdObject>(parent);
    if (!idObject) {
        std::cerr << "Error: Id parent is not an Fest Id-able object\n";
        return {};
    }
    return std::make_shared<XmlIdObject>(idObject);
}

bool FestIdHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    XmlIdObject *idObject = dynamic_cast<XmlIdObject*>(&(*obj));
    if (idObject == nullptr) {
        std::cerr << "Expected Id object on end of Id element\n";
        return false;
    }
    idObject->Merge();
    return true;
}