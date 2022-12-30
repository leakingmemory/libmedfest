//
// Created by sigsegv on 12/27/22.
//

#include "XmlVarselSlv.h"
#include "KatVarselSlv.h"
#include <iostream>

std::string XmlVarselSlv::GetName() const {
    return "VarselSlv";
}

void XmlVarselSlv::SetOverskrift(const std::string &overskrift) {
    this->overskrift = overskrift;
}

void XmlVarselSlv::SetVarseltekst(const std::string &varseltekst) {
    this->varseltekst = varseltekst;
}

bool XmlVarselSlv::Merge() {
    parent->SetVarselSlv({GetType(), overskrift, varseltekst, GetVisningsregel(), GetFraDato(), GetLenke(), GetReferanseelement()});
    return true;
}

std::shared_ptr<XMLObject> XmlVarselSlvHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                             const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlOppfVarselSlv> typedParent = std::dynamic_pointer_cast<XmlOppfVarselSlv>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected VarselSlv\n";
        return {};
    }
    return std::make_shared<XmlVarselSlv>(typedParent);
}

bool XmlVarselSlvHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *v = dynamic_cast<XmlVarselSlv *>(&(*obj));
    if (v == nullptr) {
        std::cerr << "Error: Not ending VarselSlv\n";
        return false;
    }
    return v->Merge();
}

bool XmlOverskriftHandler::Merge(std::shared_ptr<XmlVarselSlv> parent, const std::string &content) {
    parent->SetOverskrift(content);
    return true;
}

bool XmlVarseltekstHandler::Merge(std::shared_ptr<XmlVarselSlv> parent, const std::string &content) {
    parent->SetVarseltekst(content);
    return true;
}
