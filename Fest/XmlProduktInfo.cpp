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

bool XmlProduktInfo::Merge() {
    parent->SetProdusent(produsent);
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
