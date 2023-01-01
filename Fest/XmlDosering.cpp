//
// Created by sigsegv on 12/31/22.
//

#include "XmlDosering.h"
#include "XmlLegemiddelforbruk.h"
#include <iostream>

bool XmlDosering::AddDoseFastTidspunkt(const DoseFastTidspunkt &doseFastTidspunkt) {
    this->doseFastTidspunkt.emplace_back(doseFastTidspunkt);
    return true;
}

std::string XmlDosering::GetName() const {
    return "Dosering";
}

bool XmlDosering::Merge() {
    return parent->AddDosering({doseFastTidspunkt});
}

std::shared_ptr<XMLObject> XmlDoseringHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                            const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlLegemiddelforbruk> typedParent = std::dynamic_pointer_cast<XmlLegemiddelforbruk>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected Dosering\n";
        return {};
    }
    return std::make_shared<XmlDosering>(typedParent);
}

bool XmlDoseringHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *d = dynamic_cast<XmlDosering *>(&(*obj));
    if (d == nullptr) {
        std::cerr << "Error: Not ending Dosering\n";
        return false;
    }
    return d->Merge();
}