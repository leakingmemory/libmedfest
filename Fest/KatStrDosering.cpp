//
// Created by sigsegv on 12/30/22.
//

#include "KatStrDosering.h"
#include "Fest.h"
#include <iostream>

std::string KatStrDosering::GetName() const {
    return "KatStrDosering";
}

void KatStrDosering::Merge(XmlOppfStrDosering &oppf) {
    fest->Add(oppf);
}

std::string XmlOppfStrDosering::GetName() const {
    return "OppfStrDosering";
}

bool XmlOppfStrDosering::Merge() {
    kat->Merge(*this);
    return true;
}

std::shared_ptr<XMLObject> KatStrDoseringHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                               const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<Fest> fest = std::dynamic_pointer_cast<Fest>(parent);
    if (!fest) {
        std::cerr << "Error: Unexpected KatStrDosering\n";
        return {};
    }
    return std::make_shared<KatStrDosering>(fest);
}

bool KatStrDoseringHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    return true;
}

std::shared_ptr<XMLObject> XmlOppfStrDoseringHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                   const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<KatStrDosering> kat = std::dynamic_pointer_cast<KatStrDosering>(parent);
    if (!kat) {
        std::cerr << "Error: Unexpected OppfStrDosering\n";
        return {};
    }
    return std::make_shared<XmlOppfStrDosering>(kat);
}

bool XmlOppfStrDoseringHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *s = dynamic_cast<XmlOppfStrDosering *>(&(*obj));
    if (s == nullptr) {
        std::cerr << "Error: Not ending OppfStrDosering\n";
        return false;
    }
    return s->Merge();
}