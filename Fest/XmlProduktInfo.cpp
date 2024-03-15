//
// Created by sigsegv on 12/10/22.
//

#include "XmlProduktInfo.h"
#include "XmlLegemiddelMerkevare.h"

std::string XmlProduktInfo::GetName() const {
    return "ProduktInfo";
}

void XmlProduktInfo::SetProdusent(const std::string &produsent) {
    this->produsent = produsent;
}

void XmlProduktInfo::SetVarseltrekant(MaybeBoolean varseltrekant) {
    this->varseltrekant = varseltrekant;
}

void XmlProduktInfo::SetReferanseprodukt(const std::string &referanseprodukt) {
    this->referanseprodukt = referanseprodukt;
}

void XmlProduktInfo::SetVaksinestandard(const Vaksinestandard &vaksinestandard) {
    this->vaksinestandard = vaksinestandard;
}

bool XmlProduktInfo::Merge() {
    parent->SetProdusent(produsent);
    parent->SetVarseltrekant(varseltrekant);
    parent->SetReferanseprodukt(referanseprodukt);
    parent->SetVaksinestandard(vaksinestandard);
    return true;
}

std::shared_ptr<XMLObject> XmlProduktInfoHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                               const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlLegemiddelMerkevare> typedParent = std::dynamic_pointer_cast<XmlLegemiddelMerkevare>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected ProductInfo\n";
        return {};
    }
    return std::make_shared<XmlProduktInfo>(typedParent);
}

bool XmlProduktInfoHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *productInfo = dynamic_cast<XmlProduktInfo *>(&(*obj));
    if (productInfo == nullptr) {
        std::cerr << "Error: Ended not ProductInfo\n";
        return false;
    }
    return productInfo->Merge();
}

bool XmlProdusentHandler::Merge(std::shared_ptr<XmlProduktInfo> parent, const std::string &content) {
    parent->SetProdusent(content);
    return true;
}

bool XmlVarseltrekantHandler::Merge(std::shared_ptr<XmlProduktInfo> parent, const std::string &content) {
    if (content == "true") {
        parent->SetVarseltrekant(MaybeBoolean::MTRUE);
        return true;
    } else if (content == "false") {
        parent->SetVarseltrekant(MaybeBoolean::MFALSE);
        return true;
    }
    std::cerr << "Error: Invalid Varseltrekant value: " << content << "\n";
    return false;
}

bool XmlReferanseproduktHandler::Merge(std::shared_ptr<XmlProduktInfo> parent, const std::string &content) {
    parent->SetReferanseprodukt(content);
    return true;
}

bool XmlVaksinestandardHandler::Merge(std::shared_ptr<XmlValueWithCodeSet<XmlProduktInfo>> obj) {
    obj->GetParent()->SetVaksinestandard({obj->GetValueWithCodeSet()});
    return true;
}