//
// Created by sigsegv on 12/11/22.
//

#include "XmlSortertVirkestoffUtenStyrke.h"
#include <iostream>

std::string XmlSortertVirkestoffUtenStyrkeObject::GetName() const {
    return "SortertVirkestoffUtenStyrke";
}

bool XmlSortertVirkestoffUtenStyrkeObject::Merge() {
    auto refs = GetRefVirkestoff();
    if (refs.size() == 0) {
        std::cerr << "Error: SortertVirkestoffUtenStyrke: No references\n";
        return false;
    }
    if (refs.size() != 1) {
        std::cerr << "Error: SortertVirkestoffUtenStyrke: More than one reference\n";
        return false;
    }
    parent->Add(*this);
    return true;
}

void XmlSortertVirkestoffUtenStyrke::Add(XmlSortertVirkestoffUtenStyrkeObject &ref) {
    refs.emplace_back(std::make_unique<XmlSortertVirkestoffUtenStyrkeObject>(ref));
}

std::vector<std::string> XmlSortertVirkestoffUtenStyrke::GetSortertVirkestoffUtenStyrke() {
    XmlSortering::Sort(refs.begin(), refs.end());
    std::vector<std::string> plainRefs{};
    for (const auto &ref : refs) {
        auto refs = ref->GetRefVirkestoff();
        for (const auto &ref : refs) {
            plainRefs.emplace_back(ref);
        }
    }
    return plainRefs;
}

std::shared_ptr<XMLObject> XmlSortertVirkestoffUtenStyrkeHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                              const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlSortertVirkestoffUtenStyrke> typedParent = std::dynamic_pointer_cast<XmlSortertVirkestoffUtenStyrke>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected SortertVirkestoffUtenStyrke here\n";
        return {};
    }
    return std::make_shared<XmlSortertVirkestoffUtenStyrkeObject>(typedParent);
}

bool XmlSortertVirkestoffUtenStyrkeHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *typedObj = dynamic_cast<XmlSortertVirkestoffUtenStyrkeObject *>(&(*obj));
    if (typedObj == nullptr) {
        std::cerr << "Error: Ending something else than SortertVirkestoffUtenStyrke\n";
        return false;
    }
    return typedObj->Merge();
}