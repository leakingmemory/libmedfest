//
// Created by sigsegv on 12/11/22.
//

#include "XmlLegemiddelpakning.h"

std::string XmlLegemiddelpakning::GetName() const {
    return "Legemiddelpakning";
}

void XmlLegemiddelpakning::SetVarenr(const std::string &varenr) {
    this->varenr = varenr;
}

void XmlLegemiddelpakning::SetOppbevaring(const Oppbevaring &oppbevaring) {
    this->oppbevaring = oppbevaring;
}

void XmlLegemiddelpakning::SetMarkedsforingsinfo(const Markedsforingsinfo &markedsforingsinfo) {
    this->markedsforingsinfo = markedsforingsinfo;
}

void XmlLegemiddelpakning::SetEan(const std::string &ean) {
    this->ean = ean;
}

bool XmlLegemiddelpakning::SetPakningByttegruppe(const PakningByttegruppe &pakningByttegruppe) {
    if (!this->pakningByttegruppe.GetRefByttegruppe().empty()) {
        std::cerr << "Error: Legemiddelpakning: Duplicate PakningByttegruppe\n";
        return false;
    }
    this->pakningByttegruppe = pakningByttegruppe;
    return true;
}

void XmlLegemiddelpakning::SetIkkeKonservering(bool ikkeKonservering) {
    this->ikkeKonservering = ikkeKonservering;
}

bool XmlLegemiddelpakning::Merge() {
    oppfLegemiddelpakning->SetLegemiddelpakning({{
            GetAtc(),
            GetNavnFormStyrke(),
            GetReseptgruppe(),
            GetLegemiddelformKort(),
            GetRefVilkar(),
            GetTypeSoknadSlv(),
            GetOpioidsoknad(),
            GetSvartTrekant()
        },
        GetPreparattype(),
        GetId(),
        varenr,
        oppbevaring,
        GetPakningsinfo(),
        markedsforingsinfo,
        ean,
        GetPrisVare(),
        GetRefusjon(),
        pakningByttegruppe,
        GetPreparatomtaleavsnitt(),
        ikkeKonservering
    });
    return true;
}

std::shared_ptr<XMLObject> XmlLegemiddelpakningHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                     const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlOppfLegemiddelpakning> oppf = std::dynamic_pointer_cast<XmlOppfLegemiddelpakning>(parent);
    if (!oppf) {
        std::cerr << "Error: Legemiddelpakning not expected here\n";
        return {};
    }
    return std::make_shared<XmlLegemiddelpakning>(oppf);
}

bool XmlLegemiddelpakningHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *oppf = dynamic_cast<XmlLegemiddelpakning*>(&(*obj));
    if (oppf == nullptr) {
        std::cerr << "Error: End of Legemiddelpakning, but not currently a L..\n";
        return false;
    }
    return oppf->Merge();
}

bool XmlVarenrHandler::Merge(std::shared_ptr <XmlLegemiddelpakning> parent, const std::string &content) {
    parent->SetVarenr(content);
    return true;
}

bool XmlOppbevaringHandler::Merge(std::shared_ptr<XmlType> obj) {
    obj->GetParent()->SetOppbevaring(obj->GetValueWithDistinguishedName());
    return true;
}

bool XmlEanHandler::Merge(std::shared_ptr<XmlLegemiddelpakning> parent, const std::string &content) {
    parent->SetEan(content);
    return true;
}

bool XmlIkkeKonserveringHandler::Merge(std::shared_ptr<XmlLegemiddelpakning> parent, const std::string &content) {
    if (content == "true") {
        parent->SetIkkeKonservering(true);
        return true;
    } else if (content == "false") {
        parent->SetIkkeKonservering(false);
        return true;
    }
    std::cerr << "Error: IkkeKonservering: Invalid value: " << content << "\n";
    return false;
}