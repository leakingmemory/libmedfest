//
// Created by sigsegv on 12/14/22.
//

#include "XmlPakningByttegruppe.h"

std::string XmlPakningByttegruppe::GetName() const {
    return "PakningByttegruppe";
}

void XmlPakningByttegruppe::SetRefByttegruppe(const std::string &refByttegruppe) {
    this->refByttegruppe = refByttegruppe;
}

bool XmlPakningByttegruppe::Merge() {
    parent->SetPakningByttegruppe({refByttegruppe, GetGyldigFraDato()});
    return true;
}

std::shared_ptr<XMLObject> XmlPakningByttegruppeHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                      const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlLegemiddelpakning> typedParent = std::dynamic_pointer_cast<XmlLegemiddelpakning>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected PakningByttegruppe\n";
        return {};
    }
    return std::make_shared<XmlPakningByttegruppe>(typedParent);
}

bool XmlPakningByttegruppeHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *pb = dynamic_cast<XmlPakningByttegruppe *>(&(*obj));
    if (pb == nullptr) {
        std::cerr << "Error: Did not end PakningByttegruppe\n";
        return false;
    }
    return pb->Merge();
}

bool XmlRefByttegruppeHandler::Merge(std::shared_ptr<XmlPakningByttegruppe> parent, const std::string &content) {
    parent->SetRefByttegruppe(content);
    return true;
}
