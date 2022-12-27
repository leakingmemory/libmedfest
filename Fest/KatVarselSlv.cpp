//
// Created by sigsegv on 12/26/22.
//

#include "KatVarselSlv.h"
#include <iostream>

std::string KatVarselSlv::GetName() const {
    return "KatVarselSlv";
}

void KatVarselSlv::Merge(XmlOppfVarselSlv &oppf) {
    fest->Add(oppf);
}

std::string XmlOppfVarselSlv::GetName() const {
    return "OppfVarselSlv";
}

void XmlOppfVarselSlv::SetVarselSlv(const VarselSlv &varselSlv) {
    this->varselSlv = varselSlv;
}

VarselSlv XmlOppfVarselSlv::GetVarselSlv() const {
    return varselSlv;
}

void XmlOppfVarselSlv::Merge() {
    kat->Merge(*this);
}

std::shared_ptr<XMLObject> KatVarselSlvHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                             const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<Fest> fest = std::dynamic_pointer_cast<Fest>(parent);
    if (!fest) {
        std::cerr << "Error: Unexpected KatVarselSlv\n";
        return {};
    }
    return std::make_shared<KatVarselSlv>(fest);
}

bool KatVarselSlvHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    return true;
}

std::shared_ptr<XMLObject> XmlOppfVarselSlvHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                 const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<KatVarselSlv> kat = std::dynamic_pointer_cast<KatVarselSlv>(parent);
    if (!kat) {
        std::cerr << "Error: Unexpected OppfVarselSlv\n";
        return {};
    }
    return std::make_shared<XmlOppfVarselSlv>(kat);
}

bool XmlOppfVarselSlvHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *v = dynamic_cast<XmlOppfVarselSlv *>(&(*obj));
    if (v == nullptr) {
        std::cerr << "Error: Not ending OppfVarselSlv\n";
        return false;
    }
    v->Merge();
    return true;
}
