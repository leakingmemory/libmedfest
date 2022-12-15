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

bool XmlPakningsinfoObject::Mengde(const std::string &mengde) {
    this->mengde = mengde;
    return true;
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

std::shared_ptr<XmlPakningsinfo> XmlPakningsinfoObject::GetParent() const {
    return parent;
}

std::vector<Pakningsinfo> XmlPakningsinfo::GetPakningsinfo() const {
    std::vector<Pakningsinfo> pakningsinfo{};
    std::vector<std::shared_ptr<XmlPakningsinfoObject>> source{this->pakningsinfo};
    XmlSortering::Sort(source.begin(), source.end());
    for (auto &pi : source) {
        auto refMerkevarer = pi->GetRefLegemiddelMerkevare();
        if (refMerkevarer.size() <= 0) {
            std::cerr << "Error: Pakningsinfo should have RefLegemiddelMerkevare\n";
            continue;
        } else if (refMerkevarer.size() > 1) {
            std::cerr << "Error: Pakningsinfo does have more than one RefLegemiddelMerkevare\n";
            continue;
        }
        auto refMerkevare = refMerkevarer[0];
        pakningsinfo.emplace_back(refMerkevare, pi->pakningsstr, pi->enhetPakning, pi->GetPakningstype(), pi->mengde, pi->ddd, pi->pakningskomponent, pi->statistikkfaktor, pi->GetAntall());
    }
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
    std::shared_ptr<XmlPakningsinfoObject> p = std::dynamic_pointer_cast<XmlPakningsinfoObject>(obj);
    if (!p) {
        std::cerr << "Error: Did not end Pakningsinfo\n";
        return false;
    }
    p->GetParent()->pakningsinfo.push_back(p);
    return true;
}

bool XmlPakningsstrHandler::Merge(std::shared_ptr<XmlPakningsinfoObject> parent, const std::string &content) {
    parent->SetPakningsstr(content);
    return true;
}

bool XmlEnhetPakningHandler::Merge(std::shared_ptr<XmlValueWithCodeSet<XmlPakningsinfoObject>> obj) {
    obj->GetParent()->SetEnhetPakning({obj->GetValueWithCodeSet()});
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
