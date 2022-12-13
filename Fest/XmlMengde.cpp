//
// Created by sigsegv on 12/13/22.
//

#include "XmlMengde.h"
#include <iostream>
#include <boost/algorithm/string.hpp>

bool XmlMengde::Mengde(const std::string &) {
    std::cerr << "Error: Did not expect mengde with content\n";
    return false;
}

bool XmlMengde::Mengde(const ValueUnit &) {
    std::cerr << "Error: Did not expect mengde with V, U\n";
    return false;
}

std::string XmlMengdeObject::GetName() const {
    return "Mengde";
}

bool XmlMengdeObject::AppendCharacterData(const std::string &charData) {
    content.append(charData);
    return true;
}

bool XmlMengdeObject::Mengde(const ValueUnit &vu) {
    this->vu = true;
    return parent->Mengde(vu);
}

bool XmlMengdeObject::Merge() {
    boost::trim(content);
    if (!content.empty()) {
        if (vu) {
            std::cerr << "Error: Both content and V, U for Mengde\n";
            return false;
        }
        return parent->Mengde(content);
    } else if (!vu) {
        std::cerr << "Error: Empty Mengde\n";
        return false;
    }
    return true;
}

std::shared_ptr<XMLObject> XmlMengdeHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                          const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlMengde> typedParent = std::dynamic_pointer_cast<XmlMengde>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected Mengde\n";
        return {};
    }
    auto mengde = std::make_shared<XmlMengdeObject>(typedParent);
    auto v_i = attributes.find("V");
    auto u_i = attributes.find("U");
    auto f_v = v_i != attributes.end();
    auto f_u = u_i != attributes.end();
    if (f_v && f_u) {
        char *err;
        double value = strtod(v_i->second.c_str(), &err);
        if (err == nullptr || *err != '\0') {
            std::cerr << "Error: Mengde: Invalid value: " << v_i->second << "\n";
            return {};
        }
        if (!mengde->Mengde({value, u_i->second})) {
            return {};
        }
    }
    return mengde;
}

bool XmlMengdeHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *m = dynamic_cast<XmlMengdeObject *>(&(*obj));
    if (m == nullptr) {
        std::cerr << "Error: Not ending Mengde\n";
        return false;
    }
    return m->Merge();
}