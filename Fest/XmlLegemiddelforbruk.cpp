//
// Created by sigsegv on 12/30/22.
//

#include "XmlLegemiddelforbruk.h"
#include "XmlKortdose.h"
#include <iostream>

std::string XmlLegemiddelforbruk::GetName() const {
    return "Legemiddelforbruk";
}

void XmlLegemiddelforbruk::SetLopenr(int lopenr) {
    this->lopenr = lopenr;
}

void XmlLegemiddelforbruk::SetIterasjoner(int iterasjoner) {
    this->iterasjoner = iterasjoner;
}

bool XmlLegemiddelforbruk::Mengde(const std::string &smengde) {
    char *err;
    double mengde = strtod(smengde.c_str(), &err);
    if (err == nullptr || *err != '\0') {
        std::cerr << "Error: Legemiddelforbruk -> Mengde: Invalid: " << smengde << "\n";
        return false;
    }
    this->mengde = mengde;
    return true;
}

void XmlLegemiddelforbruk::SetPeriode(const std::string &periode) {
    this->periode = periode;
}

bool XmlLegemiddelforbruk::AddDosering(const Dosering &dosering) {
    this->dosering.emplace_back(dosering);
    return true;
}

bool XmlLegemiddelforbruk::Merge() {
    return parent->AddLegemiddelforbruk({lopenr, iterasjoner, mengde, periode, dosering});
}

std::shared_ptr<XMLObject> XmlLegemiddelforbrukHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                     const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlKortdoseObjectObject> typedParent = std::dynamic_pointer_cast<XmlKortdoseObjectObject>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected Legemiddelforbruk\n";
        return {};
    }
    return std::make_shared<XmlLegemiddelforbruk>(typedParent);
}

bool XmlLegemiddelforbrukHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *l = dynamic_cast<XmlLegemiddelforbruk *>(&(*obj));
    if (l == nullptr) {
        std::cerr << "Error: Not ending Legemiddelforbruk\n";
        return false;
    }
    return l->Merge();
}

bool XmlLopenrHandler::Merge(std::shared_ptr<XmlLegemiddelforbruk> parent, const std::string &content) {
    char *err;
    long lvalue = strtol(content.c_str(), &err, 10);
    if (err == nullptr || *err != '\0') {
        std::cerr << "Error: Lopenr: Invalid value: " << content << "\n";
        return false;
    }
    int value = (int) lvalue;
    if (((long) value) != lvalue) {
        std::cerr << "Error: Lopenr: Invalid value: " << content << " (overflow)\n";
        return false;
    }
    parent->SetLopenr(value);
    return true;
}

bool XmlPeriodeHandler::Merge(std::shared_ptr<XmlLegemiddelforbruk> parent, const std::string &content) {
    parent->SetPeriode(content);
    return true;
}

bool XmlIterasjonerHandler::Merge(std::shared_ptr<XmlLegemiddelforbruk> parent, const std::string &content) {
    char *err;
    long lvalue = strtol(content.c_str(), &err, 10);
    if (err == nullptr || *err != '\0') {
        std::cerr << "Error: Legemiddelforbruk -> Mengde: Invalid: " << content << "\n";
        return false;
    }
    int value = (int) lvalue;
    if (((long) value) != lvalue) {
        std::cerr << "Error: Legemiddelforbruk -> Mengde: Invalid: " << content << " (overflow)\n";
        return false;
    }
    parent->SetIterasjoner(value);
    return true;
}