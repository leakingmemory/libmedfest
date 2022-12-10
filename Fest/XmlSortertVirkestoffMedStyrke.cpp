//
// Created by sigsegv on 12/10/22.
//

#include "XmlSortertVirkestoffMedStyrke.h"
#include <iostream>

std::string XmlSortertVirkestoffMedStyrkeObject::GetName() const {
    return "SortertVirkestoffMedStyrke";
}

bool XmlSortertVirkestoffMedStyrkeObject::Merge() {
    auto refs = GetRefVirkestoffMedStyrke();
    if (refs.size() == 0) {
        std::cerr << "Error: SortertVirkestoffMedStyrke: No references\n";
        return false;
    }
    if (refs.size() != 1) {
        std::cerr << "Error: SortertVirkestoffMedStyrke: More than one reference\n";
        return false;
    }
    parent->Add(*this);
    return true;
}

void XmlSortertVirkestoffMedStyrke::Add(XmlSortertVirkestoffMedStyrkeObject &ref) {
    refs.emplace_back(std::make_unique<XmlSortertVirkestoffMedStyrkeObject>(ref));
}

std::vector<std::string> XmlSortertVirkestoffMedStyrke::GetSortertVirkestoffMedStyrke() {
    XmlSortering::Sort(refs.begin(), refs.end());
    std::vector<std::string> plainRefs{};
    for (const auto &ref : refs) {
        auto refs = ref->GetRefVirkestoffMedStyrke();
        for (const auto &ref : refs) {
            plainRefs.emplace_back(ref);
        }
    }
    return plainRefs;
}

std::shared_ptr<XMLObject> XmlSortertVirkestoffMedStyrkeHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                              const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlSortertVirkestoffMedStyrke> typedParent = std::dynamic_pointer_cast<XmlSortertVirkestoffMedStyrke>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected SortertVirkestoffMedStyrke here\n";
        return {};
    }
    return std::make_shared<XmlSortertVirkestoffMedStyrkeObject>(typedParent);
}

bool XmlSortertVirkestoffMedStyrkeHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *typedObj = dynamic_cast<XmlSortertVirkestoffMedStyrkeObject *>(&(*obj));
    if (typedObj == nullptr) {
        std::cerr << "Error: Ending something else than SortertVirkestoffMedStyrke\n";
        return false;
    }
    return typedObj->Merge();
}