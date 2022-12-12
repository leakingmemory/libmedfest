//
// Created by sigsegv on 12/12/22.
//

#include "XmlPakningsinfo.h"
#include <iostream>

std::string XmlPakningsinfoObject::GetName() const {
    return "Pakningsinfo";
}

void XmlPakningsinfoObject::SetPakningsstr(const std::string &pakningsstr) {
    this->pakningsstr = pakningsstr;
}

void XmlPakningsinfoObject::SetEnhetPakning(const EnhetPakning &enhetPakning) {
    this->enhetPakning = enhetPakning;
}

void XmlPakningsinfoObject::SetPakningstype(const Pakningstype &pakningstype) {
    this->pakningstype = pakningstype;
}

void XmlPakningsinfoObject::SetMengde(const std::string &mengde) {
    this->mengde = mengde;
}

void XmlPakningsinfoObject::SetDDD(const DDD &ddd) {
    this->ddd = ddd;
}

void XmlPakningsinfoObject::AddPakningskomponent(const Pakningskomponent &pakningskomponent) {
    this->pakningskomponent.push_back(pakningskomponent);
}

void XmlPakningsinfoObject::SetStatistikkfaktor(double statistikkfaktor) {
    this->statistikkfaktor = statistikkfaktor;
}

void XmlPakningsinfoObject::SetAntall(int antall) {
    this->antall = antall;
}

bool XmlPakningsinfoObject::Merge() {
    if (parent->hasInfo) {
        std::cerr << "Error: Duplicate Pakningsinfo\n";
        return false;
    }
    auto refMerkevarer = GetRefLegemiddelMerkevare();
    if (refMerkevarer.size() <= 0) {
        std::cerr << "Error: Pakningsinfo should have RefLegemiddelMerkevare\n";
        return false;
    } else if (refMerkevarer.size() > 1) {
        std::cerr << "Error: Pakningsinfo does have more than one RefLegemiddelMerkevare\n";
        return false;
    }
    auto refMerkevare = refMerkevarer[0];
    parent->hasInfo = true;
    parent->pakningsinfo = {refMerkevare, pakningsstr, enhetPakning, pakningstype, mengde, ddd, pakningskomponent, statistikkfaktor, antall};
    return true;
}

Pakningsinfo XmlPakningsinfo::GetPakningsinfo() const {
    return pakningsinfo;
}

std::shared_ptr<XMLObject> XmlPakningsinfoHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlPakningsinfo> typedParent = std::dynamic_pointer_cast<XmlPakningsinfo>(parent);
    if (!typedParent) {
        std::cerr << "Error: Pakningsinfo was not expected here\n";
        return {};
    }
    return std::make_shared<XmlPakningsinfoObject>(typedParent);
}

bool XmlPakningsinfoHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *p = dynamic_cast<XmlPakningsinfoObject *>(&(*obj));
    if (p == nullptr) {
        std::cerr << "Error: Did not end Pakningsinfo\n";
        return false;
    }
    return p->Merge();
}

bool XmlPakningsstrHandler::Merge(std::shared_ptr<XmlPakningsinfoObject> parent, const std::string &content) {
    parent->SetPakningsstr(content);
    return true;
}

bool XmlEnhetPakningHandler::Merge(std::shared_ptr<XmlValueWithCodeSet<XmlPakningsinfoObject>> obj) {
    obj->GetParent()->SetEnhetPakning({obj->GetValueWithCodeSet()});
    return true;
}

bool XmlPakningstypeHandler::Merge(std::shared_ptr<XmlValueWithCodeSet<XmlPakningsinfoObject>> obj) {
    obj->GetParent()->SetPakningstype({obj->GetValueWithCodeSet()});
    return true;
}

bool XmlMengdeHandler::Merge(std::shared_ptr<XmlPakningsinfoObject> parent, const std::string &content) {
    parent->SetMengde(content);
    return true;
}

bool XmlDDDHandler::Merge(std::shared_ptr<XmlType> obj) {
    obj->GetParent()->SetDDD({obj->GetValueUnit()});
    return true;
}

bool XmlStatistikkfaktorHandler::Merge(std::shared_ptr<XmlPakningsinfoObject> parent, const std::string &content) {
    char *err;
    double val = strtod(content.c_str(), &err);
    if (err == nullptr || *err != '\0') {
        std::cerr << "Error: Statistikkfaktor: Invalid value (double): " << content << "\n";
        return false;
    }
    parent->SetStatistikkfaktor(val);
    return true;
}

bool XmlAntallHandler::Merge(std::shared_ptr<XmlPakningsinfoObject> parent, const std::string &content) {
    char *err;
    double lval = strtol(content.c_str(), &err, 10);
    if (err == nullptr || *err != '\0') {
        std::cerr << "Error: Antall: Invalid value (int): " << content << "\n";
        return false;
    }
    int val = (int) lval;
    if (((long) val) != lval) {
        std::cerr << "Error: Antall: Invalid value (int): " << content << " (overflow)\n";
        return false;
    }
    parent->SetAntall(val);
    return true;
}